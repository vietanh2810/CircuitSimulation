#include "NotGate.hpp"

string const NotGate::gate_name = "NOT";

bool NotGate::eval() const {
    bool tmp = this->getGate()->eval();
    if(tmp) return 0;
    else return 1;
}

void NotGate::truthtable() {
    InputGate *a = new InputGate('a');
    Gate *not1 = new NotGate(a);
    OutputGate *out = new OutputGate(not1);
    cout << "NOT's truth table" << endl;
    cout << "----------- " << endl;
    cout << "a    |   !a " << endl;
    cout << "----------- " << endl;
    cout <<a->eval()<<"    |    "<< out->eval() << endl;
    a->setVal(true);
    cout <<a->eval()<<"    |    "<< out->eval() << endl;
    cout<<endl;
}

ostream &operator<<(ostream &out, const NotGate* g) {
    out << "NOT";
    return out;
}

void NotGate::toExpr() const{
  cout << this << '(';
  this->getGate()->toExpr();
  cout << ')'; 
}
