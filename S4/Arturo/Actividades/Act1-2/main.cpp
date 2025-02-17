#include <iostream>
#include <string>

using namespace std;

// Calcula el n-esimo numero de Fibonacci de manera iterativa
// Espera un entero n y devuelve el n-esimo numero de Fibonacci
int fibonacciIterativo(int n){
    int a = 0, b = 1, c;
    if(n == 0) return a;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Calcula el n-esimo numero de Fibonacci de manera recursiva
// Espera un entero n y devuelve el n-esimo numero de Fibonacci
int fibonacciRecursivo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
}

// Calcula el promedio de un arreglo de enteros de manera iterativa
// Espera un arreglo de enteros y su tamano, devuelve el promedio de los elementos
int promedioIterativo(int arr[], int n){
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma += arr[i];
    }
    return suma/n;
}

// Calcula el promedio de un arreglo de enteros de manera recursiva
// Espera un arreglo de enteros y su tamano, devuelve el promedio de los elementos
int promedioRecursivo(int arr[], int n){
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    return (arr[n-1] + (promedioRecursivo(arr, n-1) * (n-1))) / n;
}

// Convierte una cadena de caracteres que representa un numero en un entero de manera iterativa
// Espera una cadena de caracteres y devuelve el numero entero correspondiente
int strToIntIterativo(string str){
    int num = 0;
    for(int i = 0; i < str.size(); i++){
        num = num*10 + (str[i] - '0');
    }
    return num;
}   

// Convierte una cadena de caracteres que representa un numero en un entero de manera recursiva
// Espera una cadena de caracteres y devuelve el numero entero correspondiente
int strToIntRecursivo(string str){
    if(str.size() == 0) return 0;
    return (str[0] - '0') + 10*strToIntRecursivo(str.substr(1));
}

int main()
{
    // Casos de prueba para cada funcion
    cout << "Fibonacci Iterativo (5): " << fibonacciIterativo(8) << endl; // Espera 21
    cout << "Fibonacci Recursivo (5): " << fibonacciRecursivo(8) << endl; // Espera 21

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "Promedio Iterativo: " << promedioIterativo(arr, n) << endl; // Espera 3
    cout << "Promedio Recursivo: " << promedioRecursivo(arr, n) << endl; // Espera 3

    string str = "12345";
    cout << "String to Int Iterativo: " << strToIntIterativo(str) << endl; // Espera 12345
    cout << "String to Int Recursivo: " << strToIntRecursivo(str) << endl; // Espera 12345

    return 0;
}
