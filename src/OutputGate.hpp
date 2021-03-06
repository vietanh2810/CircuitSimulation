#ifndef OUTPUTGATE_HPP
#define OUTPUTGATE_HPP

#include "Gate.hpp"
#include <string>
#include <vector>

class OutputGate{
public:
    OutputGate(Gate* in); //basic constructor
    ~OutputGate();
    bool eval() const; // return the call to the eval function of the input Gate
    char getName() const;
    string toString() const;
    static void AddGate(vector<Gate*> &g, size_t prof);
    void plot() const;
    void toExpr() const;
    Gate* getGate() const;
    Gate* GateFromExpr(string expr) const;
    pair<string, string> ExtractArgs(string expr);
    void saveToFile() const;
protected:
    static char name_counter;
    char name;
    vector<vector<Gate*> > gates;
    Gate* in;
    static vector<vector<Gate*> > tmp_gates;
};

std::ostream &operator<<(std::ostream &out, const OutputGate *g);

#endif //OUTPUTGATE_HPP
