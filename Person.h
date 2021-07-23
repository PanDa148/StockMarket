#pragma once
#include <string>

class Person {
    public:
    std::string name;
    double money;

    Person(std::string n, double m) : name(n), money(m) {};
    void print();
};