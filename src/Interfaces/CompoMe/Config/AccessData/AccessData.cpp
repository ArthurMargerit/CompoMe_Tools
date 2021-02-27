
#include "Interfaces/CompoMe/Config/AccessData/AccessData.hpp"



namespace CompoMe{

namespace Config{



AccessData::AccessData():a_caller_stream(nullptr) {}

AccessData::~AccessData() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
  
}

CompoMe::Caller_stream* AccessData::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}




} //CompoMe

} //Config

