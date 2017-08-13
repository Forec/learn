#include "BooleanExp.h"
#include "OrExp.h"

OrExp::OrExp(BooleanExp* op1, BooleanExp* op2) {
  _operor1 = op1;
  _operor2 = op2;
}

OrExp::~OrExp() {
  delete _operor1;
  delete _operor2;
}

bool OrExp::Evaluate(Context & aContext) {
  return
    _operor1->Evaluate(aContext) ||
    _operor2->Evaluate(aContext);
}

BooleanExp* OrExp::Copy () const {
  return
    new OrExp(_operor1->Copy(),
              _operor2->Copy());
}

BooleanExp* OrExp::Replace(const char* name,
                            BooleanExp& exp) {
  return
    new OrExp(_operor1->Replace(name, exp),
              _operor2->Replace(name, exp));
}
