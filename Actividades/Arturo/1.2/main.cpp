#include <iostream>
#include <vector>

// Autor: Arturo Gomez
// Matrícula: A07106692
// Fecha de creación/modificación: 09/06/2024
// Descripción: 
/* Este programa en C++ implementa algoritmos de ordenamiento (inserción, burbuja, merge) 
y búsqueda (secuencial, binaria) sobre un vector de enteros, contando las comparaciones realizadas. */

using namespace std;


/**  
 * @brief Funcion que intercambia los valores en dos posiciones.
 * @param datos Vector de enteros donde se realizará el intercambio.
 * @param a Índice del primer valor a intercambiar.
 * @param b Índice del segundo valor a intercambiar.
 */
void swaple(vector<int> &datos, int a, int b) {
    int inter = datos[a];
    datos[a] = datos[b];
    datos[b] = inter;
}


/**  
 * @brief Imprime los elementos de un vector en la consola (Utilizado para pruebas).
 * @param datos Vector de enteros cuyos elementos serán impresos.
 */
void print(vector <int> datos){
    int lenght = datos.size();
    cout << "datos -> " ;
    for (int i = 0; i < lenght; i++){
        if (i+1 == lenght){
            cout << datos[i] << endl;
        } else {
            cout << datos[i] << ", ";
        }
    }
}


/**  
 * @brief Ordena en forma ascendente los datos con el método de Inserción
 * @param datos vector con enteros desordenados 
 * @return Numero de comparaciones realizadas
*/
int ordenaInsercion(vector<int> &datos){
    int length = datos.size();
    int noComparaciones = 0;
    for (int j = 0; j < length - 1; j++) {
        for (int i = j + 1; i > 0; i--) {
            noComparaciones++;  // Incrementa el numero de comparaciones
            if (datos[i] < datos[i - 1]) {
                swaple(datos, i, i - 1); // Funcion presstablecida que intercambia los valores en dos posiciones (i, i+1)
            } else {
                break;
            }
        }
    }
    return noComparaciones;
}


/**  
 * @brief Ordena en forma ascendentelos datos con el método de Burbuja
 * @param datos vector con enteros desordenados 
 * @return Numero de comparaciones realizadas
*/
int ordenaBurbuja(vector <int> &datos){ 
    int lenght = datos.size();
    int noComparaciones = 0;
    bool ordenado = false;
    for (int j = 0; j < lenght-1; j++){
        ordenado = true;
        for (int i = 0; i < lenght-1-j; i++){
            noComparaciones++;
            if (datos[i] > datos[i+1]){
                swaple(datos,i,i+1);
                ordenado = false;
            }
        }
        if (ordenado){
            break;
        }
    }
    return noComparaciones;
}


/**  
 * @brief Función auxiliar para combinar dos subarreglos ordenados en el vector principal.
 * @param datos Vector de enteros que contiene los elementos a combinar.
 * @param ini Índice inicial de la primera mitad del subarreglo.
 * @param fin Índice final del subarreglo.
 * @param noComparaciones Variable que cuenta el número de comparaciones realizadas.
 */
void mezcla(vector<int> &datos, int ini, int fin, int &noComparaciones) { 
    int mid = ini + (fin - ini) / 2;
    int i = ini, j = mid + 1, k = 0;

    int* temp = new int[fin - ini + 1];

    while (i <= mid && j <= fin) {
        noComparaciones++;  // Contar la comparación
        if (datos[i] <= datos[j]) {
            temp[k++] = datos[i++];
        } else {
            temp[k++] = datos[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = datos[i++];
    }

    while (j <= fin) {
        temp[k++] = datos[j++];
    }

    for (i = ini, k = 0; i <= fin; i++, k++) {
        datos[i] = temp[k];
    }

    delete[] temp;
}

/**  
 * @brief Ordena en forma ascendente los datos utilizando el algoritmo de Merge Sort.
 * @param datos Vector de enteros a ordenar.
 * @param ini Índice inicial del subarreglo a ordenar.
 * @param fin Índice final del subarreglo a ordenar.
 * @param noComparaciones Variable que cuenta el número de comparaciones realizadas.
 */
int ordenaMerge(vector<int> &datos, int ini, int fin, int &noComparaciones) {
    if (ini < fin) {
        int mid = ini + (fin - ini) / 2;
        ordenaMerge(datos, ini, mid, noComparaciones);
        ordenaMerge(datos, mid + 1, fin, noComparaciones);
        mezcla(datos, ini, fin, noComparaciones);
    }
    return 1;
}

/**  
 * @brief Ordena en forma ascendente los datos con el método de Merge.
 * @param datos Vector con enteros desordenados.
 * @return Número de comparaciones realizadas.
 */
int ordenaMerge(vector<int> &datos) {
    int length = datos.size();
    int noComparaciones = 0;
    if (length > 0) {
        ordenaMerge(datos, 0, length - 1, noComparaciones);
    }
    return noComparaciones;
}


/**  
 * @brief Buscar con  búsqueda secuencial un dato entero dentro del vector.
 * @param datos Vector de enteros donde se realiza la búsqueda.
 * @param busc Valor que se desea buscar.
 * @param noComparaciones Numero de comparaciones realizadas
 * @return Índice del valor buscado si se encuentra en el vector, de lo contrario, retorna -1.
 */
int busqSecuencial(vector <int> &datos, int busc, int &noComparaciones){
    int lenght = datos.size();
    for (int i=0; i< lenght; i++){
        noComparaciones++;
        if (datos[i]==busc){
            return i;
        }
    }
    return -1;
}


/**  
 * @brief Buscar con  búsqueda binaria un dato entero dentro del vector.
 * @param datos Vector de enteros ordenado donde se realiza la búsqueda.
 * @param busc Valor que se desea buscar.
 * @param noComparaciones Numero de comparaciones realizadas
 * @return Índice del valor buscado si se encuentra en el vector, de lo contrario, retorna -1.
 */
int busqBinaria(vector <int> datos, int busc, int &noComparaciones){
    int lenght = datos.size();
    int min = 0, max = lenght-1, mid;
    while (min <= max){
        mid = (min + max) / 2;
        noComparaciones++;
        if (datos[mid] == busc){
            return mid;
        }
        noComparaciones++;
        if (busc > datos[mid]){
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1;
}
