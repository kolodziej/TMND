#include "gtest/gtest.h"

#include <fstream>
#include <string>
#include <sstream>
#include "json.hpp"

#include "tmnd/archive.hpp"

using json = nlohmann::json;

class ArchiveTest : public ::testing::Test
{
 protected:
  virtual void SetUp()
  {
    msg1_data = json::parse("{\"text\": \"Sample message\", \"date\": \"2015-07-21\"}");
    data.push_back({
        {"version", 1},
        {"type", static_cast<uint8_t>(tmnd::MessageType::Text)},
        {"data", msg1_data.dump()}
    });
    data.push_back({
        {"version", 1},
        {"type", static_cast<uint8_t>(tmnd::MessageType::Hello)},
        {"data", std::string()}
    });
  }

  tmnd::Archive arch;
  json data;
  json msg1_data;
};

TEST_F(ArchiveTest, ConstructStream)
{
  std::stringstream stream;
  stream.str(data.dump());

  arch = tmnd::Archive(stream);
  int i = 0;
  for (tmnd::Message j : arch.messages())
  {
    ASSERT_EQ(j.version(), data[i]["version"]);
    ASSERT_EQ(j.type(), static_cast<tmnd::MessageType>(static_cast<uint8_t>(data[i]["type"])));
    ASSERT_EQ(j.data(), data[i]["data"]);
    ++i;
  }
}

TEST_F(ArchiveTest, Save)
{
  std::stringstream input, output;
  input.str(data.dump());
  arch = tmnd::Archive(input);
  arch.save(output);
  ASSERT_EQ(output.str(), data.dump());
}
