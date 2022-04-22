CPP=g++ --std=c++11
CFLAGS= -Wall

all : main

main : main.o Gate.o TwoInputGate.o InputGate.o OutputGate.o OneInputGate.o NotGate.o AndGate.o NandGate.o NorGate.o OrGate.o XorGate.o NxorGate.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

Gate.o : Gate.cpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

TwoInputGate.o : TwoInputGates/TwoInputGate.cpp TwoInputGates/TwoInputGate.hpp
	$(CPP) $(CFLAGS) -c $<

InputGate.o : InputGate.cpp InputGate.hpp
	$(CPP) $(CFLAGS) -c $<

OutputGate.o : OutputGate.cpp OutputGate.hpp
	$(CPP) $(CFLAGS) -c $<

OneInputGate.o : OneInputGates/OneInputGate.cpp OneInputGates/OneInputGate.hpp
	$(CPP) $(CFLAGS) -c $<

NotGate.o : OneInputGates/NotGate.cpp OneInputGates/NotGate.hpp
	$(CPP) $(CFLAGS) -c $<

AndGate.o : TwoInputGates/AndGate.cpp TwoInputGates/AndGate.hpp
	$(CPP) $(CFLAGS) -c $<

NandGate.o : TwoInputGates/NandGate.cpp TwoInputGates/NandGate.hpp
	$(CPP) $(CFLAGS) -c $<

NorGate.o : TwoInputGates/NorGate.cpp TwoInputGates/NorGate.hpp
	$(CPP) $(CFLAGS) -c $<

OrGate.o : TwoInputGates/OrGate.cpp TwoInputGates/OrGate.hpp
	$(CPP) $(CFLAGS) -c $<

XorGate.o : TwoInputGates/XorGate.cpp TwoInputGates/XorGate.hpp
	$(CPP) $(CFLAGS) -c $<

NxorGate.o : TwoInputGates/NxorGate.cpp TwoInputGates/NxorGate.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o

test: all
	./main