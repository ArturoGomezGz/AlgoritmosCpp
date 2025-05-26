#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "structs.h"

using namespace std;

struct Node {
    IpAddress ip; // Formato: 36.29.138.97
    vector<Registro> registros; // Vector de registros
}
    

#endif // NODE_H