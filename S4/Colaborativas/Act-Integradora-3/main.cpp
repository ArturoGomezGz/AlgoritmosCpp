// Arturo Gomez Gomez A07106692
// Gonzalo Flores A01644771

//Bibliografia:
// https://www.geeksforgeeks.org/heap-sort/
// https://www.youtube.com/watch?v=2DmK_H7IdTo

// main.cpp creado con ayuda de Cloude 3.7 Sonnet

#include <iostream>
#include "BinaryHeap.h"

using namespace std;

int main() {
    BinaryHeap heap;
    
    // Read logs from input file
    cout << "Reading from bitacoraHeap.txt..." << endl;
    heap.readFromFile("bitacoraHeap.txt");
    
    // Sort logs by IP address
    cout << "Sorting logs by IP address..." << endl;
    heap.heapSort();
    
    // Write sorted logs to output file
    cout << "Writing sorted logs to bitacora_ordenada.txt..." << endl;
    heap.writeToFile("bitacora_ordenada.txt");
    
    // Count accesses by IP address
    cout << "\nCounting IP accesses..." << endl;
    heap.countIpAccesses();
    
    // Find and display top 10 IPs with most accesses
    heap.findTopIpsByAccess(10);
    
    // Write top 10 IPs to file
    heap.writeTopIpsToFile("ips_con_mayor_acceso.txt", 10);
    
    // Find IP with least recurrence that has at least 5 accesses
    heap.findLeastRecurringIpAboveThreshold(3);
    
    cout << "\nProcess completed successfully!" << endl;
    
    return 0;
}
