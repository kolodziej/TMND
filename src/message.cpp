#include "tmnd/message.hpp"

namespace tmnd {

const uint8_t Message::default_version = 1;

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

Message::Message(uint8_t version, json data) :
    version_(version & 0b00000111),
    type_(MessageType::Text),
    data_(data.dump())
{}

Message::Message(json data) : 
    version_(default_version),
    type_(MessageType::Text),
    data_(data.dump())
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

json Message::jsonObject() const
{
  return json::parse(data());
}

void Message::setJsonObject(json obj) 
{
  setData(obj.dump());
}

}
