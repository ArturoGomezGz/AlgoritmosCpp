/* Programa que gestiona un conjunto de reportes almacenados en una bitácora,
permitiendo ordenarlos, filtrarlos por fechas y exportarlos a archivos.

Autor: [Arturo Gomez Gomez A07106692, David Martinez Martin del Campo A01645721, OScar Orlando de la Paz Ibarra A01644484]
Fecha de creación: [18/09/24]
*/

#include <iostream>
#include <fstream>
#include <string>
#include "clases/vectorReportes.h"  // Incluye la definición de la clase VectorReportes

using namespace std;


/*
Función main que gestiona el proceso de:
- Carga de un archivo de bitácora.
- Ordenación de los reportes.
- Filtrado de los reportes por fechas.
- Exportación de los reportes a archivos.
*/
int main() {

    // Nombre del archivo exportado
    string archivo2 = "output/bitacoraOrdenada1.3-eq2";

    // Ciclo para permitir múltiples filtrados por fechas
    bool continuar = true;
    int busqueda = 0;
    
    while (continuar) {
        string opt;  // Opción para continuar o no
        busqueda++;  // Contador para los archivos de salida consecutivos
        
        VectorReportes v1 = VectorReportes();
        
        // Volver a cargar los reportes exportados
        v1.addDoc(archivo2);
        
        // Filtrar los reportes por fechas ingresadas por el usuario
        v1.filtrarPorFechas();
        v1.print();
        
        // Exportar los reportes filtrados a un nuevo archivo
        v1.exportar("salida" + to_string(busqueda) + "-eq2");
        
        // Preguntar al usuario si desea realizar otra búsqueda
        cout << "¿Deseas hacer otra busqueda? (y/n): ";
        cin >> opt;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Si el usuario responde 'n', se detiene el ciclo
        if (opt == "n") {
            continuar = false;
        }

    }

    return 0;
}
