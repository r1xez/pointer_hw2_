#include <iostream>
using namespace std;


int* LocateOfArray(int size) {
    return new int[size];
}


void initializeArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
}


void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


void deleteArray(int* array) {
    delete[] array;
}


void AddToArrayInTheEnd(int*& array, int& size, int value) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = value;
    size++;
    delete[] array;
    array = newArray;
}


int* insertElement(int* array, int& size, int index, int value) {
    if (index < 0 || index > size) {
        cout << "Invalid index!" << endl;
        return array;
    }

    int* newArray = new int[size + 1];
    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    newArray[index] = value;
    for (int i = index; i < size; i++) {
        newArray[i + 1] = array[i];
    }
    size++;
    delete[] array;
    return newArray;
}


int* deleteElement(int* array, int& size, int index) {
    if (index < 0  || index >= size) {
        cout << "Invalid index!" << endl;
        return array;
    }

    int* newArray = new int[size - 1];
    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArray[i - 1] = array[i];
    }
    size--;
    delete[] array;
    return newArray;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;


    int* array = LocateOfArray(size);


    initializeArray(array, size);


    printArray(array, size);


    int value;
    cout << "Enter the value to add to the array: ";
    cin >> value;
    AddToArrayInTheEnd(array, size, value);
    printArray(array, size);


    int index;
    cout << "Enter the index to insert the value: ";
    cin >> index;
    cout << "Enter the value to insert: ";
    cin >> value;
    array = insertElement(array, size, index, value);
    printArray(array, size);


    cout << "Enter the index to delete: ";
    cin >> index;
    array = deleteElement(array, size, index);
    printArray(array, size);


    deleteArray(array);

    return 0;
}