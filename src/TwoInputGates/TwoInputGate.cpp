#include "TwoInputGate.hpp"

TwoInputGate::TwoInputGate(Gate *in1, Gate *in2) : left(in1),right(in2) {}

Gate* TwoInputGate::getLeft() const {
    return this->left;
}

Gate* TwoInputGate::getRight() const {
    return this->right;
}


void TwoInputGate::empileGates(int prof) {

    this->setProf(prof);
    vector<Gate*> sub_gate;
    sub_gate.push_back(this);
    OutputGate::AddGate(sub_gate,prof);
    this->getLeft()->empileGates(prof+1);
    this->getRight()->empileGates(prof+1);

}

vector<string> TwoInputGate::plot(int space,int size, vector<string> m) {
    if(this->toString() == "NAND_" or this->toString() == "NXOR_"){
        m.at(this->getProf()*4+1).replace(space-1,5,this->toString());
    } else {
        m.at(this->getProf()*4+1).replace(space,3,this->toString());
    }
    m.at(this->getProf()*4+2).replace(space+1,1,"|");
    int tmp = pow(2,(size-1-this->getProf()));
    m.at(this->getProf()*4+3).replace(space-tmp+1,2*tmp+1,string(2*tmp+1,'*'));
    m.at(this->getProf()*4+4).replace(space-tmp+1,1,"|");
    m.at(this->getProf()*4+4).replace(space+tmp+1,1,"|");
    m = this->getLeft()->plot(space-tmp,size,m);
    m = this->getRight()->plot(space+tmp,size,m);
    return m;
}

void TwoInputGate::toExpr() const{
  this->getLeft()->toExpr();
  cout << ',';
  this->getRight()->toExpr();
}
