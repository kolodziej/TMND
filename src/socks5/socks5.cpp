#include "tmnd/socks5/socks5.hpp"

namespace tmnd { namespace socks5 {

Socks5::Socks5(boost::asio::ip::tcp::socket& socket) :
  socket_(socket)
{}

void Socks5::initialize(std::initializer_list<auth_method> methods)
{
  init_request_.nmethods = methods.size();
  size_t i = 0;
  for (auto method : methods)
  {
    init_request_.methods[i] = method;
    ++i;
  }

  using namespace std::placeholders;
  socket_.async_send(
      boost::asio::buffer(reinterpret_cast<char*>(&init_request_), init_request_.nmethods + 2),
      std::bind(&Socks5::initialize_callback, this, _1, _2)
  );
}

void Socks5::initialize_callback(boost::system::error_code ec, size_t transferred)
{
  if (ec.value() != 0)
  {
    // log error
  } else
  {
    initialize_reply();
  }
}

void Socks5::initialize_reply()
{
  using namespace std::placeholders;
  socket_.async_receive(
      boost::asio::buffer(reinterpret_cast<char*>(&init_reply_), sizeof(init_reply_)),
      std::bind(&Socks5::initialize_reply_callback, this, _1, _2)
  );
}

void Socks5::initialize_reply_callback(boost::system::error_code ec, size_t transferred)
{
  if (ec.value() != 0)
  {
    // log error
  } else
  {
    authenticate(init_reply_.method);
  }
}

void Socks5::authenticate(auth_method method)
{
  switch (method)
  {
    case auth_method::no_authentication:
      no_authentication();
      break;

    case auth_method::gssapi:
      gssapi();
      break;

    case auth_method::user_pass:
      user_pass();
      break;
      
    case auth_method::no_methods:
      // log error
      break;

    default:
      // log error
      break;
  }
}

void Socks5::request(command cmd, address_type atype, std::string address)
{
  
}

} }
