
#include "Interfaces/CompoMe/Config/AccessData/AccessData_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace CompoMe {

namespace Config {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

AccessData_caller_stream::AccessData_caller_stream(AccessData &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool AccessData_caller_stream::call(CompoMe::Function_stream_recv &is,
                                    CompoMe::Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool AccessData_caller_stream::call(std::string &name_function,
                                    CompoMe::Function_stream_recv &is,
                                    CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("add"):
    result = this->add(is, os);
    break;

  case str2int("set"):
    result = this->set(is, os);
    break;

  case str2int("del"):
    result = this->del(is, os);
    break;

  case str2int("get"):
    result = this->get(is, os);
    break;

  case str2int("exist"):
    result = this->exist(is, os);
    break;
  };

  return result;
}

bool AccessData_caller_stream::add(CompoMe::Function_stream_recv &is,
                                   CompoMe::Return_stream_send &os) {

  CompoMe::String l_key;
  is >> l_key;
  is.get();

  CompoMe::String l_value;
  is >> l_value;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.add(l_key, l_value);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool AccessData_caller_stream::set(CompoMe::Function_stream_recv &is,
                                   CompoMe::Return_stream_send &os) {

  CompoMe::String l_key;
  is >> l_key;
  is.get();

  CompoMe::String l_value;
  is >> l_value;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.set(l_key, l_value);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool AccessData_caller_stream::del(CompoMe::Function_stream_recv &is,
                                   CompoMe::Return_stream_send &os) {

  CompoMe::String l_key;
  is >> l_key;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.del(l_key);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool AccessData_caller_stream::get(CompoMe::Function_stream_recv &is,
                                   CompoMe::Return_stream_send &os) {

  CompoMe::String l_key;
  is >> l_key;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.get(l_key);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool AccessData_caller_stream::exist(CompoMe::Function_stream_recv &is,
                                     CompoMe::Return_stream_send &os) {

  CompoMe::String l_key;
  is >> l_key;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.exist(l_key);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace Config

} // namespace CompoMe
