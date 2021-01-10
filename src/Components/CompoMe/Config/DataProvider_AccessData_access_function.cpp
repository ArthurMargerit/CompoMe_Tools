#include "Components/CompoMe/Config/DataProvider_AccessData_access.hpp"
#include "Components/CompoMe/Config/DataProvider.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Config {

CompoMe::Config::Result_state
DataProvider_AccessData_access::add(CompoMe::String key,
                                    CompoMe::String value) {
  if(this->exist(key)) {
    return Result_state::INVALID_KEY;
  }

  auto& values = this->get_c().a_values();
  values[key] = value;

  return Result_state::VALID;
}
CompoMe::Config::Result_state
DataProvider_AccessData_access::set(CompoMe::String key,
                                    CompoMe::String value) {

  if(! this->exist(key)){
    return Result_state::INVALID_KEY;
  }

  auto& values = this->get_c().a_values();
  C_INFO(key, " = ", value , "previous =", values[key]);
  values[key]= value;
  return Result_state::VALID;
}

CompoMe::Config::Result_state
DataProvider_AccessData_access::del(CompoMe::String key) {

  if(! this->exist(key)){
    return Result_state::INVALID_KEY;
  }

  this->get_c().a_values().erase(key);
  return Result_state::VALID;
}

CompoMe::Config::Result_get
DataProvider_AccessData_access::get(CompoMe::String key) {

  CompoMe::Config::Result_get ret = CompoMe::Config::Result_get();

  if(! this->exist(key)){
    ret.set_state(Result_state::INVALID_KEY);
    return ret;
  }

  auto& val = this->get_c().a_values();

  auto r = val.find(key);
  if( r == val.end()) {
    ret.set_state(Result_state::INVALID_KEY);
    return ret;
  }

  ret.set_state(Result_state::VALID);
  ret.set_result((*r).second);
  return ret;
}

bool DataProvider_AccessData_access::exist(CompoMe::String key) {
  auto& val = this->get_c().a_values();
  return val.find(key) != val.end();
}

} // namespace Config

} // namespace CompoMe
