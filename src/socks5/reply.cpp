#include "tmnd/socks5/reply.hpp"

namespace tmnd { namespace socks5 {

Reply::Reply(boost::asio::mutable_buffer mbuffer)
{
  from_buffer_(mbuffer);
}

uint8_t Reply::version()
{
  return version_;
}

reply_code Reply::reply()
{
  return reply_;
}

address_type Reply::atype()
{
  return address_type_;
}

std::string Reply::address()
{
  return address_;
}

uint16_t Reply::port()
{
  return port_;
}

void Reply::from_buffer_(boost::asio::mutable_buffer mbuffer)
{
  size_t buffer_size = boost::asio::buffer_size(mbuffer);
  unsigned char* buffer = boost::asio::buffer_cast<unsigned char*>(mbuffer);

  reply_ = static_cast<reply_code>(buffer[1]);
  address_type_ = static_cast<address_type>(buffer[3]);
  
  size_t address_size{};
  if (address_type_ == address_type::domainname)
  {
    address_size = static_cast<uint8_t>(buffer[4]);
    address_ = std::string(buffer + 5, buffer + 5 + address_size);

    // adding 1 to size -- first byte of domain name address
    // is length of domain name
    ++address_size;
  } else
  {
    if (address_type_ == address_type::ipv4)
    {
      address_size = 4; 
    } else if (address_type_ == address_type::ipv6)
    {
      address_size = 16;  
    }
    address_ = std::string(buffer + 4, buffer + 4 + address_size);
  }
  
  port_ = static_cast<uint8_t>(buffer[4 + address_size]) << 8;
  port_ += static_cast<uint8_t>(buffer[4 + address_size + 1]);
}

} }
