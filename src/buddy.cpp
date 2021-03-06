#include "tmnd/buddy.hpp"

namespace tmnd {

Buddy::Buddy(std::string nick, std::string hostname) :
    nick_(nick),
    hostname_(hostname)
{}

std::string Buddy::nick() const
{
  return nick_;
}

std::string Buddy::hostname() const
{
  return hostname_;
}

bool Buddy::operator==(const Buddy& rhs) const
{
  return hostname_ == rhs.hostname();
}

}
