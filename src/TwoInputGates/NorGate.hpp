#ifndef NORGATE_HPP
#define NORGATE_HPP

#include "TwoInputGate.hpp"
#include "OrGate.hpp"
#include "../OneInputGates/NotGate.hpp"

class NorGate : public TwoInputGate {
protected:
    string static const gate_name;
public:
    NorGate(Gate *in1 = nullptr, Gate *in2 = nullptr) : TwoInputGate(in1, in2) {}
    bool eval() const override;
    void static truthtable();
    string toString() const override {return gate_name;};
    void toExpr() const override;
};

std::ostream &operator<<(std::ostream &out, const NorGate *g);

#endif //NORGATE_HPP
