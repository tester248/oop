#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }
    double sub(double a, double b) {
        return a - b;
    }
    double mul(double a, double b) {
        return a * b;
    }
    double div(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

int main() {
    Calculator calc;
    double num1 = 10.5, num2 = 2.5;

    cout << "Addition: " << calc.add(num1, num2) << endl;
    cout << "Subtraction: " << calc.sub(num1, num2) << endl;
    cout << "Multiplication: " << calc.mul(num1, num2) << endl;
    cout << "Division: " << calc.div(num1, num2) << endl;

    return 0;
}
