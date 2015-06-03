#ifndef TMND_SOCKS5_REPLY_HPP
#define TMND_SOCKS5_REPLY_HPP
#include <cstdint>
#include <string>
#include <boost/asio.hpp>
#include "address_type.hpp"
#include "reply_code.hpp"

namespace tmnd { namespace socks5 {

class Reply
{
 public:
  Reply() {}
  Reply(boost::asio::mutable_buffer);
  
  uint8_t version();
  reply_code reply();
  address_type atype();
  std::string address();
  uint16_t port();
  
 private:
  void from_buffer_(boost::asio::mutable_buffer);
  
  const uint8_t version_ = 0x05;
  reply_code reply_;
  const uint8_t reserved = 0x00;
  address_type address_type_;
  std::string address_;
  uint16_t port_;
};

} }

#endif
