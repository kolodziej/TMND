#include "tmnd/message.hpp"

namespace tmnd {

Message::Message(MessageType type, std::string data) :
    version_(default_version),
    type_(type),
    data_(data)
{}

Message::Message(uint8_t version, MessageType type, std::string data) :
    version_(version & 0b00000111),
    type_(type),
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
  return data_.size();
}

std::string Message::data() const
{
  return data_;
}

void Message::setData(std::string data)
{
  data_ = data;
}

}
