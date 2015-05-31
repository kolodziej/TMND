#ifndef TMND_TOR_HPP
#define TMND_TOR_HPP
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

namespace tmnd {

class Tor
{
 public:
  using lowest_layer_socket = boost::asio::ip::tcp::socket;
  using ssl_stream = boost::asio::ssl::stream<lowest_layer_socket>;
  using endpoint_it = boost::asio::ip::tcp::resolver::iterator;

  Tor(boost::asio::io_service& io, boost::asio::ssl::context ctx, endpoint_it endpoint);
  
  template <typename Callback>
  void connect(Callback callback);

  template <typename Callback>
  void disconnect(Callback callback);

  template <typename Buffer, typename Callback>
  void read(Buffer& buffer, Callback callback);

  template <typename Buffer, typename Callback>
  void write(Buffer& buffer, Callback callback);

 private:
  ssl_stream socket_;
  endpoint_it endpoint_;
  
};

}

#endif
