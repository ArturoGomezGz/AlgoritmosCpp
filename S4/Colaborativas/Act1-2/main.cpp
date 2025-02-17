#include <iostream>
#include <string>
#include <vector>

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
float promedioIterativo(vector<int> n){
    int suma = 0;
    int size = n.size();
    for(int i = 0; i < size; i++){
        suma += n[i];
    }
    return static_cast<float>(suma) / size;
}

// Calcula el promedio de un arreglo de enteros de manera recursiva
// Espera un arreglo de enteros y su tamano, devuelve el promedio de los elementos
float promedioRecursivoAux(vector<int> n, int size){
    if(size == 0) return 0;
    if(size == 1) return n[0];
    return (n[size-1] + (promedioRecursivoAux(n, size-1) * (size-1))) / size;
}

float promedioRecursivo(vector<int> n){
    int size = n.size();
    return promedioRecursivoAux(n, size);
}

// Convierte una cadena de caracteres que representa un numero en un entero de manera iterativa
// Espera una cadena de caracteres y devuelve el numero entero correspondiente
int strToIntIterativo(string str){
    int num = 0;
    for(int i = 0; i < str.size(); i++){
        if(!isdigit(str[i])) {
            cout << "Cadena invalida" << endl;
            return -1; // Indicador de error
        }
        num = num*10 + (str[i] - '0');
    }
    return num;
}   

// Convierte una cadena de caracteres que representa un numero en un entero de manera recursiva
// Espera una cadena de caracteres y devuelve el numero entero correspondiente
int strToIntRecursivoAux(string str){
    if(str.size() == 0) return 0;
    if(!isdigit(str[0])) {
        cout << "Cadena invalida" << endl;
        return -1; // Indicador de error
    }
    return (str[0] - '0') + 10*strToIntRecursivoAux(str.substr(1));
}

int strToIntRecursivo(string str){
    int res = strToIntRecursivoAux(str);
    if (res <= 0) {return -1;}
    else {return res;}
}

int main()
{
    // Casos de prueba para cada funcion
    cout << "Fibonacci Iterativo (5): " << fibonacciIterativo(8) << endl; // Espera 21
    cout << "Fibonacci Recursivo (5): " << fibonacciRecursivo(8) << endl; // Espera 21

    vector<int> arr = {1, 2, 3, 4, 5, 5, 2, 2, 4, 22};
    cout << "Promedio Iterativo: " << promedioIterativo(arr) << endl; // Espera 3
    cout << "Promedio Recursivo: " << promedioRecursivo(arr) << endl; // Espera 3

    string str = "12345";
    cout << "String to Int Iterativo: " << strToIntIterativo(str) << endl; // Espera 12345
    cout << "String to Int Recursivo: " << strToIntRecursivo(str) << endl; // Espera 12345

    // Caso de prueba con cadena invalida
    string invalidStr = "12a45";
    cout << "String to Int Iterativo (invalido): " << strToIntIterativo(invalidStr) << endl; // Espera "Cadena invalida"
    cout << "String to Int Recursivo (invalido): " << strToIntRecursivo(invalidStr) << endl; // Espera "Cadena invalida"

    return 0;
}
