#ifndef TMND_SOCKS5_HEADER_HPP
#define TMND_SOCKS5_HEADER_HPP
#include <cstdint>

namespace tmnd { namespace socks5 {

class Header
{
 public:
  /* Authentication methods
   * 0x03 -- 0x7F -- IANA assigned
   * 0x80 -- 0xFE -- reserved for private methods
   */
  enum class Method : uint16_t
  {
    no_authentication = 0x00,
    gssapi = 0x01,
    username_password = 0x02,
    no_acceptable_methods = 0xff
  };

  enum class Command : uint8_t
  {
    connect = 0x01,
    bind = 0x02,
    udp_associate = 0x03
  };

  enum class AddressType : uint8_t
  {
    ipv4 = 0x01,
    domain_name = 0x03,
    ipv6 = 0x04
  };


 private:
  
};

} }

#endif
