#include "Lista.h"

Lista::Lista() {
    // Empty constructor
}

void Lista::insert(int value) {
    data[size] = value;
    size++;
}

void Lista::erase() {
    if (size > 0) {
        cout << data[-1] << endl;
        data[-1] = 0;
        size--;
    } else {
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

int Lista::getData(int position) {
    return data[position];
}

int Lista::getSize() {
    return size;
}

void Lista::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << endl;
    }
}
