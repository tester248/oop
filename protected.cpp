#include <iostream>
using namespace std;

class Base {
protected:
    int protectedVar;

public:
    Base()
    {
        protectedVar = 0;
    }

    void show() {
        cout << "Protected Variable: " << protectedVar << endl;
    }
};

class Derived : protected Base {
public:
    Derived(int x) {
        protectedVar = x;
    }

    void accessProtectedVar() {
        cout << "Accessing Protected Variable from Derived Class: " << protectedVar << endl;
    }
};

int main() {
    Derived obj(10);
    obj.accessProtectedVar();
    return 0;
}