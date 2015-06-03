#ifndef TMND_SOCKS5_ADDRESS_TYPE_HPP
#define TMND_SOCKS5_ADDRESS_TYPE_HPP

namespace tmnd { namespace socks5 {

enum class address_type : uint8_t
{
  ipv4 = 0x01,
  domainname = 0x03,
  ipv6 = 0x04
};

} }

#endif
