#pragma once
#include <vector>

class HashMap {
    private:
    class Pair {
        public:
        double key;
        int value;

        Pair(double k, int v);
        void updateValue(int v);
        void print();
    };

    std::vector<std::vector<Pair*>> prices;
    int minSize;
    int size;
    int numFilled;
    int hash(double price);
    void fixSize();
    int find(double price, int i);

    public:
    HashMap(int ms);
    HashMap();
    ~HashMap();
    void insert(double price, int index);
    int contains(double price);
    int indexOf(double price);
    void remove(double price);
    void updateIndex(double price, int index);
    void print();
    void printInfo();
};