#include <iostream>
using namespace std;

bool proste(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; 
    }
    return true;
}

int* removeProste(int* arr, int& size) {
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        if (!proste(arr[i])) { 
            arr[newSize++] = arr[i];
       }
   }

    size = newSize;
    return arr; 
}

int main() {
    int size = 9;
    int* arr = new int[size] { 1, 2, 3, 4, 5, 6, 7, 8,9 };

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   arr = removeProste(arr, size);

    cout << "Array after removing prosti numbers: ";
   for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
