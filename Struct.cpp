#include <iostream>
#include <string>
using namespace std;

// Struct definition for Student
struct Student {
    int id;
    string name;
    float gpa;
};

// Traverse and print details of all students
void traverseAndPrint(const Student students[], int count) {
    cout << "\n================ Student Directory ================\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id 
             << " | Name: " << students[i].name 
             << " | GPA: " << students[i].gpa << "\n";
    }
    cout << "===================================================\n";
}

// Search for a student by ID
void searchStudentByID(const Student students[], int count, int searchID) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == searchID) {
            cout << "\n[Student Found]\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "GPA: " << students[i].gpa << "\n";
            return;
        }
    }
    cout << "\nStudent with ID " << searchID << " was not found.\n";
}

int main() {
    const int NUM_STUDENTS = 5;
    Student students[NUM_STUDENTS];

    // 1. Add 5 students
    students[0] = {101, "Alice Johnson", 3.85};
    students[1] = {102, "Bob Smith", 3.40};
    students[2] = {103, "Charlie Davis", 3.92};
    students[3] = {104, "Diana Prince", 3.65};
    students[4] = {105, "Ethan Hunt", 3.10};

    // 2. Traverse and print their details
    traverseAndPrint(students, NUM_STUDENTS);

    // 3. Search for a student by ID
    int searchID = 103;
    cout << "\nSearching for Student with ID: " << searchID;
    searchStudentByID(students, NUM_STUDENTS, searchID);

    return 0;
}
