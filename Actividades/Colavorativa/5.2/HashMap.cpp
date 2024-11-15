#include "HashMap.h"

HashMap::HashMap() {
    this->size = 0;
    this->keys = nullptr;
}

int HashMap::length() {
    return this->size;
}

bool HashMap::isEmpty() {
    return this->size == 0;
}

void HashMap::insert(string line) {
    string ip = this->getIp(line);
    MapNode* current = this->keys;
    while (current != nullptr) {
        if (current->ip == ip) {
            current->insert(line);
            return;
        }
        current = current->next;
    }
    newIp(ip);
}

void HashMap::newIp(string ip) {
    if (this->isEmpty()) {
        this->keys = new MapNode(ip);
    } else {
        MapNode* node = new MapNode(ip);
        MapNode* current = this->keys;
        while (current->next != nullptr && current->next->ipLong < node->ipLong) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    this->size++;
}

void HashMap::print() {
    MapNode* current = keys;
    while (current != nullptr) {
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
        if (wordCount == 4) {
            size_t colonPos = word.find(':');
            if (colonPos != string::npos) {
                return word.substr(0, colonPos);
            }
            return word;
        }
    }

    return "";
}

void HashMap::loadTxt(string file) {
    ifstream fileLine("./" + file + ".txt");

    if (!fileLine.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;
    while (getline(fileLine, line)) {
        this->insert(line);
    }
    fileLine.close();
}
