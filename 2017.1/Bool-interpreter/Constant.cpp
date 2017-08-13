#include "BooleanExp.h"
#include "Constant.h"
#include "Context.h"

Constant::Constant(bool val) {
  _value = val;
}

Constant::~Constant() {
}

bool Constant::Evaluate(Context & aContext) {
  return _value;
}

BooleanExp* Constant::Copy () const {
  return new Constant(_value);
}

BooleanExp* Constant::Replace(const char* name,
                            BooleanExp& exp) {
  return this->Copy();
}
