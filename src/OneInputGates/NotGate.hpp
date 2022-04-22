#ifndef NOTGATE_HPP
#define NOTGATE_HPP

#include "OneInputGate.hpp"

#include "../InputGate.hpp"
#include "../OutputGate.hpp"

class NotGate : public OneInputGate{
protected:
    string static const gate_name;
public:
    NotGate(Gate* in = nullptr) : OneInputGate(in) {} //constructor
    bool eval() const override; //evaluation
    void static truthtable(); //static function to show truth table
    string toString() const override {return gate_name;};
    void toExpr() const override;
};

std::ostream &operator<<(std::ostream &out, const NotGate *g);

#endif //NOTGATE_HPP
