#pragma once

#include <istream>
#include <ostream>

namespace CompoMe {

namespace Config {

enum class Result_state {

  VALID = 1,

  INVALID_KEY = 2,

  INVALID_VALUE = 3,

  INTERNAL_ERROR = 4

};

} // namespace Config

} // namespace CompoMe

namespace std {

std::ostream &operator<<(std::ostream &os,
                         const CompoMe::Config::Result_state &);

std::istream &operator>>(std::istream &is, CompoMe::Config::Result_state &);
} // namespace std
