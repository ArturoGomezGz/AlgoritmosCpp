#include "Lista.h"

int main() {
    Lista lista;

    // Test insert and print
    lista.insert(10);
    lista.insert(20);
    lista.insert(30);
    lista.print(); // Expected output: 10 20 30

    // Test getSize
    cout << "Size: " << lista.getSize() << endl; // Expected output: Size: 3

    // Test getData
    cout << "Data at position 1: " << lista.getData(1) << endl; // Expected output: Data at position 1: 20

    // Test erase
    lista.erase();
    lista.print(); // Expected output: 10 20
    return 0;
}
