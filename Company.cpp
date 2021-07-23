#include "Company.h"
#include <iostream>

Company::Company(std::string n)
    : name(n)
{}

void Company::print() {
    std::cout<<name<<"\n";
	std::cout<<"Buy price: $"<<me.buyPrice()<<"\n";
	std::cout<<"Sell price: $"<<me.sellPrice()<<"\n";
}

std::string Company::getName() {
    return name;
}
