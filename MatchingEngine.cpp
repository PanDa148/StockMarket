#include "MatchingEngine.h"
#include <iostream>

MatchingEngine::MatchingEngine() : buyOrders(1), sellOrders(0) {}

double MatchingEngine::buyPrice() {
    return buyOrders.peek()->price;
}

double MatchingEngine::sellPrice() {
    return sellOrders.peek()->price;
}

/*void MatchingEngine::trade(MarketOrder* mo, LimitOrder* lo) {
    int q = tradeQuantity(mo,lo);
    double price = lo->price;
    mo->quantity-=q;
    lo->quantity-=q;
    int mult = mo->buy ? -1 : 1;
    std::cout<<"Traded "<<q<<" of "<<mo->getName()<<" and "<<lo->getName()<<" @ $"<<price<<"\n";
    
}*/

void MatchingEngine::trade(Order* o1, Order* o2) {
    int q = o1->quantity<=o2->quantity ? o1->quantity : o2->quantity;
    double price = o2->price;
    o1->quantity-=q;
    o2->quantity-=q;
    int mult = o1->buy ? -1 : 1;
    std::cout<<"Traded "<<q<<" of "<<o1->getName()<<" and "<<o2->getName()<<" @ $"<<price<<"\n";
}

void MatchingEngine::poll(bool buy) {
	LimitOrder* lo = buy ? buyOrders.poll() : sellOrders.poll();
	delete lo;
}

void MatchingEngine::matchLimitOrders() {
    while (!buyOrders.isEmpty() && !sellOrders.isEmpty() && buyPrice()>=sellPrice()) {
        LimitOrder* l1 = sellOrders.peek();
        LimitOrder* l2 = buyOrders.peek();
        trade(l1,l2);
        if (l1->quantity==0) {
			poll(0);
			delete l1;
        }
        if (l2->quantity==0) {
			poll(1);
			delete l2;
        }
    }
}

void MatchingEngine::add(MarketOrder* mo) {
    OrderBook& orders = mo->buy ? sellOrders : buyOrders;
    while (mo->quantity>0) {
        LimitOrder* lo = orders.peek();
        trade(mo,lo);
        if (lo->quantity==0) {
            orders.poll();
        }
    }
	delete mo;
    matchLimitOrders();
}

void MatchingEngine::add(LimitOrder* lo) {
    OrderBook& orders = lo->buy ? buyOrders : sellOrders;
    orders.insert(lo);
    matchLimitOrders();
}

void MatchingEngine::print() {
    std::cout<<"Printing matching engine:\n";
    std::cout<<"Buy orders:\n";
    buyOrders.printAllOrders();
    std::cout<<"Sell orders:\n";
    sellOrders.printAllOrders();
}
