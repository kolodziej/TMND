#ifndef TMND_ARCHIVE_HPP
#define TMND_ARCHIVE_HPP
#include <list>

namespace tmnd {

class Message;

class Archive
{
 public:
  Archive();
  Archive(std::string);
  
  void addMessage(const Message& msg);
  std::list<Message> getMessages() const;
  void loadArchive(std::string filename);
  
 private:
  std::list<Message> messages_;
};

}

#endif
