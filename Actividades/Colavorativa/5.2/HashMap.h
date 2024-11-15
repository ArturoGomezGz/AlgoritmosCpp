#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <stdexcept>
#include "LinkedList.h"
#include <fstream>

struct MapNode
{
    string ip;
    long ipLong;
    LinkedList* value;
    MapNode* next;

    void setIpLong() {
        // Convierte la IP en formato string a un long
        istringstream iss(ip);
        string octet;
        vector<int> octets;

        while (getline(iss, octet, '.')) {
            int value = stoi(octet);
            if (value < 0 || value > 255) {
                throw invalid_argument("Invalid IP address format");
            }
            octets.push_back(value);
        }

        if (octets.size() != 4) {
            throw invalid_argument("Invalid IP address format");
        }

        // Calcula el valor long de la IP
        ipLong = (static_cast<long>(octets[0]) << 24) |
                 (static_cast<long>(octets[1]) << 16) |
                 (static_cast<long>(octets[2]) << 8) |
                 (static_cast<long>(octets[3]));
    }

    MapNode(string ip, MapNode* next) {
        this->ip = ip;
        this->value = nullptr;
        this->next = nullptr;
        this->setIpLong();
    }

    MapNode(string ip) : MapNode(ip, nullptr) {}

    void insert(string data){
        if (this->value = nullptr){
            this->value = new LinkedList();
        }
        this->value->insert(data);
    }

    void print(){
        cout << this->ip << endl;
        this->value->print();
    }
};

class HashMap
{
private:
    int size;
    MapNode* keys;
public:
    HashMap();
    int lenght();
    bool isEmpty();
    void instert(string line);
    void newIp(string ip);
    string getIp(string line);
    void print();
    void loadTxt(string file);
};

#endif