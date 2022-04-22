#include "NorGate.hpp"

using namespace std;

string const NorGate::gate_name = "NOR";

bool NorGate::eval() const {
    Gate* a = this->getRight();
    Gate* b = this->getLeft();
    Gate* or_tmp = new OrGate(a,b);
    Gate* not_tmp = new NotGate(or_tmp);
    return not_tmp->eval();
}

void NorGate::truthtable() {
    InputGate *a = new InputGate('a');
    InputGate *b = new InputGate('b');
    Gate* nor1 = new NorGate(a,b);
    OutputGate* out = new OutputGate(nor1);
    cout << " NOR's truth table " << endl;
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

ostream &operator<<(ostream &out, const NorGate* g) {
    out << "NOR";
    return out;
}

void NorGate::toExpr() const{
  cout << this << '(';
  this->getLeft()->toExpr();
  cout << ',';
  this->getRight()->toExpr();
  cout << ')';
}
