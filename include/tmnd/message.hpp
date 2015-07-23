#ifndef TMND_MESSAGE_HPP
#define TMND_MESSAGE_HPP
#include <cstdint>
#include <string>

#include "message_type.hpp"
#include "json.hpp"

using json = nlohmann::json;

namespace tmnd {

class Message
{
 public:
  static const uint8_t default_version;

  Message(MessageType type, std::string data = std::string());
  Message(uint8_t version, MessageType type, std::string data = std::string());
  Message(uint8_t version, json data);
  Message(json data);

  uint8_t version() const;
  MessageType type() const;
  uint32_t size() const;

  std::string data() const;
  void setData(std::string data);
  json jsonObject() const;
  void setJsonObject(json data);

 private:
  uint8_t version_;
  MessageType type_;
  std::string data_;
};

}

#endif
