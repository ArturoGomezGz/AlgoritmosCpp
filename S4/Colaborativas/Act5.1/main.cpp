#include <iostream>
#include <string>
#include "openHash.h"

using namespace std;

int main() {
    cout << "===== Testing OpenHash with Integer Keys and String Values =====" << endl;
    OpenHash<int, string> studentHashTable(7);
    
    // Test add function
    cout << "\n-- Adding student IDs and names --" << endl;
    studentHashTable.add(12345, "Ana Martinez");
    studentHashTable.add(67890, "Carlos Lopez");
    studentHashTable.add(54321, "Maria Rodriguez");
    studentHashTable.add(98765, "Juan Perez");
    studentHashTable.add(13579, "Sofia Gonzalez");
    
    // Print the hash table after adding elements
    cout << "\n-- Hash table after adding 5 students --" << endl;
    studentHashTable.print();
    
    // Test finding elements
    cout << "\n-- Finding students by ID --" << endl;
    try {
        cout << "Student with ID 12345: " << studentHashTable.find(12345) << endl;
        cout << "Student with ID 98765: " << studentHashTable.find(98765) << endl;
        
        // Try to find a non-existent key
        cout << "Trying to find student with ID 11111..." << endl;
        cout << studentHashTable.find(11111) << endl;
    } 
    catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    // Test updating existing elements
    cout << "\n-- Updating student information --" << endl;
    studentHashTable.add(12345, "Ana Martinez Ruiz"); // Update existing entry
    
    cout << "After updating student 12345:" << endl;
    studentHashTable.print();
    
    // Test collision handling by adding elements that will hash to the same bucket
    cout << "\n-- Testing collision handling --" << endl;
    // Adding values that will likely collide in a table of size 7
    studentHashTable.add(7, "Collision Test 1");
    studentHashTable.add(14, "Collision Test 2");
    studentHashTable.add(21, "Collision Test 3");
    
    cout << "After adding elements with potential collisions:" << endl;
    studentHashTable.print();
    
    // Test removing elements
    cout << "\n-- Removing elements --" << endl;
    studentHashTable.remove(67890);
    cout << "After removing student with ID 67890:" << endl;
    studentHashTable.print();
    
    // Try to remove a non-existent element
    cout << "\n-- Attempting to remove a non-existent element --" << endl;
    try {
        studentHashTable.remove(99999);
    } 
    catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    // Test with string keys
    cout << "\n===== Testing OpenHash with String Keys and Integer Values =====" << endl;
    OpenHash<string, int> courseGrades(5);
    
    // Add course grades
    courseGrades.add("Math", 95);
    courseGrades.add("Science", 88);
    courseGrades.add("History", 92);
    courseGrades.add("Literature", 90);
    courseGrades.add("Programming", 100);
    
    // Print the course grades
    cout << "\n-- Course grades hash table --" << endl;
    courseGrades.print();
    
    // Find some grades
    cout << "\n-- Finding course grades --" << endl;
    try {
        cout << "Math grade: " << courseGrades.find("Math") << endl;
        cout << "Programming grade: " << courseGrades.find("Programming") << endl;
    } 
    catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    // Remove a course
    cout << "\n-- Removing a course --" << endl;
    courseGrades.remove("History");
    cout << "After removing History:" << endl;
    courseGrades.print();
    
    return 0;
}
