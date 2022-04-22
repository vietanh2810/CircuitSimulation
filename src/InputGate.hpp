#ifndef INPUTGATE_HPP
#define INPUTGATE_HPP

#include "Gate.hpp"
#include "OutputGate.hpp"

class InputGate : public Gate {
public:
    InputGate(char a); //basic constructor
    //getters
    char getName() const {return name;};
    int getProf() const {return this->prof;};
    //setters
    void setVal(bool a); //change the value of the input
    void setProf(int prof) override {this->prof = prof;};
    //orthers functions
    bool eval() const override; //simply return the value since it's an inputgate
    void empileGates(int prof) override;
    string toString() const override;
    vector<string> plot(int space,int size,vector<string> m) override;
    void toExpr() const override;

protected:
    int prof;
    bool value;
    char name;
};

std::ostream &operator<<(std::ostream &out, const InputGate *g);

#endif //INPUTGATE_HPP
