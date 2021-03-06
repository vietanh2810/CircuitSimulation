#include <iostream>
#include <fstream>
#include "Gate.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "TwoInputGates/OrGate.hpp"
#include "TwoInputGates/XorGate.hpp"
#include "TwoInputGates/NxorGate.hpp"
#include "TwoInputGates/AndGate.hpp"
#include "OneInputGates/NotGate.hpp"
#include "TwoInputGates/NandGate.hpp"
#include "TwoInputGates/NorGate.hpp"

pair<string, string> ExtractArgs(string expr) {
    pair<string, string> args;
    int cPos = 0; //comma position
    int pCounter = 0; //count parenthesis
    for (size_t i=0 ; i < expr.size() ; i++){
        if (expr[i] == '(')
            pCounter++;
        else if (expr[i] == ')')
            pCounter--;
        else if ((expr[i] == ',') && (pCounter == 0))
            cPos = i;
    }
    if (cPos!=0){
        args.first = expr.substr(0, cPos);
        args.second = expr.substr(cPos + 1, expr.size());
    }else{
        args.first = expr.substr(cPos, expr.size());
    }
    return args;
}

Gate *GateFromExpr(string expr){
    if (expr.size() == 1){
        return new InputGate(expr[0]);
    }
    else{
        string gateType = expr.substr(0, expr.find('('));
        pair<string, string> gateArgs =
                ExtractArgs(expr.substr(expr.find('(') + 1, expr.size() - expr.find('(') - 2));
        if (gateArgs.second.empty()) {
            if (gateType == "NOT")
                return new NotGate(GateFromExpr(gateArgs.first));
        }
        else {
            if (gateType == "AND")
                return  new AndGate(GateFromExpr(gateArgs.first),GateFromExpr(gateArgs.second));
            else if (gateType == "NAND")
                return  new NandGate(GateFromExpr(gateArgs.first),GateFromExpr(gateArgs.second));
            else if (gateType == "NOR")
                return  new NorGate(GateFromExpr(gateArgs.first),GateFromExpr(gateArgs.second));
            else if (gateType == "OR")
                return  new OrGate(GateFromExpr(gateArgs.first),GateFromExpr(gateArgs.second));
            else if (gateType == "XOR")
                return  new XorGate(GateFromExpr(gateArgs.first),GateFromExpr(gateArgs.second));
	          else if (gateType == "NXOR")
	              return  new NxorGate(GateFromExpr(gateArgs.first),GateFromExpr(gateArgs.second));
        }
    }
    return nullptr;
}

Gate* readFile(string fileName){
    ifstream in("circuits/"+fileName);
    string line;
    getline(in,line); //skip the first 2 lines
    getline(in,line);
    getline(in,line);
    in.close();
    return GateFromExpr(line.substr(2));
}


int main() {
    InputGate *a = new InputGate('a');
    InputGate *b = new InputGate('b');
    InputGate *c = new InputGate('c');
    Gate *or1 = new OrGate(a,b);
    Gate *and1 = new NandGate(a,b);
    Gate *and2 = new XorGate(or1,and1);
    Gate *nor1 = new NorGate(c,a);
    Gate *not1 = new NotGate(nor1);
    Gate *and3 = new AndGate(not1,and2);
    OutputGate *A = new OutputGate(and3);
    A->plot();
    //NotGate::truthtable();
    A->toExpr();
    cout << endl << endl;
    A->saveToFile();
    OutputGate *B = new OutputGate(GateFromExpr("XOR(OR(a,b),AND(a,b))"));
    B->plot();
    OutputGate *C = new OutputGate(readFile("circuitA.txt"));
    C->plot();
    return 0;
}


