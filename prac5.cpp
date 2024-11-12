#include <iostream>
using namespace std;

template <class T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

template <class T>
void inputArray(T arr[], int n) {
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

template <class T>
void outputArray(T arr[], int n) {
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the number of elements in the integer array: ";
    cin >> n;
    int intArr[n];
    inputArray(intArr, n);
    selectionSort(intArr, n);
    outputArray(intArr, n);

    cout << "Enter the number of elements in the float array: ";
    cin >> n;
    float floatArr[n];
    inputArray(floatArr, n);
    selectionSort(floatArr, n);
    outputArray(floatArr, n);

    return 0;
}