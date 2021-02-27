
#include "Structs/CompoMe/Config/Result_get_builder.hpp"
#include "Structs/CompoMe/Config/Result_get_fac.hpp"



namespace CompoMe{

namespace Config{


Result_get_builder::Result_get_builder()

:

  state()
  ,

  result()
  

 {}
Result_get_builder::~Result_get_builder() {}





Result_get_builder& Result_get_builder::set_state(const CompoMe::Config::Result_state& p_state){
    this->state = p_state;
    return *this;
}

Result_get_builder& Result_get_builder::set_result(const CompoMe::String& p_result){
    this->result = p_result;
    return *this;
}


void Result_get_builder::asign(CompoMe::Config::Result_get& p_Result_get) {
  

  p_Result_get.set_state(this->state);
  p_Result_get.set_result(this->result);
  
}

Result_get Result_get_builder::build() {
    Result_get p_this;
    this->asign(p_this);
    return p_this;
}

Result_get* Result_get_builder::build_p() {
  Result_get* p_this = new Result_get();
  this->asign(*p_this);
  return p_this;
}

std::shared_ptr<Result_get> Result_get_builder::build_sp() {
  auto p_this = std::make_shared<Result_get>();
  this->asign(*p_this);
  return p_this;
}


} //CompoMe

} //Config

