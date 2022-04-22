#ifndef TWOINPUTGATE_HPP
#define TWOINPUTGATE_HPP

#include "../Gate.hpp"
#include "../InputGate.hpp"
#include "../OutputGate.hpp"
#include <string>
#include <iostream>

class TwoInputGate : public Gate{
public:
    //constructor
    TwoInputGate(Gate* in1 = nullptr, Gate* in2 = nullptr);
    //getters
    Gate* getRight() const;
    Gate* getLeft() const;
    int getProf() const {return this->prof;};
    //setter
    void setProf(int prof) override {this->prof = prof;};
    //others functions
    vector<string> plot(int space,int size, vector<string> m) override;
    void empileGates(int prof) override;
    void toExpr() const override;

protected:
    int prof;
    Gate* left;
    Gate* right;
};

#endif //TWOINPUTGATE_HPP

