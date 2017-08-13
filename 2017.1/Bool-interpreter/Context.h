#ifndef __CONTEXT_H_
#define __CONTEXT_H_

#include <unordered_map>
#include <string>
#include "VariableExp.h"

class Context {
public:
  bool Lookup(const char*) const;
  void Assign(VariableExp *, bool);
private:
  std::unordered_map<std::string, bool> _map;
};

#endif
