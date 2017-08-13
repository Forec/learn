#ifndef __CONSTANT_H_
#define __CONSTANT_H_

#include "BooleanExp.h"

class Constant : public BooleanExp {
public:
  Constant(bool);
  virtual ~Constant();

  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*,
                              BooleanExp& exp);
  virtual BooleanExp* Copy() const;
private:
  bool _value;
};

#endif
