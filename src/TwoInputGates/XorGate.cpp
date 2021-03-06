#include "XorGate.hpp"

using namespace std;

string const XorGate::gate_name = "XOR";

bool XorGate::eval() const { //return the value after evaluating it in the gate
    Gate* a = this->getRight();
    Gate* b = this->getLeft();
    Gate* not_a = new NotGate(a);
    Gate* not_b = new NotGate(b);
    Gate* or1 = new OrGate(a,b);
    Gate* or2 = new OrGate(not_a,not_b);
    Gate* xor1 = new AndGate(or1,or2);
    return xor1->eval();
}

void XorGate::truthtable() {
    InputGate *a = new InputGate('a');
    InputGate *b = new InputGate('b');
    Gate* xor1 = new XorGate(a,b);
    OutputGate* out = new OutputGate(xor1);
    cout << " XOR's truth table " << endl;
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

ostream &operator<<(ostream &out, const XorGate* g) {
    out << "XOR";
    return out;
}

void XorGate::toExpr() const{
  cout << this << '(';
  this->getLeft()->toExpr();
  cout << ',';
  this->getRight()->toExpr();
  cout << ')';
}
