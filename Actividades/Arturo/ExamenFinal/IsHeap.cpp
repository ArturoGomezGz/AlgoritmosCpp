#include <iostream>
#include <vector>

using namespace std;

bool isHeapRec(vector<int>& arreglo, int i) {
    int size = arreglo.size();

    // El elemento es una hoja, hasta aqui llegó 
    if (i >= (size - 2) / 2) {
        return true;
    }

    bool left = (2 * i + 1 < size && arreglo[i] >= arreglo[2 * i + 1]);
    bool right = (2 * i + 2 >= size || arreglo[i] >= arreglo[2 * i + 2]);

    return 
        left && 
        right &&
        isHeapRec(arreglo, 2 * i + 1) &&
        isHeapRec(arreglo, 2 * i + 2);
}

bool isHeap(vector<int>& arreglo) {
    return isHeapRec(arreglo, 0);
}

int main() {
    vector<int> siHeap = {50, 30, 40, 10, 20, 35, 38, 5, 8, 15};
    vector<int> noHeap = {50, 30, 40, 10, 60, 35, 38, 5, 8, 15};

    if (isHeap(siHeap)) {
        cout << "El arreglo SI es un maxHeap " << endl;
    } else {
        cout << "El arreglo NO es un maxHeap " << endl;
    }

    if (isHeap(noHeap)) {
        cout << "El arreglo SI es un maxHeap " << endl;
    } else {
        cout << "El arreglo NO es un maxHeap " << endl;
    }

    return 0;
}
