#include "NxorGate.hpp"

using namespace std;

string const NxorGate::gate_name = "NXOR_";

bool NxorGate::eval() const { //return the value after evaluating it in the gate
    Gate* a = this->getRight();
    Gate* b = this->getLeft();
    Gate* xor_tmp = new XorGate(a,b);
    Gate* not_tmp = new NotGate(xor_tmp);
    return not_tmp->eval();
}

void NxorGate::truthtable() {
    InputGate *a = new InputGate('a');
    InputGate *b = new InputGate('b');
    Gate* nxor1 = new NxorGate(a,b);
    OutputGate* out = new OutputGate(nxor1);
    cout << "NXOR's truth table " << endl;
    cout << "-------------------" << endl;
    cout << "a  |   b   | a || b" << endl;
    cout << "-------------------" << endl;
    cout <<a->eval()<<"  |   "<<b->eval()<<"   |   "<< out->eval() << endl;
    a->setVal(true);
    b->setVal(false);
    cout <<a->eval()<<"  |   "<<b->eval()<<"   |   "<< out->eval() << endl;
    a->setVal(false);
    b->setVal(true);
    cout <<a->eval()<<"  |   "<<b->eval()<<"   |   "<< out->eval() << endl;
    a->setVal(true);
    b->setVal(true);
    cout <<a->eval()<<"  |   "<<b->eval()<<"   |   "<< out->eval() << endl;
}

ostream &operator<<(ostream &out, const NxorGate* g) {
    out << "NXOR_";
    return out;
}

void NxorGate::toExpr() const{
  cout << this << '(';
  this->getLeft()->toExpr();
  cout << ',';
  this->getRight()->toExpr();
  cout << ')';
}
