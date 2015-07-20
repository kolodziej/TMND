#ifndef TMND_ARCHIVE_HPP
#define TMND_ARCHIVE_HPP
#include <string>
#include <list>
#include <istream>
#include <ostream>

#include "message.hpp"

namespace tmnd {

class Archive
{
 public:
  Archive() = default;
  Archive(std::string);
  Archive(std::istream&);
  
  void addMessage(const Message& msg);
  std::list<Message> getMessages() const;

  void save(std::ostream&);
  
 private:
  void loadFromStream_(std::istream&);

  std::list<Message> messages_;
};

}

#endif
