#pragma once

#include "Structs/CompoMe/Config/Result_get.hpp"

#include <memory>

namespace CompoMe {

namespace Config {

class Result_get_builder {

public:
  Result_get_builder();
  virtual ~Result_get_builder();

  // setter

  Result_get_builder &set_state(const CompoMe::Config::Result_state &p_state);

  Result_get_builder &set_result(const CompoMe::String &p_result);

  // build
  Result_get build();
  Result_get *build_p();
  std::shared_ptr<Result_get> build_sp();

protected:
  void asign(Result_get &p_name);

private:
  CompoMe::Config::Result_state state;

  CompoMe::String result;
};

} // namespace Config

} // namespace CompoMe
