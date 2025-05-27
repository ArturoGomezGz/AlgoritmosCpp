#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ListaAdyacencias.h"

using namespace std;

int main() {
    string nombreArchivo = "bitacoraGrafos.txt";
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    string linea;

    getline(archivo, linea); // Leemos la primera línea del archivo

    int noNodos, noRegistros;

    istringstream stream(linea);
    stream >> noNodos >> noRegistros;

    ListaAdyacencias lista;

    for (int i = 0; i < noNodos; ++i) {
        getline(archivo, linea);
        lista.insertarNodo(linea); // Insertamos cada nodo en la lista de adyacencias
    }
    for (int i = 0; i < noRegistros; ++i) {
        getline(archivo, linea);
        if (!lista.insertarRegistro(linea)) {
            cerr << "Error al insertar el registro: " << linea << endl;
        }
    }
    lista.imprimir(); // Imprimimos la lista de adyacencias

    //cout << lista.getNodo(0)->registros[0]->value << endl; // Imprimimos la IP del primer nodo

    archivo.close(); // Cerramos el archivo
    return 0;
}
