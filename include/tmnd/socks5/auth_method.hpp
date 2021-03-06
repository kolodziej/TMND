#ifndef TMND_SOCKS5_AUTH_METHOD_HPP
#define TMND_SOCKS5_AUTH_METHOD_HPP

namespace tmnd { namespace socks5 {

enum class auth_method : uint8_t
{
  no_authentication = 0x00,
  gssapi = 0x01,
  user_pass = 0x02,
  no_methods = 0xff
};

} }

#endif
