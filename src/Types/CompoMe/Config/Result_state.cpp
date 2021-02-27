#include "Types/CompoMe/Config/Result_state.hpp"


#include "Serialization_context.hpp"
#include <string>




namespace CompoMe{

namespace Config{





} //CompoMe

} //Config




namespace std {
  namespace {
  constexpr unsigned int str2int(const char* str, int h = 0)
  {
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
  }
  }

std::ostream &operator<<(std::ostream &os, const CompoMe::Config::Result_state & c) {
  switch (c) {

  
  case CompoMe::Config::Result_state::VALID:
  os << "CompoMe::Config::Result_state::VALID";
    break;
  
  case CompoMe::Config::Result_state::INVALID_KEY:
  os << "CompoMe::Config::Result_state::INVALID_KEY";
    break;
  
  case CompoMe::Config::Result_state::INVALID_VALUE:
  os << "CompoMe::Config::Result_state::INVALID_VALUE";
    break;
  
  case CompoMe::Config::Result_state::INTERNAL_ERROR:
  os << "CompoMe::Config::Result_state::INTERNAL_ERROR";
    break;
  

  default:
    os << "ERROR";
  }

  return os;
}

std::istream &operator>>(std::istream &is, CompoMe::Config::Result_state & c) {
  std::string str;
  str = CompoMe::get_word(is, {',', ')', EOF}).first;
  switch (str2int(str.c_str())) {

  
  case str2int("1"): //value
  case str2int("VALID"): // no namespace and typename space
  case str2int("Result_state::VALID"): // no namespace space
  case str2int("CompoMe::Config::Result_state::VALID"): // namespace
    c = CompoMe::Config::Result_state::VALID;
    break;
  
  case str2int("2"): //value
  case str2int("INVALID_KEY"): // no namespace and typename space
  case str2int("Result_state::INVALID_KEY"): // no namespace space
  case str2int("CompoMe::Config::Result_state::INVALID_KEY"): // namespace
    c = CompoMe::Config::Result_state::INVALID_KEY;
    break;
  
  case str2int("3"): //value
  case str2int("INVALID_VALUE"): // no namespace and typename space
  case str2int("Result_state::INVALID_VALUE"): // no namespace space
  case str2int("CompoMe::Config::Result_state::INVALID_VALUE"): // namespace
    c = CompoMe::Config::Result_state::INVALID_VALUE;
    break;
  
  case str2int("4"): //value
  case str2int("INTERNAL_ERROR"): // no namespace and typename space
  case str2int("Result_state::INTERNAL_ERROR"): // no namespace space
  case str2int("CompoMe::Config::Result_state::INTERNAL_ERROR"): // namespace
    c = CompoMe::Config::Result_state::INTERNAL_ERROR;
    break;
  

  
  }
  return is;
}
}

