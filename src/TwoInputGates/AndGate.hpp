#ifndef ANDGATE_HPP
#define ANDGATE_HPP

#include "TwoInputGate.hpp"

class AndGate : public TwoInputGate{
protected:
    string static const gate_name;
public:
    AndGate(Gate* in1 = nullptr, Gate* in2 = nullptr) : TwoInputGate(in1,in2) {}
    bool eval() const override;
    void static truthtable();
    string toString() const override {return gate_name;};
    void toExpr() const override;
};

std::ostream &operator<<(std::ostream &out, const AndGate *g);

#endif //ANDGATE_HPP
