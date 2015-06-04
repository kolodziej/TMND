#include "tmnd/tor/process.hpp"

#include <cstdlib>

namespace tmnd { namespace tor {

Process::Process()
{
  #ifdef unix
  run_cmd_ = "./run_tor.sh";
  kill_cmd_ = "./kill_tor.sh";
  #endif
  #ifdef _WIN32
  run_cmd_ = "run_tor.bat";
  kill_cmd_ = "kill_tor.bat";
  #endif

  std::system(run_cmd_.data());
}

Process::~Process()
{
  std::system(kill_cmd_.data());
}

} }
