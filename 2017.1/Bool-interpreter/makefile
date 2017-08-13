OBJECTS=main.o AndExp.o OrExp.o NotExp.o VariableExp.o \
					 Constant.o Context.o
EXECUTABLE=main.exe
CXXFLAGS=-std=c++1y

main : $(OBJECTS)
	g++ $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)
main.o : main.cpp Interface.h
AndExp.o OrExp.o NotExp.o VariableExp.o Constant.o : BooleanExp.h
Context.o : VariableExp.h

.PHONY : clean
clean :
	rm $(EXECUTABLE) $(OBJECTS)
