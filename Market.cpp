#include "Market.h"

Market::~Market() {
	for (int i=0; i<companies.size(); i++) {
		delete companies[i];
	}
}

void Market::addCompany(std::string name) {
	companies.push_back(new Company(name));
}
// args: companyName, orderName, orderType, buy/sell, quantity, price(if applicablei)
void Market::placeOrder(Person* p, std::vector<std::string>& args) {
	
}
