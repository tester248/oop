#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base b;
    Derived d;
    Base *bptr;
    bptr = &b;
    bptr->display();
    bptr = &d;
    bptr->display();
    return 0;
}
