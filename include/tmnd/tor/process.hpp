#ifndef TMND_TOR_PROCESS_HPP
#define TMND_TOR_PROCESS_HPP
#include <string>

namespace tmnd { namespace tor {

class Process
{
 public:
  Process();
  ~Process();

 private:
  std::string run_cmd_;
  std::string kill_cmd_;
  
};

} }

#endif
