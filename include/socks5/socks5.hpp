#ifndef TMND_SOCKS5_HPP
#define TMND_SOCKS5_HPP
#include <boost/asio.hpp>

namespace tmnd { namespace socks5 {

class Socks5
{
 public:
  Socks5(const boost::asio::ip::tcp::endpoint&);
  
 private:
  const boost::asio::ip::tcp::endpoint& endpoint_;
  
};

} }

#endif
