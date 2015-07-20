#include "gtest/gtest.h"

#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <utility>
#include <stdexcept>

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

class BuddyListTest : public ::testing::Test
{
 public:
  using ps = std::pair<std::string, std::string>;

 protected:
  virtual void SetUp()
  {
    buddies_v = {{
      { "rlia3mv6aelrwvtm", "Kacper Kołodziej" },
      { "abcdefghaelrwvtm", "John Watson" },
      { "123344523dsfgmls", "Sherlock Holmes" },
      { "dfgeq34rfsdg34ra", "Tommy Emmanuel" }
    }};
    
    for (ps s : buddies_v)
      stream << s.first << " " << s.second << "\n";
  }

  std::stringstream stream;
  std::vector<ps> buddies_v;
};

TEST_F(BuddyListTest, ConstructFromStream)
{
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

TEST_F(BuddyListTest, ConstructFromFile)
{
  std::string filename = "tmp~";
  std::fstream file(filename, std::ios::out);
  file << stream;
  
  tmnd::BuddyList list(filename);
  std::list<tmnd::Buddy> buddies = list.getBuddies();
  int i = 0;
  for (tmnd::Buddy b : buddies)
  {
    ASSERT_EQ(buddies_v[i].first, b.hostname());
    ASSERT_EQ(buddies_v[i].second, b.nick());
    ++i;
  }
}

TEST_F(BuddyListTest, AddBuddy)
{
  tmnd::BuddyList list;
  for (ps s : buddies_v)
  {
    list.addBuddy(tmnd::Buddy(s.second, s.first));
  }
  std::list<tmnd::Buddy> buddies = list.getBuddies();
  int i = 0;
  for (tmnd::Buddy b : buddies)
  {
    ASSERT_EQ(buddies_v[i].first, b.hostname());
    ASSERT_EQ(buddies_v[i].second, b.nick());
    ++i;
  }
}

TEST_F(BuddyListTest, RemoveBuddy1)
{
  tmnd::BuddyList list(stream);
  for (ps s : buddies_v)
  {
    ASSERT_NO_THROW(list.removeBuddy(tmnd::Buddy(s.second, s.first)));
  }

  ASSERT_TRUE(list.getBuddies().empty());
}

TEST_F(BuddyListTest, RemoveBuddy2)
{
  tmnd::BuddyList list(stream);
  for (ps s : buddies_v)
  {
    ASSERT_NO_THROW(list.removeBuddy(tmnd::Buddy("no name", s.first)));
  }

  ASSERT_TRUE(list.getBuddies().empty());
}

TEST_F(BuddyListTest, RemoveNotExisting)
{
  tmnd::BuddyList list(stream);
  ASSERT_THROW(list.removeBuddy(tmnd::Buddy("no name", "123123123123123")), std::runtime_error);
}
