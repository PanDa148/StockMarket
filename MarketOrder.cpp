#include "MarketOrder.h"

MarketOrder::MarketOrder(std::string on, int q, bool b)
    : Order(on,q,b)
{}

MarketOrder::MarketOrder(std::string on, Person* p, int q, bool b)
    : Order(on,p,q,b)
{}

void MarketOrder::print() {
    std::cout<<"Market ";
    Order::print();
    std::cout<<"\n";
}

std::string MarketOrder::csvString() {
    std::stringstream csvData;
    csvData<<"market"<<Order::csvString()<<"\n";
    return csvData.str();
}
