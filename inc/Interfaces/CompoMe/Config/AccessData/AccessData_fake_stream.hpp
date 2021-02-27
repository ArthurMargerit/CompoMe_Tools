#pragma once

#include "Data/CompoMe_Tools.hpp"

#include "Interfaces/CompoMe/Config/AccessData/AccessData.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe



namespace CompoMe{

namespace Config{


class AccessData_fake_stream :public CompoMe::Config::AccessData, public CompoMe::Fake_stream {
public:
  // constructor
  AccessData_fake_stream(CompoMe::Function_stream_send& out, CompoMe::Return_stream_recv& in);

  //! Destructor
  virtual ~AccessData_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<CompoMe::Config::AccessData*>(new CompoMe::Config::AccessData_fake(os,is));
  // }

  bool is_fake() override {return true;}

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////
  
  
  
  
  virtual
  CompoMe::Config::Result_state add(CompoMe::String key,CompoMe::String value) override;
  
  
  virtual
  CompoMe::Config::Result_state set(CompoMe::String key,CompoMe::String value) override;
  
  
  virtual
  CompoMe::Config::Result_state del(CompoMe::String key) override;
  
  
  virtual
  CompoMe::Config::Result_get get(CompoMe::String key) override;
  
  
  virtual
  bool exist(CompoMe::String key) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  
};


} //CompoMe

} //Config

