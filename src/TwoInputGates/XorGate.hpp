#ifndef XORGATE_HPP
#define XORGATE_HPP

#include "TwoInputGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include "NorGate.hpp"
#include "../OneInputGates/NotGate.hpp"

class XorGate : public TwoInputGate {
protected:
    string static const gate_name;
public:
    XorGate(Gate *in1 = nullptr, Gate *in2 = nullptr) : TwoInputGate(in1,in2) {}
    bool eval() const override;
    void static truthtable();
    string toString() const override {return gate_name;};
    void toExpr() const override;
};

std::ostream &operator<<(std::ostream &out, const XorGate *g);

#endif //XORGATE_HPP
