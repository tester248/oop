#include <iostream>
using namespace std;

template <class T>
void selectionSort(T arr[], int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        int minIndex = i; 
        for (int j = i + 1; j < n; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j; 
            }
        }

        if (minIndex != i) 
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

template <class T>
void printArray(T arr[], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int intArr[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Original integer array:\n";
    printArray(intArr, intSize);
    selectionSort(intArr, intSize);
    cout << "Sorted integer array:\n";
    printArray(intArr, intSize);

    double doubleArr[] = {64.5, 25.2, 12.3, 22.1, 11.0};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "\nOriginal double array:\n";
    printArray(doubleArr, doubleSize);
    selectionSort(doubleArr, doubleSize);
    cout << "Sorted double array:\n";
    printArray(doubleArr, doubleSize);

    return 0;
}
