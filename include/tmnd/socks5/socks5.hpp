#ifndef TMND_SOCKS5_HPP
#define TMND_SOCKS5_HPP
#include <boost/asio.hpp>
#include <cstdint>

#include "auth_method.hpp"
#include "command.hpp"
#include "address_type.hpp"
#include "request.hpp"
#include "reply.hpp"

namespace tmnd { namespace socks5 {

class Socks5
{
 public:
  Socks5(boost::asio::ip::tcp::socket& socket);

  void initialize(std::initializer_list<auth_method>);
  void initialize_callback(boost::system::error_code, size_t);

  void initialize_reply();
  void initialize_reply_callback(boost::system::error_code, size_t);

  void authenticate(auth_method);
  void no_authentication() {};
  void gssapi() {};
  void user_pass(std::string user, std::string pass) {};

  void request(Request);
  void request_callback(boost::system::error_code, size_t);

 private:
  boost::asio::ip::tcp::socket& socket_;

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
