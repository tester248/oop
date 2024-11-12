#include <iostream>

using namespace std;

int main() {
  // Null Pointer
  int *ptr1 = nullptr; // Initialize ptr1 as a null pointer

  if (ptr1 == NULL) {
    cout << "ptr1 is a null pointer\n";
  }

  // Void Pointer
  void *ptr2;  // Declare a void pointer
  int num = 10;
  ptr2 = &num; // Assign the address of an integer to the void pointer
  // You cannot directly dereference a void pointer
  // To use the value, cast it back to the original type
  cout<<"Value pointed to by ptr2: " << *(int*)ptr2 << endl;
  return 0;
}