#include "OutputGate.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "TwoInputGates/OrGate.hpp"
#include "TwoInputGates/XorGate.hpp"
#include "TwoInputGates/AndGate.hpp"
#include "OneInputGates/NotGate.hpp"
#include "TwoInputGates/NandGate.hpp"
#include "TwoInputGates/NorGate.hpp"
#include <fstream>

using namespace std;

char OutputGate::name_counter = 'A';

vector<vector<Gate*>> OutputGate::tmp_gates = vector<vector<Gate*>>();


OutputGate::OutputGate(Gate* g) : name(name_counter++),gates(vector<vector<Gate *>>()),in(g) {
  tmp_gates.clear();
  in->empileGates(0);
  gates = tmp_gates;
}

string OutputGate::toString() const {
    string tmp(1,this->getName());
    return tmp;
}

void OutputGate::AddGate(vector<Gate*> &g, size_t prof){
    if(prof >= tmp_gates.size()) {
        tmp_gates.push_back(g);
    } else {
        tmp_gates.at(prof) = concat(tmp_gates.at(prof), g);
    }
}

bool OutputGate::eval() const {
    return this->in->eval();
}


void OutputGate::plot() const{
    cout << "\n" << this->getName() << "'s 2D representation !!!!!" << endl;
    int size = gates.size();
    int tmp = pow(2,size);
    vector<string> the_matrix((size-1)*4+3,string((tmp+2)*2,' '));
    string ret;
    if(this->eval()){
        ret = "1";
    } else {
        ret = "0";
    }
    string res = string(1,this->getName()) + ":" + ret;
    the_matrix.at(0*4).replace(tmp,3,res);
    the_matrix = this->in->plot(tmp,size,the_matrix);
    for (auto t : the_matrix){
        cout << t <<endl;
    }
}

char OutputGate::getName() const { return name;}

ostream &operator<<(ostream &out, const OutputGate* g) {
    out << g->getName();
    return out;
}

Gate* OutputGate::getGate() const{
  return in;
}

void OutputGate::toExpr() const{
  cout << this->toString() << " can be translated into the following text:" <<endl;
  cout << this->toString() << '=';
  this->getGate()->toExpr();
}

void OutputGate::saveToFile() const {
    string outputDirectory = "circuits";
    string fileName = "circuit";
    fileName += this->toString();
    fileName += ".txt";
    ofstream out("circuits/" + fileName);
    if (out){
        // Redirecting cout stream to our file
        streambuf *coutbuf = cout.rdbuf(); // saving old buffer
        cout.rdbuf(out.rdbuf());
        cout << "Textual expression of circuit : " << endl;
        toExpr();
	      cout << endl;
        plot();
        // Restoring stream to standard output
        cout.rdbuf(coutbuf);
        out.close();
        cout << this->toString() << " saved succesfully to directory ./circuit :D" <<endl;
        cout<< "PLease check the file circuits/" << fileName <<" for the saved circuit";
	cout<< endl;
    } else {
        cout << "Problem in opening file" << endl;
    }
}
