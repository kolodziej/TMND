#ifndef TMND_PROFILE_HPP
#define TMND_PROFILE_HPP
#include <string>

namespace tmnd {

class Archive;
class BuddyList;

class Profile
{
 public:
  Profile(std::string filename);
 
  std::string nick() const;
  std::string hostname() const;
  Archive& archive();
  BuddyList& buddyList();

 private:
  std::string nick_;
  std::string hostname_;
};

}

#endif
