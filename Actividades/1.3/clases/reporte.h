#include <iostream>   // Librería para entrada y salida estándar
#include <map>        // Librería para el uso de mapas (diccionarios)
#include <iomanip>    // Librería para manipulación de entrada/salida (get_time)
#include <sstream>    // Librería para el manejo de cadenas de caracteres y flujos
#include <ctime>      // Librería para manejo de tiempo y fechas

using namespace std;  // Para evitar escribir std:: antes de cada uso de objetos de la biblioteca estándar

// Clase Reporte que encapsula la información de un reporte con IP, razón, fecha y hora
class Reporte
{
private:
    string 
        ip,        // Almacena la dirección IP
        razon,     // Razón del reporte
        dia,       // Día en formato de texto (ej: "1", "15")
        mes,       // Mes en formato de texto (ej: "Jan", "Feb")
        hora;      // Hora en formato "HH:MM:SS"
    
    // Mapas para convertir nombres de meses y días a formato numérico
    map<string, string> meses = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"},
                                 {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"},
                                 {"Nov", "11"}, {"Dec", "12"}};
    
    map<string, string> dias = {{"1", "01"}, {"2", "02"}, {"3", "03"}, {"4", "04"}, {"5", "05"}, {"6", "06"}, 
                                {"7", "07"}, {"8", "08"}, {"9", "09"}, {"10", "10"}, {"11", "11"}, {"12", "12"},
                                {"13", "13"}, {"14", "14"}, {"15", "15"}, {"16", "16"}, {"17", "17"}, {"18", "18"},
                                {"19", "19"}, {"20", "20"}, {"21", "21"}, {"22", "22"}, {"23", "23"}, {"24", "24"},
                                {"25", "25"}, {"26", "26"}, {"27", "27"}, {"28", "28"}, {"29", "29"}, {"30", "30"}};
    
    time_t fachaHora; // Almacena el tiempo en formato de time_t (fecha y hora)

public:
    // Constructores
    Reporte(string mes, string hora, string ip, string razon, string dia); // Constructor parametrizado
    Reporte(); // Constructor por defecto

    // Métodos
    void print();                  // Imprime el reporte en formato legible
    time_t getFechaHora();         // Devuelve el tiempo almacenado (time_t)
    string getLine();              // Devuelve el reporte como una cadena formateada
};

// Constructor parametrizado que inicializa los atributos con valores proporcionados
Reporte::Reporte(string mes, string hora, string ip, string razon, string dia)
{
    this->ip = ip;        // Asigna el valor de la IP
    this->razon = razon;  // Asigna la razón del reporte
    this->dia = dia;      // Asigna el día
    this->mes = mes;      // Asigna el mes
    this->hora = hora;    // Asigna la hora

    // Crear un objeto tm para almacenar fecha y hora
    tm tm = {};
    
    // Crear un flujo de entrada con la fecha y hora en formato "dd-mm-yyyy hh:mm:ss"
    istringstream ss(dias[dia] + "-" + meses[mes] + "-2024 " + hora);
    
    // Extraer el tiempo desde la cadena y almacenarlo en el objeto tm
    ss >> get_time(&tm, "%d-%m-%Y %H:%M:%S");

    // Convertir la estructura tm a time_t para almacenar en fachaHora
    this->fachaHora = mktime(&tm);
}

// Constructor por defecto, no hace nada en este caso
Reporte::Reporte()
{

}

// Método para imprimir los detalles del reporte
void Reporte::print()
{
    // Imprime los atributos del reporte (mes, día, hora, IP, razón)
    cout << this->mes << " " << this->dia << " " << this->hora << " " << this->ip << " " << this->razon << endl;
}

// Método que devuelve el reporte formateado como una sola cadena de texto
string Reporte::getLine()
{
    // Concatena los atributos en una cadena de texto
    return (this->mes + " " + this->dia + " " + this->hora + " " + this->ip + " " + this->razon);
}

// Método que devuelve el valor de fachaHora, que contiene la fecha y hora en formato time_t
time_t Reporte::getFechaHora()
{
    return this->fachaHora;  // Devuelve el tiempo almacenado
}
