all: clean matchingengine

matchingengine: Company HashMap LimitOrder MarketOrder MatchingEngine Order OrderBook Person main
	g++ -std=c++17 Company.o HashMap.o LimitOrder.o MarketOrder.o MatchingEngine.o Order.o OrderBook.o Person.o main.o -o matchingengine

Company: Company.cpp
	g++ -c -std=c++17 Company.cpp

HashMap: HashMap.cpp
	g++ -c -std=c++17 HashMap.cpp

LimitOrder: LimitOrder.cpp
	g++ -c -std=c++17 LimitOrder.cpp

MarketOrder: MarketOrder.cpp
	g++ -c -std=c++17 MarketOrder.cpp

MatchingEngine: MatchingEngine.cpp
	g++ -c -std=c++17 MatchingEngine.cpp

Order: Order.cpp
	g++ -c -std=c++17 Order.cpp

OrderBook: OrderBook.cpp
	g++ -c -std=c++17 OrderBook.cpp

Person: Person.cpp
	g++ -c -std=c++17 Person.cpp

main: main.cpp
	g++ -c -std=c++17 main.cpp

clean:
	rm -rf *o matchingengine
