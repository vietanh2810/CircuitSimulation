#include "AndGate.hpp"

using namespace std;

string const AndGate::gate_name = "AND";

bool AndGate::eval() const {
    bool a = this->getRight()->eval();
    bool b = this->getLeft()->eval();
    return (a && b);
}


void AndGate::truthtable() {
    InputGate *a = new InputGate('a');
    InputGate *b = new InputGate('b');
    Gate* and1 = new AndGate(a,b);
    OutputGate* out = new OutputGate(and1);
    cout << " AND's truth table" << endl;
    cout << "-------------------" << endl;
    cout << "a  |   b   | a && b" << endl;
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
    cout<<endl;
}

ostream &operator<<(ostream &out, const AndGate* g) {
    out << "AND";
    return out;
}

void AndGate::toExpr() const{
  cout << this << '(';
  this->getLeft()->toExpr();
  cout << ',';
  this->getRight()->toExpr();
  cout << ')';
}
