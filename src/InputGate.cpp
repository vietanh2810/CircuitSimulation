#include "InputGate.hpp"

InputGate::InputGate(char a) : value(false),name(a) {}

bool InputGate::eval() const {
    return this->value;
}

void InputGate::setVal(bool a) {
    this->value = a;
}

void InputGate::empileGates(int prof) {
    vector<Gate*> sub_gate;
    sub_gate.push_back(this);
    OutputGate::AddGate(sub_gate,prof);
    this->setProf(prof);
}

string InputGate::toString() const {
    string tmp(1,this->getName());
    return tmp;
}
vector<string> InputGate::plot(int space,int size,vector<string> m) {
    string tmp;
    if(this->eval()){
        tmp = "1";
    } else {
        tmp = "0";
    }
    string ret = this->toString() + ":" + tmp;
    m.at(this->getProf()*4+1).replace(space,3,ret);
    return m;
}

ostream &operator<<(ostream &out, const InputGate* g) {
    out << g->getName();
    return out;
}

void InputGate::toExpr() const {
  cout << this->toString();
}
