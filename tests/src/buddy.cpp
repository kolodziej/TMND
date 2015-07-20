#include "gtest/gtest.h"

#include <string>
#include "tmnd/buddy.hpp"

TEST(Buddy, Construct)
{
  std::string nick = "Kacper Kołodziej",
              hostname = "rlia3mv6aelrwvtm";

  tmnd::Buddy buddy(nick, hostname);
  ASSERT_EQ(nick, buddy.nick());
  ASSERT_EQ(hostname, buddy.hostname());
}
