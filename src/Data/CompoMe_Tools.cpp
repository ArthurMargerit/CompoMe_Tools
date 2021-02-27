#include "Data/CompoMe_Tools.hpp"


#include "Structs/CompoMe/Config/Result_get_fac.hpp"



#include "Components/CompoMe/Config/DataProvider_fac.hpp"

void init_CompoMe_Tools() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  init_CompoMe_Log();
  init_CompoMe_Swig();
  init_CompoMe();
  

  
  CompoMe::Config::Result_get_fac::get_inst();

  

  

  
  CompoMe::Config::DataProvider_fac::get_inst();
}