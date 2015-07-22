#include "tmnd/message_json.hpp"

#include "tmnd/message_type.hpp"

namespace tmnd {

MessageJson::MessageJson() :
    Message(MessageType::Text)
{}

MessageJson::MessageJson(json data, uint8_t version) :
    Message(version, MessageType::Text)
{
  setJsonObject(data);
}

MessageJson::MessageJson(std::string data, uint8_t version) :
    Message(version, MessageType::Text, data)
{}

json MessageJson::jsonObject() const
{
  return json::parse(data());
}

void MessageJson::setJsonObject(json obj) 
{
  setData(obj.dump());
}

}
