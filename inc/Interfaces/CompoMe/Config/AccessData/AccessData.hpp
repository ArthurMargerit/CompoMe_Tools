#pragma once

#include "Data/CompoMe_Tools.hpp"

#include "Interfaces/Interface.hpp"

#include "Structs/CompoMe/Config/Result_get.hpp"

#include <functional>
#include <tuple>

namespace CompoMe {
class Caller_stream;
class Fake_stream;

class Caller_dbus;
class Fake_dbus;

class Function_dbus_send;
class Return_dbus_recv;

class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace CompoMe {

namespace Config {

class AccessData_caller_stream;

class AccessData_fake_stream;
class AccessData_fake_dbus;

class AccessData : public CompoMe::Interface {
public:
  using T_p_stream = std::tuple<AccessData_fake_stream *,
                                CompoMe::Fake_stream *, AccessData *>;
  using T_p_dbus =
      std::tuple<AccessData_fake_dbus *, CompoMe::Fake_dbus *, AccessData *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<AccessData_fake_dbus *, CompoMe::Fake_dbus *,
                           AccessData *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = CompoMe::Config::AccessData_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  AccessData();

  //! Destructor
  virtual ~AccessData() noexcept;
  virtual CompoMe::Config::Result_state add(CompoMe::String key,
                                            CompoMe::String value) = 0;
  virtual CompoMe::Config::Result_state set(CompoMe::String key,
                                            CompoMe::String value) = 0;
  virtual CompoMe::Config::Result_state del(CompoMe::String key) = 0;
  virtual CompoMe::Config::Result_get get(CompoMe::String key) = 0;
  virtual bool exist(CompoMe::String key) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace Config

} // namespace CompoMe

#include "Interfaces/CompoMe/Config/AccessData/AccessData_caller_stream.hpp"

#include "Interfaces/CompoMe/Config/AccessData/AccessData_fake_stream.hpp"
