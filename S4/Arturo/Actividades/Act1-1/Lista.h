#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

class Lista {
    private:
        static const int MAX = 100;
        int data[MAX];
        int size = 0;
    public:
        Lista();
        void insert(int);
        void erase();
        int getData(int position);
        int getSize();
        void print();
        void add(int value); // New method
        void remove(int value); // New method
        bool contains(int value); // New method
};

#endif // LISTA_H
