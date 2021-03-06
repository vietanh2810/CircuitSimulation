
#ifndef GATE_HPP
#define GATE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

class Gate{
public:
    virtual ~Gate();
    virtual void empileGates(int prof) = 0;
    virtual string toString() const = 0;
    virtual bool eval() const = 0;
    virtual void setProf(int a) = 0;
    virtual vector<string> plot(int space,int size,vector<string> m) = 0;
    virtual void toExpr() const = 0;
};

template <typename T> vector<T> concat(vector<T> &a, vector<T> &b) {
    vector<T> ret = vector<T>();
    copy(a.begin(), a.end(), back_inserter(ret));
    copy(b.begin(), b.end(), back_inserter(ret));
    return ret;
}

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i]->toString();
        if (i != last) 
            out << ", ";
    }
    out << "}";
    return out;
}

#endif //GATE_HPP
