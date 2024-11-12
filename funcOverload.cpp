#include <iostream>
using namespace std;

class Swapper {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void swap(float &a, float &b) {
        float temp = a;
        a = b;
        b = temp;
    }

    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    Swapper s;
    
    int x = 1, y = 2;
    float m = 1.1, n = 2.2;
    char c1 = 'A', c2 = 'B';
    
    s.swap(x, y);
    s.swap(m, n);
    s.swap(c1, c2);
    
    cout << "Swapped integers: " << x << " " << y << endl;
    cout << "Swapped floats: " << m << " " << n << endl;
    cout << "Swapped chars: " << c1 << " " << c2 << endl;

    return 0;
}
