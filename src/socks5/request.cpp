#incude "tmnd/socks5/request.hpp"

namespace tmnd { namespace socks5 {

Request::Request(command cmd, address_type atype, std::string address, uint16_t port) :
    command_(cmd),
    address_type_(atype),
    address_(address),
    port_(port)
{}

boost::asio::mutable_buffer Request::to_buffer()
{
  // calculating buffer size
  size_t address_size{};
  if (address_type_ == ipv4)
  {
    address_size = 4;
  } else if (address_type_ == domainname)
  {
    address_size = address_.length() + 1; // n bytes of address and 1 byte containing n
  } else if (address_type_ == ipv6)
  {
    address_size = 16;
  }
  size_t buffer_size{6 + address_size};
  unsigned char buffer[buffer_size];
  
  buffer[0] = version;
  buffer[1] = static_cast<uint8_t>(command_);
  buffer[2] = 0x00; // reserved
  buffer[3] = static_cast<uint8_t>(address_type_);
  size_t buf_pos{4};
  if (address_type_ == domainname)
  {
    buffer[4] = address_size;
    std::memcpy(buffer + 5, address_.data(), address_size);
    buf_pos = 5 + address_size;
  } else
  {
    std::memcpy(buffer+4, address_.data(), address_size);
    buf_pos = 4 + address_size;
  }
  buffer[buf_pos] = 0xff00 & port_;
  buffer[buf_pos + 1] = 0x00ff & port_;

  return boost::asio::buffer(buffer, buffer_size);
}

void Request::from_buffer(boost::asio::mutable_buffer mbuffer)
{
  size_t buffer_size = boost::asio::buffer_size(mbuffer);
  unsigned char* buffer = boost::asio::buffer_cast<unsigned char*>(mbuffer);
  
}

} }

