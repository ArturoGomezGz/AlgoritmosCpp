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
    // Casos de prueba para Fibonacci
    cout << "Fibonacci Iterativo (10): " << fibonacciIterativo(10) << endl; // Espera 55
    cout << "Fibonacci Iterativo (15): " << fibonacciIterativo(15) << endl; // Espera 610
    cout << "Fibonacci Iterativo (30): " << fibonacciIterativo(30) << endl; // Espera 832040

    cout << "Fibonacci Recursivo (10): " << fibonacciRecursivo(10) << endl; // Espera 55
    cout << "Fibonacci Recursivo (15): " << fibonacciRecursivo(15) << endl; // Espera 610
    cout << "Fibonacci Recursivo (30): " << fibonacciRecursivo(30) << endl; // Espera 832040

    // Casos de prueba para promedio
    vector<int> arr1 = {1, 5, 10, 23, 56, 100};
    vector<int> arr2 = {51, 35, 140, 323, 566, 1600, 231, 99, 1, 662};

    cout << "Promedio Iterativo (arr1): " << promedioIterativo(arr1) << endl; // Espera 32.5
    cout << "Promedio Iterativo (arr2): " << promedioIterativo(arr2) << endl; // Espera 370.8

    cout << "Promedio Recursivo (arr1): " << promedioRecursivo(arr1) << endl; // Espera 32.5
    cout << "Promedio Recursivo (arr2): " << promedioRecursivo(arr2) << endl; // Espera 370.8

    // Casos de prueba para stringToInteger
    string str1 = "345169";
    string str2 = "89651472543";
    string str3 = "123a456";

    cout << "String to Int Iterativo (str1): " << strToIntIterativo(str1) << endl; // Espera 345169
    cout << "String to Int Iterativo (str2): " << strToIntIterativo(str2) << endl; // Espera 89651472543
    cout << "String to Int Iterativo (str3): " << strToIntIterativo(str3) << endl; // Espera "Cadena invalida"

    cout << "String to Int Recursivo (str1): " << strToIntRecursivo(str1) << endl; // Espera 345169
    cout << "String to Int Recursivo (str2): " << strToIntRecursivo(str2) << endl; // Espera 89651472543
    cout << "String to Int Recursivo (str3): " << strToIntRecursivo(str3) << endl; // Espera "Cadena invalida"

    return 0;
}