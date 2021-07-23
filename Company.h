#pragma once
#include <string>
#include "MatchingEngine.h"

class Company {
    private:
    std::string name;

    public:
    double marketPrice;
    Company(std::string n);
    void print();
    std::string getName();
};
