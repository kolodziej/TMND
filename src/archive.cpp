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
  
}

void Archive::loadFromStream_(std::istream& stream)
{
  using json = nlohmann::json;
  json data;
  data << stream;

  for (json::iterator it = data.begin(); it != data.end(); ++it)
  {
    //Message msg;
  }
}

}
