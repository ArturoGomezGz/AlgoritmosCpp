#include "HashMap.h"

HashMap::HashMap(){
    this->size = 0;
    this->keys = nullptr;
}

int HashMap::lenght(){
    return this->size;
}

bool HashMap::isEmpty(){
    return this->size == 0;
}

void HashMap::instert(string line){
    string ip = this->getIp(line);
    MapNode* current = this->keys;
    while (current != nullptr){

        if (current->ip == ip){
            current->insert(line);
            return ;
        }
        current = current->next;
    }
    newIp(ip);
}

void HashMap::newIp(string ip){
    MapNode* node = new MapNode(ip);
    if (this->isEmpty()){
        this->keys = new MapNode(ip);
        this->size++;
    } else {
        MapNode* current = this->keys;
        while (current->next != nullptr && current->next->ipLong < node->ipLong) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    this->size++;
}

void HashMap::print(){
    MapNode* current = keys;
    while (current != nullptr){
        current->print();
        current = current->next;
    }
}

string HashMap::getIp(string line) {
    istringstream iss(line);
    string word;
    int wordCount = 0;

    while (iss >> word) {
        wordCount++;
        if (wordCount == 4) { // El tercer espacio separa el 4to token
            size_t colonPos = word.find(':');
            if (colonPos != string::npos) {
                return word.substr(0, colonPos); // Retorna solo la IP antes del ':'
            }
            return word; // Si no hay ':', regresa el token completo
        }
    }

    return ""; // Retorna una cadena vacía si no encuentra suficientes palabras
}

void HashMap::loadTxt(string file){
    ifstream fileLine("./"+file+".txt");

    string line;
    while (getline(fileLine, line))
    {
        this->instert(line);
    }
}