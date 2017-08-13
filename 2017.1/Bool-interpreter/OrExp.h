#ifndef __OREXP_H_
#define __OREXP_H_

#include "BooleanExp.h"

class OrExp : public BooleanExp {
public:
  OrExp(BooleanExp*, BooleanExp*);
  virtual ~OrExp();

  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*,
                              BooleanExp &);
  virtual BooleanExp* Copy() const;
private:
  BooleanExp* _operor1;
  BooleanExp* _operor2;
};

#endif
