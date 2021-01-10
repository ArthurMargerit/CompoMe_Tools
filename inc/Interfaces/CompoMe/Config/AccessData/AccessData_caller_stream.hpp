#pragma once

#include "Interfaces/CompoMe/Config/AccessData/AccessData.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace CompoMe {

namespace Config {

class AccessData_caller_stream : public CompoMe::Caller_stream {
private:
  CompoMe::Config::AccessData &comp;

public:
  AccessData_caller_stream(CompoMe::Config::AccessData &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool add(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool set(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool del(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool get(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool exist(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
};

} // namespace Config

} // namespace CompoMe
