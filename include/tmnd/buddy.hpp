#ifndef TMND_BUDDY_HPP
#define TMND_BUDDY_HPP
#include <string>

namespace tmnd {

class Buddy
{
 public:
  Buddy(std::string nick, std::string hostname);
  
  std::string nick() const;
  std::string hostname() const;

  bool operator==(const Buddy& rhs) const;

 private:
  std::string nick_;
  std::string hostname_;
};

}

#endif
