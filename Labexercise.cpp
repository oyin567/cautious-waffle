#include <iostream>
#include <string>

using namespace std;

// Struct for Question 4
struct Book {
    int id;
    string title;
};

int main() {
    // 1. Declare an int variable and pointer to it.
    int num = 42;
    int *ptr = &num;

    // 2. Print variable value using both variable and pointer.
    cout << "2. Value using variable (num): " << num << endl;
    cout << "   Value using pointer (*ptr): " << *ptr << endl;

    // 3. Use new to allocate array of 5 integers, store values, then delete.
    int *arr = new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10; // Store values: 10, 20, 30, 40, 50
    }

    cout << "3. Dynamic array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocate memory
    delete[] arr;
    arr = nullptr; // Good practice

    // 4. Create a struct Book (ID, Title). Create 20 books using pointers.
    Book *books = new Book[20];

    // Populate data for the 20 books
    for (int i = 0; i < 20; i++) {
        books[i].id = i + 1;
        books[i].title = "Book Title " + to_string(i + 1);
    }

    // Print a few books to verify
    cout << "4. Sample created books using pointers (Showing first 3):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "   ID: " << (books + i)->id << ", Title: " << (books + i)->title << endl;
    }

    // Deallocate dynamic struct array
    delete[] books;
    books = nullptr;

    return 0;
}
