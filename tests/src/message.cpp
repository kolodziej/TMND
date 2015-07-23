#include "gtest/gtest.h"

#include <string>

#include "tmnd/message.hpp"

class MessageTest : public ::testing::Test
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

  std::string json_code;
  nlohmann::json json_object;
};

TEST_F(MessageTest, Construct1)
{
  tmnd::Message msg(tmnd::MessageType::Hello);
  ASSERT_EQ(msg.version(), tmnd::Message::default_version);
  ASSERT_EQ(msg.type(), tmnd::MessageType::Hello);
  ASSERT_EQ(msg.size(), static_cast<uint8_t>(0));
  ASSERT_TRUE(msg.data().empty());
}

TEST_F(MessageTest, Construct2)
{
  std::string body = "Example Message";
  tmnd::Message msg(tmnd::MessageType::Hello, body);
  ASSERT_EQ(msg.size(), body.size());
  ASSERT_EQ(msg.data(), body);
}

TEST_F(MessageTest, Construct3)
{
  tmnd::Message msg(tmnd::Message::default_version, json_object);
  ASSERT_EQ(msg.data(), json_code);
}

TEST_F(MessageTest, SetJsonObject)
{
  tmnd::Message msg(tmnd::MessageType::Text);
  msg.setJsonObject(json_object);
  ASSERT_EQ(msg.data(), json_code);
}

TEST_F(MessageTest, GetJsonObject)
{
  tmnd::Message msg(tmnd::MessageType::Text);
  msg.setData(json_code);
  ASSERT_EQ(msg.jsonObject(), json_object);
}
