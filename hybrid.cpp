#include <iostream>
using namespace std;

class Vehicle
{
    public:
        void display()
        {
            cout << "This is a vehicle" << endl;
        }
};

class Car : public virtual Vehicle
{
    public:
        void fill()
        {
            cout << "Petrol is being filled" << endl;
        }
};

class ElectricCar : public virtual Vehicle
{
    public:
        void charge()
        {
            cout << "Car is charging" << endl;
        }
};

class HybridCar: public Car, public ElectricCar
{
    public:
        void run()
        {
            cout << "Hybrid car runs on both battery and fuel" << endl;
        }
};

int main()
{
    //Vehicle *v;
    //v->display();
    HybridCar h;
    h.display();
    h.fill();
    h.charge();
    h.run();
    return 0;
}
