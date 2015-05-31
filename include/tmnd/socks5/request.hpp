#ifndef TMND_SOCKS5_REQUEST_HPP
#define TMND_SOCKS5_REQUEST_HPP

namespace tmnd {

class Socks5Request
{

 private:
  const uint8_t version_ = 0x05;
  command command_;
  const uint8_t reserved_ = 0x00;
  address_type address_type_;
  
  
};

}

#endif
