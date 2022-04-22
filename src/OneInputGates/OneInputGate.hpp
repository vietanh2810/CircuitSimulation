#ifndef ONEINPUTGATE_HPP
#define ONEINPUTGATE_HPP

#include "../Gate.hpp"
#include "../InputGate.hpp"
#include "../OutputGate.hpp"
#include <string>
#include <vector>

class OneInputGate : public Gate{
public:
    //constructor
    OneInputGate(Gate* in = nullptr);
    //getters
    Gate* getGate() const;
    int getProf() const {return this->prof;};
    //setter
    void setProf(int prof) override {this->prof = prof;};
    //others functions
    void empileGates(int prof) override;
    vector<string> plot(int space,int size, vector<string> m) override;
    void toExpr() const override;

protected:
    int prof;
    string gate_name;
    Gate* in;
};

#endif //ONEINPUTGATE_HPP
