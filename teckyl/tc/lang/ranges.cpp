
#include "teckyl/tc/lang/ranges.h"

namespace ranges {

  std::string dumpArithOp(ARITH op) {
    switch (op) {
    case PLUS:  return "+";
    case MINUS: return "-";
    case TIMES: return "*";
    }
  }

  std::string dumpCmpOp(CMP op) {
    switch (op) {
    case LT:  return "<";
    case LE:  return "<=";
    case EQ:  return "==";
    case GE:  return ">=";
    case GT:  return "<";
    }
  }

  std::string BinOp::dump() const {
    std::stringstream ss;
    ss << "(" << l->dump() << dumpArithOp(op) << r->dump() << ")";
    return ss.str();
  }

  std::string Variable::dump() const {
    return n;
  }

  std::string Parameter::dump() const {
    return "$" + n;
  }

  std::string Constant::dump() const {
    std::stringstream ss;
    ss << val;
    return ss.str();
  }


  std::string Constraint::dump() const {
    std::stringstream ss;
    ss << l->dump() << " " << dumpCmpOp(op) << " " << r->dump();
    return ss.str();
  }

  std::string Range::dump() const {
    std::stringstream ss;
    ss << low->dump() << " <= " << n << " < " << up->dump();
    return ss.str();
  }

  std::string InferenceProblem::dump() const {
    std::stringstream ss;

    ss << "ranges:\n";
    for (const auto &r : solved)
      ss << r.dump() << "\n";
    
    ss << "constraints:\n";
    for (const auto &c : constraints)
      ss << c.dump() << "\n";

    ss << "------------------------------------------------------------\n";
    
    return ss.str();
  }

} // namespace ranges

