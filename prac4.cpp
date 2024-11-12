#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Employee {
    string name;
    int id;
    double salary;
public:
    void accept() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: $" << salary << endl;
    }
};
int main() {
    Employee employees[5];
    fstream file;
    int n;
    file.open("employees.txt", ios::out | ios::binary);
    cout << "Enter the number of employees to store (up to 5): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter information for Employee " << i + 1 << ":\n";
        employees[i].accept();
        file.write(reinterpret_cast<char*>(&employees[i]), sizeof(employees[i]));
    }
    file.close();
    file.open("employees.txt", ios::in | ios::binary);
    cout << "\nInformation of Employees:\n";
    for (int i = 0; i < n; i++) {
        file.read(reinterpret_cast<char*>(&employees[i]), sizeof(employees[i]));
        cout << "\nEmployee " << i + 1 << ":\n";
        employees[i].display();
    }
    file.close();

    return 0;
}
