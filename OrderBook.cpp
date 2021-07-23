#include "OrderBook.h"
#include <iostream>

OrderBook::OrderBook(bool b) 
    : buy(b)
{}

OrderBook::~OrderBook() {
	for (int i=0; i<orders.size(); i++) {
		for (int j=0; j<orders[i].size(); j++) {
			if (orders[i][j]!=NULL) {
				delete orders[i][j];
			}
		}
	}
}

void OrderBook::updateIndex(int i) {
    double p = orders[i][0]->price;
    if (map.contains(p)!=-1) {
        map.updateIndex(p,i);
    }
}

void OrderBook::swap(int x, int y) {
    //std::cout<<"Swapping "<<orders[x]->getName()<<" and "<<orders[y]->getName()<<"\n";
    std::vector<LimitOrder*> temp = orders[x];
    orders[x]=orders[y];
    orders[y]=temp;
    updateIndex(x);
    updateIndex(y);
}

int OrderBook::parent(int i) {
    return (i-1)/2;
}

int OrderBook::left(int i) {
    return (2*i +1);
}

int OrderBook::right(int i) {
    return (2*i +2);
}

LimitOrder* OrderBook::peek() {
    return orders[0][0];
}

bool OrderBook::lessThan(int i, int j) {
    if (buy) {
        return orders[i][0]->price>orders[j][0]->price;
    } else {
        return orders[i][0]->price<orders[j][0]->price;
    }
}

bool OrderBook::greaterThan(int i, int j) {
    if (buy) {
        return orders[i][0]->price<orders[j][0]->price;
    } else {
        return orders[i][0]->price>orders[j][0]->price;
    }
}

void OrderBook::insert(LimitOrder* lo) {
    //std::cout<<"Inserting "<<lo->getName()<<":\n";
    if (lo->buy!=buy) {
        std::cout<<"Error: buy is not the same\n";
        return;
    }
    int f = map.contains(lo->price);
    if (f==-1) {
        int i = orders.size();
        map.insert(lo->price,i);
        orders.push_back({lo});
        updateIndex(i);
        while (i != 0  && greaterThan(parent(i),i)) {
            swap(i, parent(i));
            i=parent(i);
        }
    } else {
        orders[map.indexOf(lo->price)].push_back(lo);
    }
}

void OrderBook::printAllOrders() {
    for (int i=0; i<orders.size(); i++) {
        for (int j=0; j<orders[i].size(); j++) {
            std::cout<<"("<<orders[i][j]->getName()<<", "<<orders[i][j]->price<<") ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void OrderBook::heapify(int i) {
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if (l<orders.size() && lessThan(l,i)) {
        smallest=l;
    }
    if (r<orders.size() && lessThan(r,smallest)) {
        smallest=r;
    }
    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}

LimitOrder* OrderBook::poll() {
    //std::cout<<"Polling: ";
    if (orders.size()<=0) {
        std::cout<<"Error: OrderBook is empty\n";
        return NULL;
    }
    LimitOrder* root=orders[0][0];
    orders[0].erase(orders[0].begin());
    if (orders[0].size()==0) {
        orders[0] = orders.back();
        updateIndex(0);
        orders.pop_back();
        heapify(0);
    }
    return root;
}

void OrderBook::remove(int i) {
    while (i!=0 && greaterThan(parent(i),i)) {
        swap(i,parent(i));
        i = parent(i);
    }
}

void OrderBook::cancel(LimitOrder* lo) {
    std::cout<<"Canceling "<<lo->getName()<<"\n";
    int i = map.indexOf(lo->price);
    if (i==-1) {
        std::cout<<lo->getName()<<" is not in this orderbook\n";
        return;
    }
    if (orders[i].size()>1) {
        int j=0;
        while (orders[i][j]!=lo) {
            j++;
        }
        orders[i].erase(orders[i].begin()+j);
    } else {
        map.remove(lo->price);
        lo->price = orders[0][0]->price-1+2*buy;
        remove(i);
        poll();
    }
}

void OrderBook::changePrice(LimitOrder* lo, double newPrice) {
    cancel(lo);
    lo->price=newPrice;
    insert(lo);
}

bool OrderBook::isEmpty() {
    return orders.size()==0;
}
