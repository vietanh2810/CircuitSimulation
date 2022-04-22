#ifndef NANDGATE_HPP
#define NANDGATE_HPP

#include "TwoInputGate.hpp"
#include "AndGate.hpp"
#include "../OneInputGates/NotGate.hpp"

class NandGate : public TwoInputGate{
protected:
    string static const gate_name;
public:
    NandGate(Gate* in1 = nullptr, Gate* in2 = nullptr) : TwoInputGate(in1,in2) {}
    bool eval() const override;
    void static truthtable() ;
    string toString() const override {return gate_name;};
    void toExpr() const override;
};

std::ostream &operator<<(std::ostream &out, const NandGate *g);

#endif //NANDGATE_HPP
