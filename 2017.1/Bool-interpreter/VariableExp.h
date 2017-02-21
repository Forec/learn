#ifndef __VARIABLE_EXP_H_
#define __VARIABLE_EXP_H_

#include "BooleanExp.h"

class VariableExp: public BooleanExp {
public:
  VariableExp(const char*);
  virtual ~VariableExp();

  virtual bool Evaluate(Context &);
  virtual BooleanExp* Replace(const char*, BooleanExp &);
  virtual BooleanExp* Copy() const;

  char* getName();
private:
  char * _name;
};

#endif
