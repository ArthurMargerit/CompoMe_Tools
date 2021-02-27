#include "Structs/CompoMe/Config/Result_get.hpp"
#include "Structs/CompoMe/Config/Result_get_fac.hpp"



#include <utility>
#include <string>
#include <cstdlib>

#include "CompoMe/Log.hpp"



namespace CompoMe{

namespace Config{



Result_get_fac::Result_get_fac() {
  this->init();
}

Result_get_fac::~Result_get_fac() {}

CompoMe::Config::Result_get* Result_get_fac::build(const std::string& p_type, std::istream& p_stream, CompoMe::Serialization_context_import& p_ctx) {

  if (p_type == "CompoMe::Config::Result_get") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<Result_get>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
      CompoMe::Config::Result_get* b = new CompoMe::Config::Result_get();
      b->from_stream(p_stream, p_ctx);
      //    }
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream, p_ctx);
  }

  C_ERROR("Error: of Serializable* build ", "Your type \"", p_type, "\" is not include or not init as a child.");

  return NULL;
}

std::shared_ptr<CompoMe::Config::Result_get> Result_get_fac::build_sp(const std::string& p_type, std::istream& p_stream) {

  if (p_type == "CompoMe::Config::Result_get") {
    auto b =std::make_shared<CompoMe::Config::Result_get>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  C_ERROR("Error: of std::shared_ptr<CompoMe::Config::Result_get> build ",
          "Your type \"", p_type,
          "\" is not include or not init as a child.");

  return std::shared_ptr<CompoMe::Config::Result_get>();
}

void Result_get_fac::init() {

    
    CompoMe::Serializable_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s, CompoMe::Serialization_context_import& l_ctx)
                                               {return dynamic_cast<CompoMe::Serializable_Item*>(Result_get_fac::get_inst().build(str, p_s, l_ctx)); };
    CompoMe::Serializable_fac::Build_fac_f_sp  f_sp= [](const std::string& str,std::istream& p_s)
                                {return Result_get_fac::get_inst().build_sp(str,p_s); };

    CompoMe::Serializable_fac::get_inst().subscribe("CompoMe::Config::Result_get", f, f_sp);
    
  }

void Result_get_fac::subscribe(const std::string& ss, Build_fac_f v,Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v,v_sp);

  
  CompoMe::Serializable_fac::get_inst().subscribe(ss, v, v_sp);
  
 }


} //CompoMe

} //Config

