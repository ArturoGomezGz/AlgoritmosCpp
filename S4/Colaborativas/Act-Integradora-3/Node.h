#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

struct Time {
    string time; // Formato de la hora: 10:32:24
    int 
        hour,
        minute,
        second;
    long long timeComparableValue; // Este es un valor que se obtiene de la hora y se usa para comparar una hora con otra
    
    void set(string time) {
        this->time = time;
        int size = time.size();
        string hourString = "";
        string minuteString = "";
        string secondString = "";

        for (int i = 0; i < size; i++) {
            if (time[i] == ':') {
                hourString = time.substr(0, i);
                break;
            }
        }

        int pos = time.find(':', hourString.size() + 1);
        if (pos != string::npos) {
            minuteString = time.substr(hourString.size() + 1, pos - hourString.size() - 1);
            secondString = time.substr(pos + 1);
        }

        hour = stoi(hourString);
        minute = stoi(minuteString);
        second = stoi(secondString);

        // Calcula el valor comparable de la hora
        timeComparableValue = hour * 3600LL + minute * 60LL + second;
        // El valor comparable de la hora es el número total de segundos desde la medianoche
        // (00:00:00) hasta la hora dada.
    }

    Time() {
        time = "";
        hour = minute = second = 0;
        timeComparableValue = 0;
    }
    
    Time(string time) {
        set(time);
    }
};

struct Date {
    string date; 
    int
        month,
        day;
    long long dateComparableValue; // Este es un valor que se obtiene de la fecha y se usa para comparar una fecha con otra

    void set(string date) { // Formato de la fecha: Oct 9
        // Elimina los espacios en blanco al final de la cadena en caso de que existan
        while (!date.empty() && date.back() == ' ') {
            date.pop_back();
        }
        
        this->date = date;
        int size = date.size();
        string monthString = "";
        for (int i = 0; i < size; i++) {
            if (date[i] == ' ') {
                monthString = date.substr(0, i);
                break;
            }
        }

        // Convierte el mes a un número
        if (monthString == "Jan") month = 1;
        else if (monthString == "Feb") month = 2;
        else if (monthString == "Mar") month = 3;
        else if (monthString == "Apr") month = 4;
        else if (monthString == "May") month = 5;
        else if (monthString == "Jun") month = 6;
        else if (monthString == "Jul") month = 7;
        else if (monthString == "Aug") month = 8;
        else if (monthString == "Sep") month = 9;
        else if (monthString == "Oct") month = 10;
        else if (monthString == "Nov") month = 11;
        else if (monthString == "Dec") month = 12;

        // Convierte el día a un número
        int spacePos = date.find(' ');
        if (spacePos != string::npos) {
            string dayString = date.substr(spacePos + 1);
            // Trim leading spaces from day string
            while (!dayString.empty() && dayString.front() == ' ') {
                dayString.erase(0, 1);
            }
            day = stoi(dayString);
        } else {
            day = 0; // Default value if no day is found
        }

        // Calcula el valor comparable de la fecha
        dateComparableValue = month * 100 + day; // El valor comparable de la fecha es el mes y el día concatenados
    }
    
    Date() {
        date = "";
        month = day = 0;
    }

    Date(string date) { // Formato de la fecha: Oct 9
        set(date);
    }

    void print() {
        cout << date << endl;
    }
};

struct IpAddress {
    string ip;
    int
        first,
        second,
        third,
        fourth,
        port; // Este es el puerto de la ip (no afecta a la ipComparableValue)
        long long ipComparableValue; // Este es un valor que se obtiene de la ip y se usa para comparar una ip con otra

    void set(string ip) { // Formato de la ip: 10.15.175.231:6166 (siempre tiene el puerto)
        // Initialize all variables to zero
        first = second = third = fourth = port = 0;
        
        // Trim any whitespace
        while (!ip.empty() && isspace(ip.back())) {
            ip.pop_back();
        }
        while (!ip.empty() && isspace(ip.front())) {
            ip.erase(0, 1);
        }
        
        this->ip = ip;
        int size = ip.size();

        // Parse IP components
        int segmentCount = 0;
        size_t pos = 0;
        size_t nextPos = 0;
        
        // Parse the first four segments (IP octets)
        for (int i = 0; i < 4; i++) {
            nextPos = ip.find('.', pos);
            if (nextPos == string::npos && i < 3) {
                // Colon could be present if we're at the last segment
                nextPos = ip.find(':', pos);
                if (nextPos == string::npos) break; // Invalid format
            }
            
            string segment = ip.substr(pos, nextPos - pos);
            int value = stoi(segment);
            
            switch (i) {
                case 0: first = value; break;
                case 1: second = value; break;
                case 2: third = value; break;
                case 3: 
                    // For the fourth segment, we need to check if it contains a colon
                    size_t colonPos = segment.find(':');
                    if (colonPos != string::npos) {
                        fourth = stoi(segment.substr(0, colonPos));
                        port = stoi(segment.substr(colonPos + 1));
                    } else {
                        fourth = value;
                        // Look for port after this segment
                        pos = nextPos + 1;
                        if (pos < ip.size() && ip[nextPos] == ':') {
                            port = stoi(ip.substr(pos));
                        }
                    }
                    break;
            }
            
            if (nextPos == string::npos || ip[nextPos] == ':') break;
            pos = nextPos + 1;
        }
        
        // Calculate the comparable IP value
        ipComparableValue = first * 16777216LL + second * 65536LL + third * 256LL + fourth;
    }
    
    IpAddress() {
        ip = "";
        first = second = third = fourth = port = 0;
        ipComparableValue = 0;
    }

    IpAddress(string ip) { // Formato de la ip: 10.15.175.231:6166 (siempre tiene el puerto)
        set(ip);
    }

    void print() {
        cout << ip << endl;
    }
};

struct Node {
    string value; // Formato: Oct 9 10:32:24 10.15.175.231:6166 Failed password for illegal user guest

    Date date;
    Time time;
    IpAddress ip;
    string message;
    
    // Punteros para el heap binario
    Node* right;
    Node* left;

    Node(string valor) {
        this->value = valor;
        right = nullptr;
        left = nullptr;

        istringstream ss(valor);
        string mes, dia, hora, ip, mensaje;

        // Obtener la fecha
        ss >> mes >> dia;
        string fecha = mes + " " + dia;

        // Obtener la hora
        ss >> hora;

        // Obtener la IP (incluyendo el puerto)
        ss >> ip;

        // Obtener el mensaje
        getline(ss, mensaje);
        mensaje = mensaje.substr(1); // Eliminar el espacio inicial

        // Mostrar los resultados
        this->date = Date(fecha);
        this->time = Time(hora);
        this->ip = IpAddress(ip);
        this->message = mensaje;
    }
};

#endif //NODE_H
