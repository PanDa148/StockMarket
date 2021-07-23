#include "LimitOrder.h"

LimitOrder::LimitOrder(std::string on, double pr, int q, bool b)
    : Order(on, q, b)
{}

LimitOrder::LimitOrder(std::string on,Person* p, double pr, int q, bool b)
    : Order(on, p, q, b)
{
    price=pr;
}

void LimitOrder::print() {
    std::cout<<"Limit ";
    Order::print();
    std::cout<<"Price: $"<<price<<"\n\n";
}

void LimitOrder::printName() {
    std::cout<<orderName<<"\n";
}

void LimitOrder::printString() {
    std::cout<<"("<<orderName<<", "<<price<<")";
}

std::string LimitOrder::csvString() {
    std::stringstream csvData;
    csvData<<"limit"<<Order::csvString()<<",$"<<price<<"\n";
    return csvData.str();
}
