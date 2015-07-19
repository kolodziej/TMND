#ifndef TMND_MESSAGE_HPP
#define TMND_MESSAGE_HPP
#include <cstdint>
#include <boost/asio.hpp>

#include "message_type.hpp"

namespace tmnd {

class Message
{
 public:
  Message(uint8_t version, MessageType type, std::string data = std::string());

  uint16_t version() const;
  MessageType type() const;
  uint32_t size() const;
  uint32_t time() const;

  std::string data() const;

  boost::asio::mutable_buffer buffer();

 private:
  uint16_t header_;
  uint32_t size_;
  uint32_t time_;
  std::string data_;
};

}

#endif
