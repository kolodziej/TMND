#ifndef TMND_SOCKS5_COMMAND_HPP
#define TMND_SOCKS5_COMMAND_HPP

namespace tmnd { namespace socks5 {

enum class command : uint8_t
{
  connect = 0x01,
  bind = 0x02,
  udp_associate = 0x03
};

} }

#endif
