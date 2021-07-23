#pragma once
#include "LimitOrder.h"
#include <vector>
#include "HashMap.h"

class OrderBook {
    private:
    std::vector<std::vector<LimitOrder*>> orders;
    bool buy;
    void swap(int x, int y);
    static int parent (int i);
    static int left(int i);
    static int right (int i);
    void heapify(int i);
    void updateIndex(int i);
    void remove(int i);
    bool lessThan(int i, int j);
    bool greaterThan(int i, int j);

    public:
    HashMap map;
    OrderBook(bool b);
	~OrderBook();
    LimitOrder* peek();
    LimitOrder* poll();
    void cancel(LimitOrder* lo);
    void insert(LimitOrder* lo);
    void printAllOrders();
    void changePrice(LimitOrder* lo, double newPrice);
    bool isEmpty();
};
