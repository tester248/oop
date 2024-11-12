#include <iostream>

using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "Array elements using pointer:" << endl;
    for (int i = 0; i < 5; ++i) 
    {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }
    cout << "Array elements using array indexing:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Element " << i << ": " << arr[i] << endl;
    }
    return 0;
}
