//c++ program to demonstrate pointers to base and derived classes
#include <iostream>
using namespace std;

class Base
{
    public:
        virtual void display()
        {
            cout << "This is a base class" << endl;
        }
};

class Derived : public Base
{
    public:
        void display()
        {
            cout << "This is a derived class" << endl;
        }
};

class Derived2 : public Base
{
    public:
        void display()
        {
            cout << "This is another derived class" << endl;
        }
};
int main()
{
    Base *bptr;
    Derived d;
    Derived2 d2;
    bptr = &d;
    bptr->display();
    bptr = &d2;
    bptr->display();
    return 0;
}