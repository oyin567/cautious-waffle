#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int currentSize = 0;

// Function to print the array elements
void displayArray(int arr[]) {
    if (currentSize == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Current Array: [ ";
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

// 1. Insert element at position i (0-based indexing)
void insertAt(int arr[], int pos, int value) {
    if (currentSize >= MAX_SIZE) {
        cout << "Error: Array is full!\n";
        return;
    }
    if (pos < 0 || pos > currentSize) {
        cout << "Error: Invalid position!\n";
        return;
    }
    // Shift elements right
    for (int i = currentSize; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    currentSize++;
    cout << "Inserted " << value << " at position " << pos << " successfully.\n";
}

// 2. Delete element at position i (0-based indexing)
void deleteAt(int arr[], int pos) {
    if (currentSize == 0) {
        cout << "Error: Array is empty!\n";
        return;
    }
    if (pos < 0 || pos >= currentSize) {
        cout << "Error: Invalid position!\n";
        return;
    }
    int removedValue = arr[pos];
    // Shift elements left
    for (int i = pos; i < currentSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    currentSize--;
    cout << "Deleted element " << removedValue << " from position " << pos << " successfully.\n";
}

// 3. Search for a value
int searchVal(int arr[], int value) {
    for (int i = 0; i < currentSize; i++) {
        if (arr[i] == value) {
            return i; // Returns zero-based index
        }
    }
    return -1; // Not found
}

// 4. Sort the array using Bubble Sort
void sortArray(int arr[]) {
    for (int i = 0; i < currentSize - 1; i++) {
        for (int j = 0; j < currentSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted in ascending order.\n";
}

int main() {
    int arr[MAX_SIZE];

    // Example Usage:
    insertAt(arr, 0, 45);
    insertAt(arr, 1, 12);
    insertAt(arr, 2, 89);
    insertAt(arr, 1, 23); // Inserts 23 at index 1

    displayArray(arr);

    // Search
    int valToFind = 89;
    int index = searchVal(arr, valToFind);
    if (index != -1) {
        cout << "Value " << valToFind << " found at index " << index << ".\n";
    } else {
        cout << "Value " << valToFind << " not found.\n";
    }

    // Sort
    sortArray(arr);
    displayArray(arr);

    // Delete
    deleteAt(arr, 2);
    displayArray(arr);

    return 0;
}
