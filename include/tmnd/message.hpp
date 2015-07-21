#ifndef TMND_MESSAGE_HPP
#define TMND_MESSAGE_HPP
#include <cstdint>
#include <boost/asio.hpp>

#include "message_type.hpp"

namespace tmnd {

class Message
{
 public:
  Message(MessageType type, std::string data = std::string());
  Message(uint8_t version, MessageType type, std::string data = std::string());

  uint8_t version() const;
  MessageType type() const;
  uint32_t size() const;
  std::string data() const;
  void setData(std::string);

 private:
  uint8_t version_;
  MessageType type_;
  std::string data_;
};

}

#endif
