#ifndef NXORGATE_HPP
#define NXORGATE_HPP

#include "TwoInputGate.hpp"
#include "XorGate.hpp"
#include "../OneInputGates/NotGate.hpp"

class NxorGate : public TwoInputGate{
protected:
    string static const gate_name;
public:
    NxorGate(Gate* in1 = nullptr, Gate* in2 = nullptr) : TwoInputGate(in1,in2) {}
    bool eval() const override;
    void static truthtable() ;
    string toString() const override {return gate_name;};
    void toExpr() const override;
};

std::ostream &operator<<(std::ostream &out, const NxorGate *g);

#endif //NXORGATE_HPP
