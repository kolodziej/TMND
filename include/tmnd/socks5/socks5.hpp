#ifndef TMND_SOCKS5_HPP
#define TMND_SOCKS5_HPP
#include <boost/asio.hpp>
#include <cstdint>

#include "auth_method.hpp"
#include "command.hpp"
#include "address_type.hpp"
#include "request.hpp"
#include "reply.hpp"
#include "error.hpp"

namespace tmnd { namespace socks5 {

class Socks5
{
 public:
  Socks5(boost::asio::ip::tcp::socket& socket);

  using InitCallback = std::function<void(error, boost::system::error_code, auth_method)>;
  using RequestCallback = std::function<void(error, boost::system::error_code, Reply)>;
  
  void initialize(std::initializer_list<auth_method>, InitCallback);
  void request(Request, RequestCallback);

 private:
  void initialize_callback_(boost::system::error_code, size_t);
  void initialize_reply_();
  void initialize_reply_callback_(boost::system::error_code, size_t);
  void request_callback_(boost::system::error_code, size_t);
  void request_reply_();
  void request_reply_callback_(boost::system::error_code, size_t);

  boost::asio::ip::tcp::socket& socket_;
  InitCallback initialize_callback_func_;
  RequestCallback request_callback_func_;
  bool initialized_;

  unsigned char buffer_[255];

  struct init_request
  {
    const uint8_t version = 0x05;
    uint8_t nmethods;
    auth_method methods[255];
  } init_request_;

  struct init_reply
  {
    const uint8_t version = 0x05;
    auth_method method;
  } init_reply_;

};

} }

#endif
