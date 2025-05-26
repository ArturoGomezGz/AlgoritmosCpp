#include <iostream>
#include <string>
#include <vector>
#include "structs.h"

using namespace std;

// Función para mostrar los detalles de un Registro
void mostrarRegistro(const Registro& reg) {
    cout << "=== Registro ===" << endl;
    cout << "Valor original: " << reg.value << endl;
    cout << "Fecha: " << reg.date.date << " (valor comparable: " << reg.date.dateComparableValue << ")" << endl;
    cout << "Hora: " << reg.time.time << " (valor comparable: " << reg.time.timeComparableValue << ")" << endl;
    cout << "IP Origen: " << reg.origen.ip << " (valor comparable: " << reg.origen.ipComparableValue << ")" << endl;
    cout << "IP Destino: " << reg.destino.ip << " (valor comparable: " << reg.destino.ipComparableValue << ")" << endl;
    cout << "Peso: " << reg.peso << endl;
    cout << "Mensaje: " << reg.mensaje << endl;
    cout << endl;
}

int main() {
    // Ejemplos de registros para probar
    vector<string> ejemplos = {
        "Sep 17 00:54:39 33.213.148.82:2528 137.169.193.233:3170 53 Failed password for admin",
        "Oct 9 10:32:24 10.15.175.231:6166 203.45.117.80:4521 80 Failed password for illegal user guest",
        "Nov 21 15:45:12 192.168.1.1:8080 10.0.0.1:443 22 Connection established with root"
    };
    
    // Probar el constructor de Registro con cada ejemplo
    for (const string& ejemplo : ejemplos) {
        Registro reg(ejemplo);
        mostrarRegistro(reg);
    }
    
    // Prueba manual adicional
    cout << "Ingrese un registro en el formato correcto para probarlo:" << endl;
    string entradaUsuario;
    getline(cin, entradaUsuario);
    
    if (!entradaUsuario.empty()) {
        Registro regUsuario(entradaUsuario);
        mostrarRegistro(regUsuario);
    }
    
    return 0;
}
