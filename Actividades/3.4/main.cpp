#include "BST.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByFrequency(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

void obtenerIpsMasRepetidas(const string& nombreArchivo, int x) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    map<string, int> contadorIps;
    string linea;

    while (getline(archivo, linea)) {
        
        size_t posInicioIp = linea.find(" ");
        posInicioIp = linea.find(" ", posInicioIp + 1);
        posInicioIp = linea.find(" ", posInicioIp + 1) + 1;
        size_t posFinIp = linea.find(":", posInicioIp);
        
        if (posInicioIp != string::npos && posFinIp != string::npos) {
            string ip = linea.substr(posInicioIp, posFinIp - posInicioIp);
            contadorIps[ip]++;
        }
    }
    archivo.close();

    vector<pair<string, int>> ipsOrdenadas(contadorIps.begin(), contadorIps.end());

    sort(ipsOrdenadas.begin(), ipsOrdenadas.end(), sortByFrequency);

    cout << "Las " << x << " IPs más repetidas son:" << endl;
    for (int i = 0; i < x && i < ipsOrdenadas.size(); ++i) {
        cout << ipsOrdenadas[i].first << " " << ipsOrdenadas[i].second << endl;
    }
}


int main(int argc, char const *argv[])
{
    BST arbol = BST();
    arbol.insertFromTxt("bitacora2");
    arbol.writeToFile("bitacoraOrdenadaIP-Eq1-BST");
    obtenerIpsMasRepetidas("bitacoraOrdenadaIP-Eq1-BST", 5);
    
    return 0;
}
