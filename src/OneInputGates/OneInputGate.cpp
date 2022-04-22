#include "OneInputGate.hpp"

OneInputGate::OneInputGate(Gate *in) : in(in) {}

Gate *OneInputGate::getGate() const { return this->in;}

void OneInputGate::empileGates(int prof) {
    this->setProf(prof);
    vector<Gate*> sub_gate;
    sub_gate.push_back(this);
    OutputGate::AddGate(sub_gate,prof);
    this->getGate()->empileGates(prof+1);
}

vector<string> OneInputGate::plot(int space,int size, vector<string> m) {
    m.at(this->getProf()*4+1).replace(space,3,this->toString());
    m.at(this->getProf()*4+2).replace(space+1,1,"|");
    m.at(this->getProf()*4+3).replace(space+1,1,"|");
    m.at(this->getProf()*4+4).replace(space+1,1,"|");
    m = this->getGate()->plot(space,size,m);
    return m;
}

void OneInputGate::toExpr() const{
  this->getGate()->toExpr();
}
