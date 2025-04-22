#include <iostream>
#include <vector>
#include "BST.cpp"

using namespace std;

void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Crear y llenar el primer BST
    BST<int> bst1;
    cout << "Insertando elementos en el BST1: 10, 5, 15, 3, 7, 12, 20" << endl;
    bst1.insert(10);
    bst1.insert(5);
    bst1.insert(15);
    bst1.insert(3);
    bst1.insert(7);
    bst1.insert(12);
    bst1.insert(20);
    
    // Demostrar minDifference
    cout << "\n--- Demostración de minDifference ---" << endl;
    try {
        int minDiff = bst1.minDifference();
        cout << "La diferencia mínima entre nodos del BST1 es: " << minDiff << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Demostrar whatLevelAmI
    cout << "\n--- Demostración de whatLevelAmI ---" << endl;
    cout << "Nivel del valor 10: " << bst1.whatLevelAmI(10) << endl;
    cout << "Nivel del valor 3: " << bst1.whatLevelAmI(3) << endl;
    cout << "Nivel del valor 20: " << bst1.whatLevelAmI(20) << endl;
    cout << "Nivel del valor 100: " << bst1.whatLevelAmI(100) << " (no existe en el árbol)" << endl;
    
    // Demostrar ancestors
    cout << "\n--- Demostración de ancestors ---" << endl;
    cout << "Ancestros del valor 7: ";
    bst1.ancestors(7);
    
    cout << "Ancestros del valor 20: ";
    bst1.ancestors(20);
    
    cout << "Ancestros del valor 10: ";
    bst1.ancestors(10);
    
    cout << "Ancestros del valor 100: ";
    bst1.ancestors(100);
    
    // Crear un segundo BST para demostrar intersection
    BST<int> bst2;
    cout << "\nInsertando elementos en el BST2: 15, 7, 25, 3, 9, 20, 30" << endl;
    bst2.insert(15);
    bst2.insert(7);
    bst2.insert(25);
    bst2.insert(3);
    bst2.insert(9);
    bst2.insert(20);
    bst2.insert(30);
    
    // Demostrar intersection
    cout << "\n--- Demostración de intersection ---" << endl;
    vector<int> intersect = bst1.intersection(bst2);
    cout << "Intersección entre BST1 y BST2: ";
    printVector(intersect);
    
    // Demostrar con un BST vacío
    BST<int> emptyBST;
    cout << "\nIntersección entre BST1 y un BST vacío: ";
    printVector(bst1.intersection(emptyBST));
    
    return 0;
}