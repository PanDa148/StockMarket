#pragma once
#include "Order.h"

class LimitOrder : public Order{
    public:
    LimitOrder(std::string on, double pr, int q, bool b);
    LimitOrder(std::string on,Person* p, double pr, int q, bool b);
    void print();
    void printName();
    void printString();
    std::string csvString();
};