#pragma once
#include "Order.h"
#include "Company.h"

class MarketOrder : public Order {
    public:
    MarketOrder(std::string on, int q, bool b);
    MarketOrder(std::string on, Person* p, int q, bool b);
    void print();
    std::string csvString();
};