#include <iostream>
using namespace std;
#include <iostream>
using namespace std;


bool contains(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {

    int M, N;

    cout << "Enter size of array M: ";
    cin >> M;

    cout << "Enter size of array N: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];
    int* C = new int[M + N];

    int sizeC = 0;


    cout << "Enter elements of array M: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }


    cout << "Enter elements of array N: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }


    for (int i = 0; i < M; i++) {
        if (!contains(B, N, A[i]) && !contains(C, sizeC, A[i])) {
            C[sizeC++] = A[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (!contains(A, M, B[i]) && !contains(C, sizeC, B[i])) {
            C[sizeC++] = B[i];
        }
    }

    cout << "Elements that not general for both arrays (without dublicate): ";
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;


    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}