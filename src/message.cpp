#include "tmnd/message.hpp"

namespace tmnd {

Message::Message(uint8_t version, MessageType type, std::string data) :
    version_(version & 0b00000111),
    type_(type),
    size_(data.size()),
    time_(0),
    data_(data)
{}

uint8_t Message::version() const
{
  return version_;
}

MessageType Message::type() const
{
  return type_;
}

uint32_t Message::size() const
{
  return size_;
}

uint32_t Message::time() const
{
  return time_;
}

std::string Message::data() const
{
  return data_;
}

}
