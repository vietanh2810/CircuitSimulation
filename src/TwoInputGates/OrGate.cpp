#include "OrGate.hpp"

using namespace std;

string const OrGate::gate_name = "OR_";

bool OrGate::eval() const {
    bool a = this->getRight()->eval();
    bool b = this->getLeft()->eval();
    return (a || b);
}

void OrGate::truthtable() {
    InputGate *a = new InputGate('a');
    InputGate *b = new InputGate('b');
    Gate* or1 = new OrGate(a,b);
    OutputGate* out = new OutputGate(or1);
    cout << "  OR's truth table " << endl;
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

ostream &operator<<(ostream &out, const OrGate* g) {
    out << "OR";
    return out;
}

void OrGate::toExpr() const{
  cout << this << '(';
  this->getLeft()->toExpr();
  cout << ',';
  this->getRight()->toExpr();
  cout << ')';
}
