#include "Interface.h"
#include <iostream>

int main(){
  BooleanExp* expression;
  Context context;

  VariableExp* x = new VariableExp("x");
  VariableExp* y = new VariableExp("y");

  expression = new OrExp(new AndExp(new Constant(true), x),
                         new AndExp(y, new NotExp(x))
                         );

  context.Assign(x, false);
  context.Assign(y, true);

  VariableExp * z = new VariableExp("z");
  NotExp not_z(z);

  BooleanExp* replacement = expression->Replace("y", not_z);

  context.Assign(z, true);

  bool result = replacement->Evaluate(context);

  std::cout << result << std::endl;
  return 0;
}
