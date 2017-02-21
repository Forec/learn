#include "Context.h"

bool Context::Lookup(const char* name) const {
  std::string _name(name);
  return _map.at(_name);
}

void Context::Assign(VariableExp * var, bool val){
  if (!var)
    return;
  std::string _name(var->getName());
  _map[_name] = val;
}
