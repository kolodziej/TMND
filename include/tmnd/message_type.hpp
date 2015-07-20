#ifndef TMND_MESSAGE_TYPE_HPP
#define TMND_MESSAGE_TYPE_HPP
#include <cstdint>

namespace tmnd {

enum class MessageType : uint8_t
{
  Hello = 0x00,
  Ping = 0x01,
  Pong = 0x02,
  Invite = 0x03,
  Accept = 0x04,
  Reject = 0x05,
  Text = 0x06,
  FileStart = 0x07,
  FileData = 0x08,
  FileEnd = 0x09,
  Contact = 0x0A,
  NewHostname = 0x0B,
  Bye = 0xFF
};

}

#endif
