#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
    Node *right, *left;
    string ip,       // Almacena la dirección IP
           razon,    // Razón del reporte
           dia,      // Día en formato de texto (ej: "1", "15")
           mes,      // Mes en formato de texto (ej: "Jan", "Feb")
           hora;     // Hora en formato "HH:MM:SS"
    long long ipComparableValue; // Valor comparable de la IP, utilizado para ordenar en el BST

    // Constructor que inicializa el nodo con datos y sin hijo izquierdo o derecho
    Node(string data)
        : right(nullptr), left(nullptr)
    {
        loadData(data);
        ipToComparableValue();
    }

    // Método para cargar los datos desde una línea de texto
    void loadData(string linea)
    {
        int spaceCount = 0;
        string elemento = "";
        string mes, hora, ip, razon, dia;

        // Procesa los elementos de la línea separados por espacios
        for (size_t i = 0; i < linea.length(); i++)
        {
            if (spaceCount < 4)
            {
                if (!(linea[i] == ' '))
                {
                    elemento += linea[i];  // Acumula caracteres hasta encontrar un espacio
                }
                else
                {
                    switch (spaceCount)  // Asigna el valor acumulado a la variable correspondiente
                    {
                    case 0:
                        this->mes = elemento;
                        elemento = "";
                        break;
                    case 1:
                        this->dia = elemento;
                        elemento = "";
                        break;
                    case 2:
                        this->hora = elemento;
                        elemento = "";
                        break;
                    case 3:
                        this->ip = elemento;
                        elemento = "";
                        break;
                    }
                    spaceCount++;
                }
            }
            else
            {
                elemento += linea[i];  // Acumula el resto de la línea como la razón
            }
        }
        this->razon = elemento;
    }

    // Método para imprimir en consola los datos en formato de línea
    void print()
    {
        cout << this->mes << " " << this->dia << " " << this->hora << " " << this->ip << " " << this->razon << endl;
    }

    string write()
    {
        return this->mes + " " + this->dia + " " + this->hora + " " + this->ip + " " + this->razon;
    }

    // Método para escribir los datos en una línea en formato de texto
    string writeLine()
    {
        return this->mes + " " + this->dia + " " + this->hora + " " + this->ip + " " + this->razon;
    }

    // Método para convertir la IP a un valor comparable tipo long long
    long long ipToComparableValue(string ipStr)
    {
        int octet1, octet2, octet3, octet4;
        char dummy;
        stringstream ss(ipStr);

        ss >> octet1 >> dummy >> octet2 >> dummy >> octet3 >> dummy >> octet4;

        long long ipValue = (static_cast<long long>(octet1) << 24) | (octet2 << 16) | (octet3 << 8) | octet4;

        return ipValue;
    }

    // Función para actualizar ipComparableValue con el valor de la IP actual
    void ipToComparableValue()
    {
        this->ipComparableValue = ipToComparableValue(this->ip);
    }
};

#endif
