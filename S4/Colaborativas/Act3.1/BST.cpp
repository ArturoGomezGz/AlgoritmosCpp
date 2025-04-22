#ifndef BST_CPP
#define BST_CPP

#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

using namespace std;

template <typename T>
class Node {
public:
    T valor;
    Node* left;
    Node* right;

    Node(T valor) : valor(valor), left(nullptr), right(nullptr) {}

    void print() const {
        cout << valor << " ";
    }
};

template <typename T>
class BST {
private:
    Node<T>* root;
    int size;

    int insertRec(Node<T>* current, Node<T>* newNode);
    bool searchRec(Node<T>* current, T valor) const;
    bool ancestorsRec(Node<T>* current, T valor);
    int whatLevelAmIRec(Node<T>* current, T valor, int nivel);
    void storeInorder(Node<T>* current, vector<T>& values);
    void findIntersection(Node<T>* current, const BST<T>& otherBST, vector<T>& result) const;

public:
    BST();
    int insert(T valor);
    bool search(T valor) const;
    bool isEmpty() const;
    T minDifference();
    int whatLevelAmI(T valor);
    void ancestors(T valor);
    vector<T> intersection(const BST<T>& otherBST);
};

template <typename T>
BST<T>::BST() {
    this->root = nullptr;
    this->size = 0;
}

template <typename T>
int BST<T>::insert(T valor) {
    Node<T>* newNode = new Node<T>(valor);
    if (this->root == nullptr) {
        this->root = newNode;
        this->size++;
        return 1;
    }
    return insertRec(this->root, newNode);
}

template <typename T>
bool BST<T>::search(T valor) const {
    return searchRec(this->root, valor);
}

template <typename T>
bool BST<T>::isEmpty() const {
    return this->root == nullptr;
}

template <typename T>
T BST<T>::minDifference() {
    if (isEmpty()) {
        throw invalid_argument("El BST está vacío");
    }
    
    if (size == 1) {
        throw invalid_argument("El BST solo tiene un nodo");
    }
    
    vector<T> values;
    storeInorder(this->root, values);
    
    T minDiff = numeric_limits<T>::max();
    for (size_t i = 1; i < values.size(); i++) {
        T diff = values[i] - values[i-1];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    return minDiff;
}

template <typename T>
int BST<T>::whatLevelAmI(T valor) {
    return whatLevelAmIRec(this->root, valor, 1);
}

template <typename T>
void BST<T>::ancestors(T valor) {
    if (root == nullptr) {
        cout << "El árbol está vacío" << endl;
        return;
    }
    
    if (root->valor == valor) {
        cout << "El valor es la raíz, no tiene ancestros" << endl;
        return;
    }
    
    if (!search(valor)) {
        cout << "El valor no existe en el árbol" << endl;
        return;
    }
    
    if (!ancestorsRec(root, valor)) {
        cout << "El valor no tiene ancestros" << endl;
    }
    cout << endl;
}

template <typename T>
vector<T> BST<T>::intersection(const BST<T>& otherBST) {
    vector<T> result;
    
    if (this->isEmpty() || otherBST.isEmpty()) {
        return result;
    }
    
    findIntersection(this->root, otherBST, result);
    
    return result;
}

template <typename T>
int BST<T>::insertRec(Node<T>* current, Node<T>* newNode) {
    if (newNode->valor == current->valor) {
        delete newNode;
        return 0;
    }
    
    if (newNode->valor < current->valor) {
        if (current->left == nullptr) {
            current->left = newNode;
            this->size++;
            return 1;
        }
        return insertRec(current->left, newNode);
    } else {
        if (current->right == nullptr) {
            current->right = newNode;
            this->size++;
            return 1;
        }
        return insertRec(current->right, newNode);
    }
}

template <typename T>
bool BST<T>::searchRec(Node<T>* current, T valor) const {
    if (current == nullptr) {
        return false;
    }
    
    if (valor == current->valor) {
        return true;
    }
    
    if (valor < current->valor) {
        return searchRec(current->left, valor);
    } else {
        return searchRec(current->right, valor);
    }
}

template <typename T>
bool BST<T>::ancestorsRec(Node<T>* current, T valor) {
    if (current == nullptr || current->valor == valor) {
        return false;
    }
    
    if ((current->left != nullptr && current->left->valor == valor) || 
        (current->right != nullptr && current->right->valor == valor)) {
        current->print();
        return true;
    }
    
    bool found = false;
    if (valor < current->valor) {
        found = ancestorsRec(current->left, valor);
    } else {
        found = ancestorsRec(current->right, valor);
    }
    
    if (found) {
        current->print();
        return true;
    }
    
    return false;
}

template <typename T>
int BST<T>::whatLevelAmIRec(Node<T>* current, T valor, int nivel) {
    if (current == nullptr) {
        return -1;
    }
    
    if (current->valor == valor) {
        return nivel;
    }
    
    if (valor < current->valor) {
        return whatLevelAmIRec(current->left, valor, nivel + 1);
    } else {
        return whatLevelAmIRec(current->right, valor, nivel + 1);
    }
}

template <typename T>
void BST<T>::storeInorder(Node<T>* current, vector<T>& values) {
    if (current == nullptr) {
        return;
    }
    
    storeInorder(current->left, values);
    values.push_back(current->valor);
    storeInorder(current->right, values);
}

template <typename T>
void BST<T>::findIntersection(Node<T>* current, const BST<T>& otherBST, vector<T>& result) const {
    if (current == nullptr) {
        return;
    }
    
    findIntersection(current->left, otherBST, result);
    
    if (otherBST.search(current->valor)) {
        result.push_back(current->valor);
    }
    
    findIntersection(current->right, otherBST, result);
}

#endif // BST_CPP