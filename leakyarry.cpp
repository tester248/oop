#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    vector<void*> allocatedMemory;
    const size_t allocationSize = 16 * 1024 * 1024; // Allocate 8MB each iteration

    while (true) {
        void* memory = malloc(allocationSize); // Allocate memory
        if (memory == nullptr) {
            cerr << "Memory allocation failed!" << endl;
            break;
        }
        allocatedMemory.push_back(memory);
        cout << "Allocated another 8MB, total allocated: " << allocatedMemory.size() * 8 << "MB" << endl;
    }

    return 0;
}
