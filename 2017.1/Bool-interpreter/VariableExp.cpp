#include "VariableExp.h"
#include "Context.h"
#include <cstring>

VariableExp::VariableExp(const char* name){
  _name = new char[strlen(name)];
  strcpy(_name, name);
}

VariableExp::~VariableExp(){
  delete _name;
}

bool VariableExp::Evaluate(Context& aContext){
  return aContext.Lookup(_name);
}

BooleanExp* VariableExp::Copy() const {
  return new VariableExp(_name);
}

BooleanExp* VariableExp::Replace(const char* name,
                                 BooleanExp& exp){
  if (!strcmp(name, _name)){
    return exp.Copy();
  }
  return new VariableExp(_name);
}

char* VariableExp::getName() {
  return _name;
}
