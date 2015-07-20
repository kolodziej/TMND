#include "gtest/gtest.h"

#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <utility>
#include "tmnd/buddy.hpp"
#include "tmnd/buddy_list.hpp"

TEST(Buddy, Construct)
{
  std::string nick = "Kacper Kołodziej",
              hostname = "rlia3mv6aelrwvtm";

  tmnd::Buddy buddy(nick, hostname);
  ASSERT_EQ(nick, buddy.nick());
  ASSERT_EQ(hostname, buddy.hostname());
}

TEST(BuddyList, ConstructFromStream)
{
  using ps = std::pair<std::string, std::string>;
  std::stringstream stream;
  std::vector<ps> buddies_v = {{
      { "rlia3mv6aelrwvtm", "Kacper Kołodziej" },
      { "abcdefghaelrwvtm", "John Watson" },
      { "123344523dsfgmls", "Sherlock Holmes" }
  }};

  for (ps s : buddies_v)
    stream << s.first << " " << s.second << "\n";

  tmnd::BuddyList list(stream);
  std::list<tmnd::Buddy> buddies = list.getBuddies();
  int i = 0;
  for (tmnd::Buddy b : buddies)
  {
    ASSERT_EQ(buddies_v[i].first, b.hostname());
    ASSERT_EQ(buddies_v[i].second, b.nick());
    ++i;
  }
}
