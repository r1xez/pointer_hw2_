#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

void distributionElement(int* arr, int size, int*& positiveArr, int& positiveSize, int*& negativeArr, int& negativeSize, int*& zeroArr, int& zeroSize) {
    positiveSize = negativeSize = zeroSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveSize++;
        }
        else if (arr[i] < 0) {
            negativeSize++;
        }
        else {
            zeroSize++;
        }
    }

    positiveArr = new int[positiveSize];
    negativeArr = new int[negativeSize];
    zeroArr = new int[zeroSize];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveArr[posIndex++] = arr[i];
        }
        else if (arr[i] < 0) {
            negativeArr[negIndex++] = arr[i];
        }
        else {
            zeroArr[zeroIndex++] = arr[i];
        }
    }
}

void printArray(int* arr, int size, const char description[]) {
    cout << description << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 9;
    int* arr = new int[size] { 3, -1, 0, 7, -5, 0, 2, -8, 0 };

    int* positiveArr = nullptr;
    int* negativeArr = nullptr;
    int* zeroArr = nullptr;
    int positiveSize, negativeSize, zeroSize;

    distributionElement(arr, size, positiveArr, positiveSize, negativeArr, negativeSize, zeroArr, zeroSize);

    printArray(positiveArr, positiveSize, "Positive elements");
    printArray(negativeArr, negativeSize, "Negative elements");
    printArray(zeroArr, zeroSize, "Zero elements");


    delete[] positiveArr;
    delete[] negativeArr;
    delete[] zeroArr;
    delete[] arr;
    return 0;
}