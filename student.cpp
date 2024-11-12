#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float mark;

public:
    void setData();
    void display();
};

void Student::setData()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter mark: ";
    cin >> mark;
}
void Student::display()
{
    cout << "Name: " << name << endl;
    cout << "Roll Number: " << roll << endl;
    cout << "Mark: " << mark << endl;
}
int main() {
    Student s;
    s.setData();
    s.display();
    return 0;
}
