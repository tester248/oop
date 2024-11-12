#include <iostream>
using namespace std;

class Complex
{

public:
   double real;
   double imag;

   //Default constructor (0 + 0i)
   Complex()
   {
       real = 0;
       imag = 0;
   }

   //Constructor with parameters
   Complex(double r, double i)
   {
       real = r;
       imag = i;
   }

   //Overloading operator + to add 2 complex numbers
   Complex operator+(Complex &c)
   {
       Complex res;
       res.real = this->real + c.real;
       res.imag = this->imag + c.imag;
       return res;
   }

   // Overloading operator * to multiply 2 complex numbers

   Complex operator*(Complex &c)
   {
       Complex res;
       res.real = this->real * c.real - this->imag * c.imag;
       res.imag = this->real * c.imag + this->imag * c.real;
       return res;
   }

   // friend functions for overloading << and >> opeartors
   friend ostream &operator<<(ostream &out, const Complex &c);
   friend istream &operator>>(istream &in, Complex &c);

};
//Overloading << operator to print Complex numbers
ostream &operator<<(ostream &out, const Complex &c) {
   if (c.imag >= 0)
       out << c.real << " + " << c.imag << "i";
   else
       out << c.real << " - " << -c.imag << "i";
   return out;
}

//Overloading >> operator to read Complex numbers
istream &operator>>(istream &in, Complex &c) {
   cout << "Enter Real Part: ";
   in >> c.real;
   cout << "Enter Imaginary Part: ";
   in >> c.imag;
   return in;
}

void displayMenu() {
    cout << "\n=== Complex Number Calculator ===\n";
    cout << "1. Input complex numbers\n";
    cout << "2. Add complex numbers\n";
    cout << "3. Multiply complex numbers\n";
    cout << "4. Display complex numbers\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Complex c1, c2, result;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nEnter first complex number:\n";
                cin >> c1;
                cout << "\nEnter second complex number:\n";
                cin >> c2;
                break;

            case 2:
                result = c1 + c2;
                cout << "\nSum: " << result << endl;
                break;

            case 3:
                result = c1 * c2;
                cout << "\nProduct: " << result << endl;
                break;

            case 4:
                cout << "\nFirst complex number: " << c1;
                cout << "\nSecond complex number: " << c2 << endl;
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 5);

    return 0;
}