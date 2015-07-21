#include "tmnd/message_json.hpp"

#include "tmnd/message_type.hpp"

namespace tmnd {

MessageJson::MessageJson(uint8_t version) :
    Message(version, MessageType::Text)
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
