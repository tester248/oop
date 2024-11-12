#include <iostream>
using namespace std;

// Function to be pointed to
int add(int a, int b) {
    return a + b;
}

int main() {
    // Declaration of function pointer
    int (*funcPtr)(int, int);

    // Referencing: Assigning function address to pointer
    funcPtr = add;

    // Dereferencing: Calling the function using the pointer
    int result = (*funcPtr)(5, 3);

    cout << "The sum is: " << result << endl;

    return 0;
}
