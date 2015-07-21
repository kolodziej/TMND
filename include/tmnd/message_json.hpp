#ifndef TMND_MESSAGE_JSON_HPP
#define TMND_MESSAGE_JSON_HPP
#include "message.hpp"

#include "json.hpp"

using json = nlohmann::json;

namespace tmnd {

class MessageJson : public Message
{
 public:
  MessageJson(uint8_t version = default_version);
  
  json jsonObject() const;
  void setJsonObject(json);

 private:
  json jsondata_;
};

}

#endif
