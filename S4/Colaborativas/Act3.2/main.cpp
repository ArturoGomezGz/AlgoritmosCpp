#include <iostream>
#include <vector>
#include "MaxHeap.cpp"

using namespace std;

int main() {

    // Prueba 1: Constructor con vector y heapify
    cout << "Prueba 1: Constructor y heapify" << endl;
    vector<int> arr = {4, 10, 3, 5, 1, 8};
    cout << "Vector original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    MaxHeap heap1(arr);
    cout << "Elementos del heap (extrayendo uno a uno): ";
    while (!heap1.empty()) {
        cout << heap1.pop() << " ";
    }
    cout << endl << endl;

    // Prueba 2: Método push
    cout << "Prueba 2: Método push" << endl;
    vector<int> arr2 = {};
    MaxHeap heap2(arr2);
    cout << "Insertando elementos: 7, 3, 9, 1, 5" << endl;
    heap2.push(7);
    heap2.push(3);
    heap2.push(9);
    heap2.push(1);
    heap2.push(5);
    
    cout << "Elementos del heap (extrayendo uno a uno): ";
    while (!heap2.empty()) {
        cout << heap2.pop() << " ";
    }
    cout << endl << endl;

    // Prueba 3: Método top
    cout << "Prueba 3: Método top" << endl;
    vector<int> arr3 = {15, 8, 10, 3, 7};
    MaxHeap heap3(arr3);
    cout << "Heap creado con: 15, 8, 10, 3, 7" << endl;
    cout << "Elemento máximo (usando top): " << heap3.top() << endl;
    cout << "Verificando que top no elimina el elemento..." << endl;
    cout << "Elemento máximo después de top: " << heap3.top() << endl << endl;

    // Prueba 4: Método empty y getCurrentSize
    cout << "Prueba 4: Métodos empty y getCurrentSize" << endl;
    cout << "¿El heap está vacío? " << (heap3.empty() ? "Sí" : "No") << endl;
    cout << "Tamaño actual del heap: " << heap3.getCurrentSize() << endl;
    
    cout << "Extrayendo todos los elementos..." << endl;
    while (!heap3.empty()) {
        heap3.pop();
    }
    
    cout << "¿El heap está vacío ahora? " << (heap3.empty() ? "Sí" : "No") << endl;
    cout << "Tamaño actual del heap: " << heap3.getCurrentSize() << endl << endl;

    // Prueba 5: Método mezclar
    cout << "Prueba 5: Método mezclar" << endl;
    vector<int> arr4 = {20, 10, 5};
    vector<int> arr5 = {15, 7, 12};
    
    MaxHeap heap4(arr4);
    MaxHeap heap5(arr5);
    
    cout << "Heap 1 creado con: 20, 10, 5" << endl;
    cout << "Heap 2 creado con: 15, 7, 12" << endl;
    
    heap4.mezclar(heap5);
    
    cout << "Después de mezclar, elementos del heap resultante: ";
    while (!heap4.empty()) {
        cout << heap4.pop() << " ";
    }
    cout << endl << endl;

    // Prueba de casos borde
    cout << "Prueba 6: Casos borde" << endl;
    vector<int> arr6 = {};
    MaxHeap heap6(arr6);
    
    cout << "Prueba con heap vacío:" << endl;
    cout << "Intentando hacer pop en heap vacío: " << heap6.pop() << endl;
    cout << "Intentando obtener top en heap vacío: " << heap6.top() << endl;
    
    // Prueba con un solo elemento
    cout << "Prueba con un solo elemento:" << endl;
    heap6.push(42);
    cout << "Elemento insertado: 42" << endl;
    cout << "Top del heap: " << heap6.top() << endl;
    cout << "Pop del heap: " << heap6.pop() << endl;
    cout << "¿El heap está vacío? " << (heap6.empty() ? "Sí" : "No") << endl;

    return 0;
}
