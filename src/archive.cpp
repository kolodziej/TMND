#include "tmnd/archive.hpp"

#include <fstream>

namespace tmnd {

Archive::Archive(std::string filename)
{
  std::fstream file(filename, std::ios::in);
  loadFromStream_(file);
}

Archive::Archive(std::istream& stream)
{
  loadFromStream_(stream);
}

void Archive::addMessage(const Message& msg)
{
  messages_.push_back(msg);
}

std::list<Message> Archive::getMessages() const
{
  return messages_;
}

void Archive::save(std::ostream& stream)
{
  
}

void Archive::loadFromStream_(std::istream& stream)
{
}

}
