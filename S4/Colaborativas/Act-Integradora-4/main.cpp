#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "ListaAdyacencias.h"
#include "bfs_aux.h"

using namespace std;

int main() {
    string nombreArchivo = "bitacoraGrafos.txt";
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    string linea;
    int noNodos, noRegistros;

    getline(archivo, linea);
    istringstream stream(linea);
    stream >> noNodos >> noRegistros;

    ListaAdyacencias lista;

    for (int i = 0; i < noNodos; ++i) {
        getline(archivo, linea);
        lista.insertarNodo(linea);
    }

    for (int i = 0; i < noRegistros; ++i) {
        getline(archivo, linea);
        if (!lista.insertarRegistro(linea)) {
            cerr << "Error al insertar el registro: " << linea << endl;
        }
    }

    archivo.close();

    // Guardar grados de salida de cada IP
    guardarGrados(lista.getNodos());

    // Obtener las top 5 IPs con mayor grado de salida
    vector<Node*> top5 = obtenerTopConHeap(lista.getNodos(), 5);

    if (top5.empty()) {
        cerr << "No se pudo identificar un bot master." << endl;
        return 1;
    }

    string ipBotMaster = top5[0]->ip.ip;
    cout << "Bot master: " << ipBotMaster << endl;

    // Imprimir primera conexión del bot master
    if (!top5[0]->registros.empty()) {
        Registro* primero = top5[0]->registros[0];
        cout << "Primera conexión: " << primero->date.month << " " 
        << primero->date.day << " "
        << (primero->time.hour < 10 ? "0" : "") << primero->time.hour << ":"
        << (primero->time.minute < 10 ? "0" : "") << primero->time.minute << ":"
        << (primero->time.second < 10 ? "0" : "") << primero->time.second << endl;
    }

    unordered_map<string, int> distancias;
    unordered_map<string, string> padres;

    bfsDesdeIP(lista, ipBotMaster, distancias, padres);
    guardarDistancias(distancias);

    // Encontrar la IP más lejana
    string ipMasLejana;
    int maxDist = -1;
    for (const auto& par : distancias) {
        if (par.second > maxDist) {
            maxDist = par.second;
            ipMasLejana = par.first;
        }
    }

    cout << "IP más lejana: " << ipMasLejana << " a distancia " << maxDist << endl;
    guardarCamino(padres, ipMasLejana);

    return 0;
}
