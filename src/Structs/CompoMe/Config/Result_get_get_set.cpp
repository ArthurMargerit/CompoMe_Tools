#include "Structs/CompoMe/Config/Result_get.hpp"

namespace CompoMe {

namespace Config {

// GET SET ////////////////////////////////////////////////////////////////////

// get/set state
CompoMe::Config::Result_state Result_get::get_state() const {
  return this->state;
}

void Result_get::set_state(const CompoMe::Config::Result_state &p_state) {
  this->state = p_state;
}

CompoMe::Config::Result_state &Result_get::a_state() { return this->state; }

// get/set result
CompoMe::String Result_get::get_result() const { return this->result; }

void Result_get::set_result(const CompoMe::String &p_result) {
  this->result = p_result;
}

CompoMe::String &Result_get::a_result() { return this->result; }

} // namespace Config

} // namespace CompoMe
