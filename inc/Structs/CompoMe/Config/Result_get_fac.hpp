#pragma once

#include <map>
#include <functional>
#include <istream>
#include <memory>
#include "Serialization_context.hpp"



namespace CompoMe{

namespace Config{


class Result_get;

class Result_get_fac {
 public:
 using Build_fac_f = std::function<CompoMe::Config::Result_get*(const std::string&, std::istream&, CompoMe::Serialization_context_import& )>;
 using Build_fac_f_sp = std::function<std::shared_ptr<CompoMe::Config::Result_get>(const std::string&, std::istream&)>;

 static
 Result_get_fac& get_inst() {
   static Result_get_fac inst;
   return inst;
 }

 CompoMe::Config::Result_get* build(const std::string& p_type, std::istream& p, CompoMe::Serialization_context_import& p_ctx);
 std::shared_ptr<CompoMe::Config::Result_get> build_sp(const std::string& p_type, std::istream& p);

 void init();

 void subscribe(const std::string& ss, Build_fac_f v, Build_fac_f_sp v_sp);
 private:
 Result_get_fac();
 virtual ~Result_get_fac();
 std::map<std::string,std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};


} //CompoMe

} //Config

