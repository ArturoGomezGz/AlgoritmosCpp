#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// Estructura Node que representa un nodo en la lista enlazada.
struct Node {
    string month;        // Mes en formato abreviado.
    int day;             // Día del mes.
    string time;         // Hora en formato HH:MM:SS.
    Node* next;          // Puntero al siguiente nodo.
    long dateCompare;    // Valor numérico utilizado para comparar fechas.

    // Calcula un valor numérico basado en el mes, día y hora para comparar fechas.
    // Complejidad: O(1)
    void setDateCompare() {
        unordered_map<string, int> monthToNumber = {
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
            {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
        };

        int monthValue = monthToNumber[this->month];
        int hour = stoi(this->time.substr(0, 2));
        int minute = stoi(this->time.substr(3, 2));
        int second = stoi(this->time.substr(6, 2));

        this->dateCompare = monthValue * 100000000 + this->day * 1000000 + hour * 10000 + minute * 100 + second;
    }

    // Separa los elementos de una línea y los asigna a las propiedades del nodo.
    // Complejidad: O(1)
    void separarLinea(const string& linea) {
        istringstream stream(linea);
        string dayStr;

        getline(stream, this->month, ' ');
        getline(stream, dayStr, ' ');
        this->day = stoi(dayStr);
        getline(stream, this->time, ' ');
    }

    // Constructor que inicializa un nodo con datos y un puntero al siguiente nodo.
    // Complejidad: O(1)
    Node(string data, Node* next) {
        separarLinea(data);
        setDateCompare();
        this->next = next;
    }

    // Constructor que inicializa un nodo con datos y sin siguiente nodo.
    // Complejidad: O(1)
    Node(string data) : Node(data, nullptr) {}

    // Retorna una cadena que representa los datos del nodo en formato de línea.
    // Complejidad: O(1)
    string writeLine() {
        return month + " " + to_string(day) + " " + time;
    }

    // Imprime los datos del nodo.
    // Complejidad: O(1)
    void print() {
        cout << writeLine() << endl;
    }
};

// Clase LinkedList que representa una lista enlazada de nodos.
class LinkedList {
private:
    int size;          // Tamaño de la lista enlazada.
    Node* head;        // Puntero al primer nodo de la lista.
public:
    LinkedList();
    // Constructor: inicializa la lista con tamaño 0 y sin nodos.

    int length();
    // Retorna el número de nodos en la lista.

    bool isEmpty();
    // Verifica si la lista está vacía.

    void insert(string data);
    // Inserta un nuevo nodo en la lista en orden ascendente según dateCompare.

    void print();
    // Imprime todos los nodos de la lista enlazada.
};

#endif
