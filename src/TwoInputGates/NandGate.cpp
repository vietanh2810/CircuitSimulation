#include "NandGate.hpp"

using namespace std;

string const NandGate::gate_name = "NAND_";

bool NandGate::eval() const {
    Gate* a = this->getRight();
    Gate* b = this->getLeft();
    Gate* and_tmp = new AndGate(a,b);
    Gate* not_tmp = new NotGate(and_tmp);
    return not_tmp->eval();
}

void NandGate::truthtable() {
    InputGate *a = new InputGate('a');
    InputGate *b = new InputGate('b');
    Gate* nand1 = new NandGate(a,b);
    OutputGate* out = new OutputGate(nand1);
    cout << "NAND's truth table " << endl;
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

ostream &operator<<(ostream &out, const NandGate* g) {
    out << "NAND";
    return out;
}

void NandGate::toExpr() const{
  cout << this << '(';
  this->getLeft()->toExpr();
  cout << ',';
  this->getRight()->toExpr();
  cout << ')';
}
