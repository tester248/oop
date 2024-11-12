//Code to find area of a triangle using inline functions using oop
#include <iostream>
using namespace std;
class triangle
{
    public:
        inline double area(double b, double h)
        {
            return 0.5*b*h;
        }
};
int main()
{
    triangle t;
    double b, h;
    cout << "Enter base and height of the triangle: ";
    cin >> b >> h;
    cout << "Area of the triangle is: " << t.area(b, h);
    return 0;
}