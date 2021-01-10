#include "Interfaces/CompoMe/Config/AccessData/AccessData_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace CompoMe {

namespace Config {

AccessData::T_p_stream
AccessData::get_fake_stream(CompoMe::Function_stream_send &fs,
                            CompoMe::Return_stream_recv &rs) {
  AccessData_fake_stream *a = new AccessData_fake_stream(fs, rs);
  std::tuple<AccessData_fake_stream *, CompoMe::Fake_stream *, AccessData *> rr(
      a, a, a);
  return rr;
}

AccessData_fake_stream::AccessData_fake_stream(
    CompoMe::Function_stream_send &out, CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

AccessData_fake_stream::~AccessData_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function AccessData
// ////////////////////////////////////////////////

CompoMe::Config::Result_state
AccessData_fake_stream::add(CompoMe::String key, CompoMe::String value) {
  this->get_o().start();
  this->get_o() << "add(" << key << "," << value << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  CompoMe::Config::Result_state ri = CompoMe::Config::Result_state();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

CompoMe::Config::Result_state
AccessData_fake_stream::set(CompoMe::String key, CompoMe::String value) {
  this->get_o().start();
  this->get_o() << "set(" << key << "," << value << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  CompoMe::Config::Result_state ri = CompoMe::Config::Result_state();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

CompoMe::Config::Result_state AccessData_fake_stream::del(CompoMe::String key) {
  this->get_o().start();
  this->get_o() << "del(" << key << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  CompoMe::Config::Result_state ri = CompoMe::Config::Result_state();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

CompoMe::Config::Result_get AccessData_fake_stream::get(CompoMe::String key) {
  this->get_o().start();
  this->get_o() << "get(" << key << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  CompoMe::Config::Result_get ri = CompoMe::Config::Result_get();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

bool AccessData_fake_stream::exist(CompoMe::String key) {
  this->get_o().start();
  this->get_o() << "exist(" << key << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  bool ri = bool();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set AccessData
// /////////////////////////////////////////////////

} // namespace Config

} // namespace CompoMe
