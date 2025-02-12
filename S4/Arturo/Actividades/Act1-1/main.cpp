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

    // Test add
    lista.add(40);
    lista.print(); // Expected output: 10 20 40

    // Test remove
    lista.remove(20);
    lista.print(); // Expected output: 10 40

    // Test contains
    cout << "Contains 10: " << lista.contains(10) << endl; // Expected output: Contains 10: 1
    cout << "Contains 20: " << lista.contains(20) << endl; // Expected output: Contains 20: 0

    return 0;
}
