#include "Order.h"

Order::Order(std::string on, int q, bool b) 
    : orderName(on)
    , person(NULL)
    , quantity(q)
    , buy(b)
    , price(0)
{}

Order::Order(std::string on, Person* p,int q, bool b) 
    : Order(on,q,b)
{
    person = p;
}

void Order::print() {
    if (buy) {
        std::cout<<"Buy";
    }
    else {
        std::cout<<"Sell";
    }
    std::cout<<" order: "<<orderName<<"\n";
    if (person!=NULL) {
        std::cout<<person->name<<"\n";
    }
    std::cout<<"Quantity: "<<quantity<<"\n";
}

std::string Order::getName() {
    return orderName;
}

std::string Order::csvString() {
    std::stringstream csvData;
    csvData<<","<<orderName<<","<<(buy ? "buy" : "sell")<<","<<person->name<<","<<quantity;
    return csvData.str();
}
