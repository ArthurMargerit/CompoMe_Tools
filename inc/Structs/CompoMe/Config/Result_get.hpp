#pragma once

#include <ostream>
#include <memory>


#include "Structs/Struct.hpp"


// TYPES

// d.D_NAME

#include "Types/CompoMe/Config/Result_state.hpp"
  
// d.D_NAME

#include "Types/CompoMe/String.hpp"
  

// STRUCTS


struct DBusMessageIter;



namespace CompoMe{

namespace Config{



class Result_get : public CompoMe::Struct {
 public:

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  

  
  Result_get();
  

  virtual ~Result_get();

  Result_get(CompoMe::Config::Result_state p_state ,CompoMe::String p_result );

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  CompoMe::Config::Result_state get_state() const;
  void set_state(const CompoMe::Config::Result_state&);
  CompoMe::Config::Result_state & a_state();
  CompoMe::String get_result() const;
  void set_result(const CompoMe::String&);
  CompoMe::String & a_result();

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

// OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const CompoMe::Config::Result_get &other) const;
  bool operator!=(const CompoMe::Config::Result_get &other) const;

  std::ostream& to_stream(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const override;
  std::istream& from_stream(std::istream& is, CompoMe::Serialization_context_import& p_ctx) override;

  

  

 private:
  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  CompoMe::Config::Result_state state;
  CompoMe::String result;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream& operator<<(std::ostream& os, const Result_get& c);
std::istream& operator>>(std::istream& os, Result_get& c);
///////////////////////////////////////////////////////////////////////////////


} //CompoMe

} //Config

