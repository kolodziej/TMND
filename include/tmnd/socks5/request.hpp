#ifndef TMND_SOCKS5_REQUEST_HPP
#define TMND_SOCKS5_REQUEST_HPP
#include <string>
#include <boost/asio.hpp>
#include "command.hpp"
#include "address_type.hpp"

namespace tmnd {

class Request
{
 public:
  Request() {}
  Request(command cmd, address_type atype, std::string address, uint16_t port);
  
  boost::asio::mutable_buffer to_buffer();

 private:
  const uint8_t version_ = 0x05;
  command command_;
  const uint8_t reserved_ = 0x00;
  address_type address_type_;
  std::string address_;
  uint16_t port;
};

}

#endif
