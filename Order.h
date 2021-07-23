#pragma once
#include <string>
#include "Person.h"
#include <iostream>
#include <sstream>

class Order {
    protected:
    std::string orderName;

    public:
    bool buy;
    int quantity;
    double price;
    Person* person;
    Order(std::string orderName, int q, bool b);
    Order(std::string orderName,Person* p, int q, bool b);
    virtual void print();
    std::string getName();
    virtual std::string csvString();
};