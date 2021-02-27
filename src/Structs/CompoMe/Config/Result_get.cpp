#include "Structs/CompoMe/Config/Result_get.hpp"
#include "Structs/CompoMe/Config/Result_get_fac.hpp"

#include <ostream>
#include <istream>
#include <sstream>



namespace CompoMe{

namespace Config{





Result_get::Result_get():Result_get(CompoMe::Config::Result_state(),CompoMe::String()){}


Result_get::Result_get(CompoMe::Config::Result_state p_state,CompoMe::String p_result)
  :Struct()
     ,state(p_state)
  
     ,result(p_result)
   {
}

Result_get::~Result_get(){}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool Result_get::operator==(const CompoMe::Config::Result_get &other) const {
  return 
  true 
  
  
  && this->state == other.state
  
  && this->result == other.result
  ;
}

bool Result_get::operator!=(const CompoMe::Config::Result_get &other) const {
  return !(*this == other); 
}



} //CompoMe

} //Config

