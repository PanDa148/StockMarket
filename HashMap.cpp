#include "HashMap.h"
#include <iostream>

HashMap::Pair::Pair(double k, int v) : key(k), value(v) {}

void HashMap::Pair::print() {
    std::cout<<"($"<<key<<", "<<value<<") ";
}

void HashMap::Pair::updateValue(int v) {
    value=v;
}

HashMap::HashMap(int ms) : minSize(ms), size(ms), numFilled(0)  {
    for (int i=0; i<size; i++) {
        prices.push_back({NULL});
    }
};

HashMap::HashMap() : HashMap(10) {}

HashMap::~HashMap() {
    for (int i=0; i<size; i++) {
        if (prices[i][0]!=NULL) {
            for (int j=0; j<prices[i].size(); j++) {
                delete prices[i][j];
            }
        }
    }
}

int HashMap::hash(double price) {
    //std::cout<<"Hashing\n";
    int t1 = price;
    int t2 = price*10;
    int t3 = price*100;
    int temp = t1+t2+t3;
    //std::cout<<"Hashed to "<<temp%size<<"\n";
    return temp % size;
}

void HashMap::insert(double price, int index) {
    if (contains(price)==-1) {
        int i = hash(price);
        if (prices[i][0]==NULL) {
            prices[i][0]=new Pair(price,index);
            numFilled++;
        }
        else {
            prices[i].push_back(new Pair(price,index));
        }
    }
    else {
        std::cout<<"Error: "<<price<<" is already in the map\n";
    }
    fixSize();
}

void HashMap::print() {
    for (int i=0; i<size; i++) {
        if (prices[i][0]!=NULL) {
            std::cout<<i<<": ";
            for (int j=0;j<prices[i].size(); j++) {
                prices[i][j]->print();
            }
            std::cout<<"\n";
        }
    }
    std::cout<<"\n";
}

int HashMap::contains(double price) {
    //std::cout<<"c\n";
    //std::cout<<"Contains: ";
    //std::cout<<price<<"\n";
    //std::cout<<"d\n";
    int i = hash(price);
    //std::cout<<"e\n";
    if (prices[i][0]==NULL) {
        //std::cout<<"f\n";
        return -1;
    }
   // std::cout<<"g\n";
    for (int j=0; j<prices[i].size(); j++) {
       // std::cout<<"h\n";
        if (prices[i][j]->key==price) {
           // std::cout<<"i\n";
            return i;
        }
        //std::cout<<"j\n";
    }
   // std::cout<<"k\n";
    return -1;
}

int HashMap::find(double price, int i) {
    int j=0;
    while (prices[i][j]->key!=price) {
        j++;
    }
    return j;
}

int HashMap::indexOf(double price) {
   // std::cout<<"v\n";
    int i = contains(price);
    //std::cout<<"w\n";
    if (i==-1) {
       // std::cout<<"x\n";
        std::cout<<"Error: "<<price<<" is not in the map\n";
        //std::cout<<"z\n";
        return -1;
    }
   // std::cout<<"A\n";
    return prices[i][find(price,i)]->value;
}

void HashMap::remove(double price) {
    int i = contains(price);
    if (i==-1) {
        std::cout<<"Error: "<<price<<" is not in the map\n";
    } else {
        int j=find(price,i);
        Pair* p = prices[i][j];
        delete p;
        prices[i][j]=NULL;
        if (prices[i].size()>1) {
            prices[i].erase(prices[i].begin()+j);
        } else {
            numFilled--;
            fixSize();
        }
    }
}

void HashMap::fixSize() {
    double loadFactor=(double) numFilled/ (double) size;
    int oldSize=size;
    if (loadFactor>0.75) {
        size*=2;
    } else if (size>minSize && loadFactor<0.25) {
        size/=2;
    }
    if (oldSize!=size) {
        std::cout<<"Fixing size\n";
        std::vector<std::vector<Pair*>> temp;
        for (int i=0; i<size; i++) {
            temp.push_back({NULL});
        }
        for (int i=0; i<oldSize; i++) {
            if (prices[i][0]!=NULL) {
                for (int j=0; j<prices[i].size(); j++) {
                    int h = hash(prices[i][j]->key);
                    if (temp[h][0]==NULL) {
                        temp[h][0]=prices[i][j];
                    }
                    else {
                        temp[h].push_back(prices[i][j]);
                    }
                }
            }
        }
        prices=temp;
        //std::cout<<"Done\n";
    }
}

void HashMap::printInfo() {
    std::cout<<"minSize: "<<minSize<<"\n";
    std::cout<<"size: "<<size<<"\n";
    std::cout<<"numFilled: "<<numFilled<<"\n";
}

void HashMap::updateIndex(double price, int index) {
    int i = contains(price);
    if (i==-1) {
        std::cout<<"Error: "<<price<<" is not in the map\n";
    } else {
        prices[i][find(price,i)]->updateValue(index);
    }
}