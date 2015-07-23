#include "tmnd/tor/config.hpp"

#include <stdexcept>

namespace tmnd { namespace tor {

Config::Config()
{
  initializeDefault_();
}

Config::Config(json config) :
    config_(config)
{
  if (validateConfig_() == false)
    throw std::logic_error("tmnd::tor::Config (CTOR): invalid configuration!");
}

Config::Config(std::istream& stream)
{
  config_ << stream;
}

void Config::initializeDefault_()
{
  // range of TCP ports on which TMND will try to run SOCKS of Tor
  config_["socks_port_range"] = json{
    {"min", 9051},
    {"max", 65535}
  };

  config_["hs_directory"] = std::string("hidden_service");
}

} }
