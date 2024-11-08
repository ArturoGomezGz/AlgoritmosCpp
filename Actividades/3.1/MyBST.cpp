#include "MyBST.h"
#include <queue>

// Constructor
MyBST::MyBST() 
{
    size = 0;
    root = nullptr;
}

// Método para obtener la longitud del árbol
// O(1)
int MyBST::length() 
{
    return size;
}

// Método para verificar si el árbol está vacío
// O(1)
bool MyBST::isEmpty() 
{
    return size == 0;
}

// Método de búsqueda en el árbol
// O(log n) en promedio, O(n) en el peor caso
bool MyBST::search(int data) 
{
    return search(data, this->root);
}

// Método de búsqueda recursiva (privado)
bool MyBST::search(int data, MyNodeBST* current) 
{
    if (current == nullptr) 
    {
        return false;
    }

    if (current->data == data) 
    {
        return true;
    } 
    else if (data < current->data) 
    {
        return search(data, current->left);
    } 
    else 
    {
        return search(data, current->right);
    }
}

// Método para insertar un dato en el árbol
// O(log n) en promedio, O(n) en el peor caso
bool MyBST::insert(int data) 
{
    MyNodeBST* node = new MyNodeBST(data);
    if (this->isEmpty())
    {
        this->root = node;
        this->size++;
        return true;
    }

    MyNodeBST* actual = this->root;
    MyNodeBST* parent = nullptr;

    while (actual != nullptr)
    {
        parent = actual;

        if (data < actual->data) 
        {
            actual = actual->left;
        } 
        else if (data > actual->data) 
        {
            actual = actual->right;
        } 
        else 
        {
            return false;
        }
    }

    if (data < parent->data)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }

    this->size++;
    return true;
}

// Método para eliminar un dato del árbol
// O(log n) en promedio, O(n) en el peor caso
bool MyBST::remove(int data) 
{
    if (this->isEmpty()) 
    {
        return false;
    }

    MyNodeBST* actual = this->root;
    MyNodeBST* parent = nullptr;

    while (actual != nullptr && actual->data != data) 
    {
        parent = actual;
        if (data < actual->data) 
        {
            actual = actual->left;
        } else 
        {
            actual = actual->right;
        }
    }

    if (actual == nullptr) {
        return false;
    }

    // Caso 1: El nodo a eliminar no tiene hijos (nodo hoja)
    // O(1)
    if (actual->left == nullptr && actual->right == nullptr) 
    {
        if (actual == root) {
            root = nullptr;
        } else if (parent->left == actual) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }
    // Caso 2: El nodo a eliminar tiene un solo hijo (izquierdo o derecho)
    // O(1)
    else if (actual->left == nullptr) 
    {
        if (actual == root) {
            root = actual->right;
        } else if (parent->left == actual) {
            parent->left = actual->right;
        } else {
            parent->right = actual->right;
        }
    } 
    else if (actual->right == nullptr) 
    {
        if (actual == root) {
            root = actual->left;
        } else if (parent->left == actual) {
            parent->left = actual->left;
        } else {
            parent->right = actual->left;
        }
    }
    // Caso 3: El nodo a eliminar tiene dos hijos
    // O(log n) en promedio, O(n) en el peor caso
    else 
    {
        MyNodeBST* successor = actual->right;
        MyNodeBST* successorParent = actual;

        while (successor->left != nullptr) 
        {
            successorParent = successor;
            successor = successor->left;
        }

        actual->data = successor->data;

        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
    }

    delete actual;
    this->size--;
    return true;
}

// Método para recorrer el árbol en preorden
// O(n)
void MyBST::preorder() 
{
    preorder(root);
    cout << endl;
}

// Método de recorrido en preorden recursivo (privado)
void MyBST::preorder(MyNodeBST* current) 
{
    if (current == nullptr) 
    {
        return;
    }

    cout << current->data << ",";
    preorder(current->left);
    preorder(current->right);
}

// Método para recorrer el árbol en inorden
// O(n)
void MyBST::inorder() 
{
    inorder(root);
    cout << endl;
}

// Método de recorrido en inorden recursivo (privado)
void MyBST::inorder(MyNodeBST* current) 
{
    if (current == nullptr) 
    {
        return;
    }

    inorder(current->left);
    cout << current->data << ",";
    inorder(current->right);
}

// Método para recorrer el árbol en postorden
// O(n)
void MyBST::postorder() 
{
    postorder(root);
    cout << endl;
}

// Método de recorrido en postorden recursivo (privado)
void MyBST::postorder(MyNodeBST* current) 
{
    if (current == nullptr) 
    {
        return;
    }
    
    inorder(current->left);
    inorder(current->right);
    cout << current->data << ",";
}

// Método para recorrer el árbol por niveles
// O(n)
void MyBST::level() 
{
    if (isEmpty()) 
    {
        cout << "El árbol está vacío." << endl;
        return;
    }

    queue<MyNodeBST*> q;
    q.push(this->root);

    while (!q.empty()) 
    {
        MyNodeBST* current = q.front();
        q.pop();

        cout << current->data << ",";

        if (current->left != nullptr) 
        {
            q.push(current->left);
        }

        if (current->right != nullptr) 
        {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Método para visitar el árbol según el tipo de recorrido
void MyBST::visit(int type) 
{
    switch (type)
    {
    case 1:
        preorder();
        break;
    case 2:
        inorder();
        break;
    case 3:
        postorder();
        break;
    case 4:
        level();
        break;
    default:
        cout << type << " no es una opción" << endl;
        cout << "Opciones posibles: 1 (Preorder), 2 (Inorder), 3 (Postorder), 4 (Level-order)" << endl;
        break;
    }
}

// Método para obtener la altura del árbol
// O(n)
int MyBST::height() 
{
    if (this->isEmpty()) 
    {
        return -1;
    }

    queue<MyNodeBST*> q;
    q.push(this->root);

    int height = -1;

    while (!q.empty()) 
    {
        int levelSize = q.size();
        height++;

        for (int i = 0; i < levelSize; i++) 
        {
            MyNodeBST* current = q.front();
            q.pop();

            if (current->left != nullptr) 
            {
                q.push(current->left);
            }
            if (current->right != nullptr) 
            {
                q.push(current->right);
            }
        }
    }

    return height;
}

// Método para imprimir los ancestros de un dato
// O(n)
void MyBST::ancestors(int data) 
{
    if (this->isEmpty()) 
    {
        cout << "El árbol está vacío." << endl;
        return;
    }

    MyNodeBST* current = this->root;
    bool found = false;

    while (current != nullptr) 
    {
        if (current->data == data) 
        {
            found = true;
            break;
        }
        
        cout << current->data << ",";

        if (data < current->data) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }

    if (!found) 
    {
        cout << "No se encontró el valor en el árbol." << endl;
    }
}

// Método para obtener el nivel de un dato en el árbol
// O(log n) en promedio, O(n) en el peor caso
int MyBST::whatLevelAmI(int data) 
{
    MyNodeBST* current = this->root;
    int level = 0;

    while (current != nullptr) 
    {
        if (current->data == data) 
        {
            return level;
        } 
        else if (data < current->data) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
        
        level++;
    }

    return -1;
}
