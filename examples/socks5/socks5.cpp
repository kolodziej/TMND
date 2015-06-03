#include <iostream>
#include <boost/asio.hpp>
#include "tmnd/socks5/socks5.hpp"

int main(int argc, char** argv)
{
  using namespace tmnd::socks5;

  boost::asio::io_service io;
  boost::asio::ip::tcp::socket socket(io);
  boost::asio::ip::tcp::resolver resolver(io);
  boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve({ "127.0.0.1", "9050" });
  socket.connect(endpoint);

  Socks5 socks(socket);
  socks.initialize({ auth_method::no_authentication });

  // make request
  Request request(command::connect, address_type::ipv4, { 37, 233, 101, 34 }, 80);
  

  io.run();
  return 0;
}
