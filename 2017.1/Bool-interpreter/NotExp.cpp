#include "BooleanExp.h"
#include "NotExp.h"

NotExp::NotExp(BooleanExp* op) {
  _opernot = op;
}

NotExp::~NotExp() {
  delete _opernot;
}

bool NotExp::Evaluate(Context & aContext) {
  return
    !_opernot->Evaluate(aContext);
}

BooleanExp* NotExp::Copy () const {
  return
    new NotExp(_opernot->Copy());
}

BooleanExp* NotExp::Replace(const char* name,
                            BooleanExp& exp) {
  return
    new NotExp(_opernot->Replace(name, exp));
}
