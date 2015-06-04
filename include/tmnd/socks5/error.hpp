#ifndef TMND_SOCKS5_ERROR_HPP
#define TMND_SOCKS5_ERROR_HPP
#include <cstdint>

namespace tmnd { namespace socks5 {

enum class error : uint8_t
{
  no_error = 0,
  init_send_error = 1,
  init_receive_error = 2,
  request_send_error = 3,
  reply_receive_error = 4,
};

} }

#endif
