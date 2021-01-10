#include "Structs/CompoMe/Config/Result_get.hpp"

#include "CompoMe/Log.hpp"
#include <cstdlib>
#include <string>

namespace CompoMe {

namespace Config {

// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::istream &
Result_get::from_stream(std::istream &is,
                        CompoMe::Serialization_context_import &p_ctx) {
  Result_get l_reset;
  *this = l_reset;

  char l_c = is.get();
  if (l_c != '{') {
    C_ERROR("Wrong start: '", l_c, "' != '{'");
    throw "Wrong start: '"
          "' != '{'";
  }

  do {
    std::string args;
    std::getline(is, args, ':');

    switch (str2int(args.c_str())) {

    case str2int("type"): {
      auto t = CompoMe::get_word(is, {',', '}'});
      if (t.first != "Result_get") {
        throw "Wrong Type: "; // + "Result_get" + " != " + t.first ;
      }
      break;
    }

    case str2int("addr"): {
      void *addr;
      is >> addr;
      p_ctx.inscribe(addr, this);
      break;
    }

    case str2int("state"):

      is >> this->state;

      break;

    case str2int("result"):

      is >> this->result;

      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in Result_get");
      throw "wrong attribute: \"" + args + "\" not in Result_get";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  if (l_c != '}') {
    C_ERROR("Wrong end: '", l_c, "' != '}'");
    throw "Wrong end";
  }

  return is;
}

std::ostream &
Result_get::to_stream(std::ostream &os,
                      CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "Result_get";
  os << ",state:";

  os << this->state;
  os << ",result:";

  os << this->result;

  os << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const Result_get &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, Result_get &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

} // namespace Config

} // namespace CompoMe
