#pragma once
#include "Company.h"

class Market {
	private:
	std::vector<Company*> companies;

	public:
	Market(){};
	~Market();
	void addCompany(std::string name);
	void placeOrder(Person* p, std::vector<std::string>& args);
};
