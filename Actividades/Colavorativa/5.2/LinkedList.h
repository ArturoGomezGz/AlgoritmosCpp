#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Node
{
    string month;
    int day;
    string time;
    Node* next;
    long dateCompare;

    void setDateCompare() {
        unordered_map<string, int> monthToNumber = {
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
            {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
        };

        int monthValue = monthToNumber[this->month];
        int hour = stoi(this->time.substr(0, 2));
        int minute = stoi(this->time.substr(3, 2));
        int second = stoi(this->time.substr(6, 2));

        // Combinar todos los valores en una sola cifra para comparación
        this->dateCompare = monthValue * 100000000 + this->day * 1000000 +
                            hour * 10000 + minute * 100 + second;
    }
    
    // Método para separar y asignar los valores desde una línea de texto
    void separarLinea(const string& linea) {
        istringstream stream(linea);
        string dayStr;

        getline(stream, this->month, ' '); 
        getline(stream, dayStr, ' ');
        this->day = stoi(dayStr);
        getline(stream, this->time, ' ');
        // Lo que queda después del tercer espacio se ignora
    }

    Node(string data, Node* next) {
        separarLinea(data);
        setDateCompare();
    }

    Node(string data) : Node(data, nullptr) {}

    string writeLine(){
        return month + " " + to_string(day) + " " + time;
    }

    void print(){
        cout << writeLine() << endl;
    }
};

class LinkedList
{
private:
    int size;
    Node* head;
public:
    LinkedList(); // Constructor
    int length(); // Devuelve el largo de la lista
    bool isEmpty(); // Revisa si la lista esta vacia
    void insert(string data); // Inserta un elemento 
    void print(); // Imprime todos los elementos
};

#endif