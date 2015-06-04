#include <iostream>
#include <boost/asio.hpp>
#include "tmnd/socks5/socks5.hpp"

using namespace tmnd::socks5;

void init_callback(error err, boost::system::error_code ec, auth_method method)
{
  switch (err)
  {
    case error::no_error:
      std::cout << "Successfully connected to SOCKS5 proxy!\n";
      break;
    case error::init_send_error:
      std::cout << "Error while sending connect message to SOCKS5 proxy!\n";
      std::cout << "Boost: " << ec.message() << "\n";
      break;
    case error::init_receive_error:
      std::cout << "Error while receiveing initialize response from SOCKS5 proxy!\n";
      std::cout << "Boost: " << ec.message() << "\n";
      break;
  }
  
  std::cout << "Authorization method: " << static_cast<int>(method) << "\n";
}

void req_callback(error err, boost::system::error_code ec, Reply reply)
{
  std::cout << "Reply received\n";
}

int main(int argc, char** argv)
{
  boost::asio::io_service io;
  boost::asio::ip::tcp::socket socket(io);
  boost::asio::ip::tcp::resolver resolver(io);
  boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve({ "127.0.0.1", "9050" });
  socket.connect(endpoint);

  Socks5 socks(socket);
  socks.initialize({ auth_method::no_authentication }, [&](error err, boost::system::error_code ec, auth_method method) {
      init_callback(err, ec, method);
      Request request(command::connect, address_type::domainname, "kolodziej.in", 80);
      socks.request(request, &req_callback);
  });  

  io.run();
  return 0;
}
