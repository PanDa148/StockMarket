#pragma once
#include "OrderBook.h"
#include "MarketOrder.h"

class MatchingEngine {
    private:
    OrderBook buyOrders;
    OrderBook sellOrders;
    void matchLimitOrders();
    void trade(Order* o1, Order* o2);
	void poll(bool buy);
    
    public:
    MatchingEngine();
    double buyPrice();
    double sellPrice();
    void add(MarketOrder* mo);
    void add(LimitOrder* lo);
    void print();
};
