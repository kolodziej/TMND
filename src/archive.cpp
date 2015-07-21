#include "tmnd/archive.hpp"

#include <fstream>

#include "json.hpp"

namespace tmnd {

Archive::Archive(std::string filename)
{
  std::fstream file(filename, std::ios::in);
  loadFromStream_(file);
}

Archive::Archive(std::istream& stream)
{
  loadFromStream_(stream);
}

void Archive::addMessage(const Message& msg)
{
  messages_.push_back(msg);
}

std::list<Message> Archive::messages() const
{
  return messages_;
}

void Archive::save(std::ostream& stream)
{
  using json = nlohmann::json;
  json arr = json::array();
  for (Message msg : messages())
  {
    json obj;
    obj["version"] = msg.version();
    obj["type"] = static_cast<uint8_t>(msg.type());
    obj["data"] = msg.data();
    arr.push_back(obj);
  }
  stream << arr;
}

void Archive::loadFromStream_(std::istream& stream)
{
  using json = nlohmann::json;
  json data;
  data << stream;

  for (json obj : data)
  {
    Message msg(obj["version"], static_cast<MessageType>(static_cast<uint8_t>(obj["type"])), obj["data"]);
    messages_.push_back(msg);
  }
}

}
