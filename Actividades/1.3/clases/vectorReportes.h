#include <iostream>
#include <vector>
#include "reporte.h"  // Incluye la clase Reporte
#include <sstream>
#include <limits>


using namespace std;

// Clase que almacena y manipula un vector de objetos Reporte
class VectorReportes
{
private:
    vector<Reporte> reportes;  // Vector que almacena múltiples objetos de tipo Reporte
public:
    // Constructores
    VectorReportes();  // Constructor por defecto
    VectorReportes(vector<Reporte> reportes);  // Constructor que inicializa con un vector de reportes

    // Métodos
    vector<Reporte> &getVector();  // Devuelve una referencia al vector de reportes
    void mezcla(int ini, int fin);  // Método para mezclar dos subarreglos (utilizado en merge sort)
    void mergeSort(int ini, int fin);  // Método recursivo para aplicar merge sort en un rango
    void mergeSort();  // Método para aplicar merge sort a todo el vector
    int busquedaSec(time_t fecha);  // Búsqueda secuencial de un reporte por fecha
    void print();  // Imprime los reportes
    void addDoc(string doc);  // Agrega reportes desde un archivo de texto
    void exportar(string nombre);  // Exporta los reportes a un archivo de texto
    void filtrarPorFechas();  // Filtra reportes entre dos fechas
    map<string, string> meses = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"},{"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"},{"Nov", "11"}, {"Dec", "12"}};
    map<string, string> dias = {{"1", "01"}, {"2", "02"}, {"3", "03"}, {"4", "04"}, {"5", "05"}, {"6", "06"}, {"7", "07"}, {"8", "08"}, {"9", "09"}, {"10", "10"},{"11", "11"}, {"12", "12"}, {"13", "13"}, {"14", "14"}, {"15", "15"},{"16", "16"}, {"17", "17"}, {"18", "18"}, {"19", "19"}, {"20", "20"},{"21", "21"}, {"22", "22"}, {"23", "23"}, {"24", "24"}, {"25", "25"}, {"26", "26"}, {"27", "27"}, {"28", "28"}, {"29", "29"}, {"30", "30"}};
};

// Constructor por defecto, no hace nada en este caso
VectorReportes::VectorReportes()
{
}

// Constructor que inicializa el vector de reportes
VectorReportes::VectorReportes(vector<Reporte> reportes)
{
    this->reportes = reportes;
}

// Devuelve una referencia al vector de reportes
vector<Reporte> &VectorReportes::getVector()
{
    return this->reportes;
}

// Mezcla dos subarreglos en el proceso de merge sort
void VectorReportes::mezcla(int ini, int fin) { 
    int mid = ini + (fin - ini) / 2;
    int i = ini, j = mid + 1, k = 0;

    // Vector temporal para almacenar los elementos ordenados
    vector<Reporte> temp(fin - ini + 1);

    // Mezclar los dos sub-arreglos
    while (i <= mid && j <= fin) {
        if (this->reportes[i].getFechaHora() <= this->reportes[j].getFechaHora()) {
            temp[k++] = this->reportes[i++];  // Agrega el reporte con menor fecha
        } else {
            temp[k++] = this->reportes[j++];
        }
    }

    // Copiar los elementos restantes del primer sub-arreglo, si hay
    while (i <= mid) {
        temp[k++] = this->reportes[i++];
    }

    // Copiar los elementos restantes del segundo sub-arreglo, si hay
    while (j <= fin) {
        temp[k++] = this->reportes[j++];
    }

    // Copiar el contenido del vector temporal al vector original
    for (i = ini, k = 0; i <= fin; i++, k++) {
        this->reportes[i] = temp[k];
    }
}

// Método recursivo para aplicar merge sort en un rango específico del vector
void VectorReportes::mergeSort(int ini, int fin) {
    if (ini < fin) {
        int mid = ini + (fin - ini) / 2;
        mergeSort(ini, mid);  // Ordena la primera mitad
        mergeSort(mid + 1, fin);  // Ordena la segunda mitad
        mezcla(ini, fin);  // Mezcla ambas mitades
    }
}

// Aplica merge sort a todo el vector de reportes
void VectorReportes::mergeSort() {
    int length = this->reportes.size();
    if (length > 0) {
        mergeSort(0, length - 1);  // Llama a mergeSort para ordenar todo el vector
    }
}

// Búsqueda secuencial de un reporte con una fecha igual o posterior a la proporcionada
int VectorReportes::busquedaSec(time_t fecha){
    for (int i = 0; i < reportes.size(); i++){
        if (reportes[i].getFechaHora() >= fecha){  // Compara las fechas
            return i;  // Devuelve el índice si la fecha es encontrada
        }
    }
    return -1;  // Devuelve -1 si no se encuentra ninguna fecha mayor o igual
}

