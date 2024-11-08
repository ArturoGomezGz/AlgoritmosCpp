#include <iostream>

// Autor: Arturo Gomez
// Matrícula: A07106692
// Fecha de creación/modificación: 30/08/2024
// Descripción: Este programa implementa tres métodos para calcular la suma de los primeros n números naturales.

using namespace std;

/**
 * @brief Calcula la suma de los primeros n números usando un ciclo iterativo.
 * @param n El número hasta el cual se desea calcular la suma.
 * @return La suma de los primeros n números.
 */
int sumaIterativa(int n){
    if (n<0){
        return -1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        res = res + i;
    }
    return res;
}

/**
 * @brief Calcula la suma de los primeros n números de forma recursiva.
 * @param n El número hasta el cual se desea calcular la suma.
 * @return La suma de los primeros n números.
 */
int sumaRecursiva(int n){
    if (n<0){
        return -1;
    } else if(n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

/**
 * @brief Calcula la suma de los primeros n números de forma directa usando la fórmula aritmética de Gauss.
 * @param n El número hasta el cual se desea calcular la suma.
 * @return La suma de los primeros n números.
 */
int sumaDirecta(int n){
    if (n<0){
        return -1;
    }
    return (n * (n + 1)) / 2; 
}