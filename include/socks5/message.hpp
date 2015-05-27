#ifndef TMND_SOCKS5_MESSAGE_HPP
#define TMND_SOCKS5_MESSAGE_HPP
#include <cstdint>

namespace tmnd { namespace socks5 {

class Message
{
 public:
  const uint8_t version = 0x05;

  enum class Command : uint8_t
  {
    connect = 0x01,
    bind = 0x02,
    udp_associate = 0x03
  };

  /* Authentication methods
   * 0x03 -- 0x7F -- IANA assigned
   * 0x80 -- 0xFE -- reserved for private methods
   */
  enum class Method : uint16_t
  {
    no_authentication = 0x00,
    gssapi = 0x01,
    username_password = 0x02,
    no_acceptable_methods = 0xff
  };

  enum class AddressType : uint8_t
  {
    ipv4 = 0x01,
    domain_name = 0x03,
    ipv6 = 0x04
  };

  enum class Reply : uint8_t
  {
    succeeded = 0x00,
    socks_server_failure = 0x01,
    connection_not_allowed = 0x02,
    network_unreachable = 0x03,
    host_unreachable = 0x04,
    connection_refused = 0x05,
    ttl_expired = 0x06,
    command_not_supported = 0x07,
    address_type_not_supported = 0x08
  };

  Message();
  
  template <typename Callback>
  /* tcp socket */ connectTcp(AddressType address_type, std::string address, Callback callback);
  
  template <typename Callback>
  /* udp socket */ connectUdp(AddressType address_type, std::string address, Callback callback);

  

 private:
  
};

} }

#endif