// Imprime todos los reportes
void VectorReportes::print() {
    for (size_t i = 0; i < this->reportes.size(); i++) {
        this->reportes[i].print();  // Llama al método print de cada reporte
    }
}

// Agrega reportes desde un archivo de texto
void VectorReportes::addDoc(string doc){
    ifstream archivo("../"+doc+".txt");  // Abre el archivo de texto
    
    string linea;

    // Procesa cada línea del archivo
    while (getline(archivo, linea)) {
        int spaceCount = 0;
        string elemento = "";
        string mes, hora, ip, razon, dia;

        // Procesa los elementos de la línea separados por espacios
        for (size_t i = 0; i < linea.length(); i++) {
            if (spaceCount < 4){
                if (!(linea[i] == ' ')){
                    elemento += linea[i];  // Acumula caracteres hasta encontrar un espacio
                } else {
                    switch (spaceCount){  // Asigna el valor acumulado a la variable correspondiente
                    case 0:
                        mes = elemento;
                        elemento = "";
                        break;
                    case 1:
                        dia = elemento;
                        elemento = "";
                        break;
                    case 2:
                        hora = elemento;
                        elemento = "";
                        break;
                    case 3:
                        ip = elemento;
                        elemento = "";
                        break;
                    }
                    spaceCount++;
                }
            } else {
                elemento += linea[i];  // Acumula el resto de la línea como la razón
            }
        }
        razon = elemento;  // La última parte de la línea es la razón

        // Crea un objeto Reporte y lo agrega al vector de reportes
        Reporte reporte = Reporte(mes,hora,ip,razon,dia);
        this->reportes.push_back(reporte);
    }
    archivo.close();  // Cierra el archivo
}

// Exporta el vector de reportes a un archivo de texto
void VectorReportes::exportar(string nombre){
    ofstream archivo(nombre+".txt");  // Abre un archivo para escribir

    // Escribe cada reporte en el archivo
    for (int i = 0; i < this->reportes.size(); ++i) {
        archivo << this->reportes[i].getLine() << "\n";  // Escribe cada reporte en una nueva línea
    }

    archivo.close();  // Cierra el archivo
    cout << "archivo exportado con exito" << endl;
}

// Filtra los reportes entre dos fechas proporcionadas por el usuario
void VectorReportes::filtrarPorFechas(){
    string 
        mesIni, 
        mesFin, 
        diaIni,
        diaFin, 
        lineaIni,
        lineaFin;
    
    // Solicita la fecha inicial al usuario
    cout << "Fecha inicial (MMM D): " << endl;
    getline(cin, lineaIni);
    stringstream iniLine(lineaIni);
    iniLine >> mesIni;
    iniLine >> diaIni;

    // Solicita la fecha final al usuario
    cout << "Fecha final (MMM D): " << endl;
    getline(cin, lineaFin);
    stringstream finLine(lineaFin);
    finLine >> mesFin;
    finLine >> diaFin;


    time_t fehcaFin, fehcaIni;  // Variables para almacenar las fechas en formato time_t

    int posIni, posFin;  // Posiciones de inicio y fin en el vector de reportes

    vector<Reporte> result;  // Vector para almacenar los reportes filtrados

    try {
        tm tm = {};
        // Convierte la fecha inicial a time_t
        istringstream ss(dias[diaIni]+"-"+meses[mesIni]+"-2024 00:00:00");
        ss >> get_time(&tm, "%d-%m-%Y %H:%M:%S");
        fehcaIni = mktime(&tm);

        // Convierte la fecha final a time_t
        istringstream mm(dias[diaFin]+"-"+meses[mesFin]+"-2024 00:00:00");
        mm >> get_time(&tm, "%d-%m-%Y %H:%M:%S");
        fehcaFin = mktime(&tm);

    } catch (exception e) {
        cout << "formato de fehca incorrecto " << endl;  // Captura errores en el formato de fecha
    }

    // Verifica que la fecha inicial sea menor que la fecha final
    if (fehcaIni < fehcaFin){
        posIni = this->busquedaSec(fehcaIni);  // Busca la posición de la fecha inicial
        if (this->busquedaSec(fehcaFin) == -1){
            posFin = this->reportes.size();  // Si no se encuentra la fecha final, toma el tamaño total
        } else {
            posFin = this->busquedaSec(fehcaFin);  // Encuentra la posición de la fecha final
        }
    } else {
        cout << "la fehca de inicio debe de ser menor que la fecha final" << endl;  // Mensaje de error si las fechas están invertidas
    }

    // Filtra los reportes entre las posiciones encontradas
    for (int i = posIni; i < posFin ; i++){
        result.push_back(reportes[i]);
    }
    
    this->reportes = result;  // Actualiza el vector de reportes con los resultados filtrados
}
