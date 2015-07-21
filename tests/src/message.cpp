#include "gtest/gtest.h"

#include <string>

#include "tmnd/message.hpp"
#include "tmnd/message_json.hpp"

TEST(MessageTest, Construct1)
{
  tmnd::Message msg(tmnd::MessageType::Hello);
  ASSERT_EQ(msg.version(), tmnd::Message::default_version);
  ASSERT_EQ(msg.type(), tmnd::MessageType::Hello);
  ASSERT_EQ(msg.size(), static_cast<uint8_t>(0));
  ASSERT_TRUE(msg.data().empty());
}

TEST(MessageTest, Construct2)
{
  std::string body = "Example Message";
  tmnd::Message msg(tmnd::MessageType::Hello, body);
  ASSERT_EQ(msg.size(), body.size());
  ASSERT_EQ(msg.data(), body);
}

class MessageJsonTest : public ::testing::Test
{
 protected:
  virtual void SetUp()
  {
    json_object = {
      {"date", "2015-07-21 13:34"},
      {"message", "Sample message"}
    };
    json_code = json_object.dump();
  }

  tmnd::MessageJson msg;
  std::string json_code;
  nlohmann::json json_object;
};

TEST_F(MessageJsonTest, SetJsonObject)
{
  msg.setJsonObject(json_object);
  ASSERT_EQ(msg.data(), json_code);
}

TEST_F(MessageJsonTest, GetJsonObject)
{
  msg.setData(json_code);
  ASSERT_EQ(msg.jsonObject(), json_object);
}
