#ifndef TMND_FILTER_MESSAGE_HPP
#define TMND_FILTER_MESSAGE_HPP
#include <list>

namespace tmnd {

class Message;

class FilterMessage
{
 public:
  virtual void filter(std::list<Message>&) = 0;
};

}

#endif
