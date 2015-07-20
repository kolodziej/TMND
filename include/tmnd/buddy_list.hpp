#ifndef TMND_BUDDY_LIST_HPP
#define TMND_BUDDY_LIST_HPP
#include <string>
#include <ostream>
#include <list>

namespace tmnd {

class Buddy;

class BuddyList
{
 public:
  BuddyList(std::string filename);
  BuddyList(std::istream& stream);
  
  void addBuddy(Buddy);
  void removeBuddy(Buddy);
  std::list<Buddy> getBuddies() const;

  void save(std::ostream&);

 private:
  void loadFromStream_(std::istream&);

  std::string filename_;
  std::list<Buddy> buddies_;
};

}

#endif
