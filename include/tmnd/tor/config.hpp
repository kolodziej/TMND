#ifndef TMND_TOR_CONFIG_HPP
#define TMND_TOR_CONFIG_HPP
#include <utility>
#include <cstdint>
#include <istream>
#include "json.hpp"

using json = nlohmann::json;

namespace tmnd { namespace tor {

using PortRange = std::pair<uint16_t,uint16_t>;

class Config
{
 public:
  /* creates new configuration */
  Config();

  /* loads configuration from json object */
  Config(json config);

  /* loads configuration from stream (JSON serialized) */
  Config (std::istream& data);
  
 private:
  /* initializes config_ object with default values */
  void initializeDefault_();
  bool validateConfig_();

  json config_;
};

} }

#endif
