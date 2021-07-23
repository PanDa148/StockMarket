#include <iostream>
#include "Company.h"
#include <cstdlib>
#include <vector>
#include <fstream>

void testOrderBook() {
    LimitOrder a ("a",5.1,10,0);
    LimitOrder b ("b",5.1,2,0);
    LimitOrder c ("c",10.5,3,0);
    LimitOrder d ("d",4.3,2,0);
    LimitOrder e ("e",1.1,10,0);
    LimitOrder f ("f",20,5,0);
    LimitOrder g ("g",10.5,9,0);
    LimitOrder h ("h",20,10,0);
    LimitOrder i ("i",5.7,2,0);
    LimitOrder j ("j",1.0,3,0);
    LimitOrder k ("k",100,2,0);
    LimitOrder l ("l",7.5,10,0);
    LimitOrder m ("m",20,5,0);
    LimitOrder n ("n",11.3,9,0);
    LimitOrder o ("o",5.0,10,0);
    LimitOrder p ("p",5.1,2,0);
    LimitOrder q ("q",10.2,3,0);
    LimitOrder r ("r",4.3,2,0);
    LimitOrder s ("s",1.4,10,0);
    LimitOrder t ("t",20.5,5,0);
    LimitOrder u ("u",10.6,9,0);
    LimitOrder v ("v",20.7,10,0);
    LimitOrder w ("w",5.8,2,0);
    LimitOrder x ("x",1.9,3,0);
    LimitOrder y ("y",101,2,0);
    LimitOrder z ("z",7.59,10,0);
    LimitOrder A ("A",20.01,5,0);
    LimitOrder B ("B",11.35,9,0);
    LimitOrder* orders [] = {&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z,&A,&B};
    int num = sizeof(orders)/sizeof(LimitOrder*);

    OrderBook orderbook1 (0);
    for (int i=0; i<num; i++) {
        orderbook1.insert(orders[i]);
    }
    orderbook1.printAllOrders();
    orderbook1.map.print();
    orderbook1.map.printInfo();
    for (int i=0; i<num; i++) {
        std::cout<<orderbook1.poll()->getName()<<" ";
    }
    for (int i=0; i<num; i++) {
        orderbook1.insert(orders[i]);
    }
    for (int i=0; i<num; i++) {
        orderbook1.cancel(orders[i]);
    }
    orderbook1.printAllOrders();
    orderbook1.map.print();
    orderbook1.map.printInfo();
}

void generateRandom(std::vector<Person*>& people, std::vector<LimitOrder*>& orders, int num) {
    int i = 0;
    while (i<num) {
        double price = (double) (rand() % 9999 + 1) / 100;
        int quantity = rand() % 20 + 1;
        int person = rand() % people.size();
        int buy = rand() % 2;
        orders.push_back(new LimitOrder(std::string(1,(char)(i+65)),people[person], price, quantity, buy));
        i++;
    }
}

void testMatchingEngine(std::vector<LimitOrder*>& orders) {
    MatchingEngine m;
    for (int i=0; i<orders.size(); i++) {
        m.add(orders[i]);
        m.print();
    }
}

void writeCSV(std::vector<LimitOrder*>& orders) {
    std::ofstream limOrders("LimitOrders.csv");
    limOrders<<"Order type,order name,buy/sell,person name,quantity,price (if applicable)\n";
	for (int i=0; i<orders.size(); i++) {
        limOrders<<orders[i]->csvString();
    }
    limOrders.close();
}

void readCSV() {

}

void testWriteCSV() {
    std::vector<LimitOrder*> orders;
    Person p1("p1",100);
    Person p2("p2",100);
    Person p3("p3",100);
    std::vector<Person*> people = {&p1, &p2, &p3};
    generateRandom(people, orders, 20);

    writeCSV(orders);

    for (int i=0; i<orders.size(); i++) {
        delete orders[i];
    }
}

int main() {
	Person p1("Daisy");
	Person p2("Donald");
	Person p3("Mickey");
	Person p4("Minnie");
	Company c1("Amazon");
	Company c2("Google");
	Company c3("Apple");
	
}
