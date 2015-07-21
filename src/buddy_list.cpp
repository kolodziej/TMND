#include "tmnd/buddy_list.hpp"

#include <algorithm>
#include <fstream>
#include <stdexcept>

#include "tmnd/buddy.hpp"

namespace tmnd {

BuddyList::BuddyList(std::string filename) :
    filename_(filename)
{
  std::fstream file(filename, std::ios::in);
  loadFromStream_(file);
}

BuddyList::BuddyList(std::istream& stream)
{
  loadFromStream_(stream);
}

void BuddyList::addBuddy(Buddy buddy)
{
  buddies_.push_back(buddy);
}

void BuddyList::removeBuddy(Buddy buddy)
{
  std::list<Buddy>::iterator it =
      std::find(buddies_.begin(), buddies_.end(), buddy);

  if (it == buddies_.end())
  {
    throw std::runtime_error("No such buddy on list!");
  }
  buddies_.erase(it);
}

std::list<Buddy> BuddyList::buddies() const
{
  return buddies_;
}

void BuddyList::save(std::ostream& stream)
{
  for (Buddy buddy : buddies_)
  {
    stream << buddy.hostname() << " " << buddy.nick() << "\n";
  }
}

void BuddyList::loadFromStream_(std::istream& stream)
{
  std::string line;
  while (std::getline(stream, line))
  {
    std::string hostname = line.substr(0,16);
    std::string nick = line.substr(17);
    Buddy buddy(nick, hostname);
    buddies_.push_back(buddy);
  }
}

}
