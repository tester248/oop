#include <iostream>
#include <fstream>
using namespace std;

class person
{
protected:
    string name;
    short age;

public:
    void getdata();
    void disp();
};

void person::getdata()
{
    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your age\n";
    cin >> age;
}

void person::disp()
{
    cout << "Name: " << name << endl
         << "Age: " << age;
}

int main()
{

    char ch;
    person p;
    fstream file;
    
    file.open("group.dat", ios::app | ios::out | ios::in | ios::binary);
    do
    {
        cout << "\nEnter person’s data :";
        p.getdata(); 
        
        file.write((char*)(&p), sizeof(p));
        cout << "Enter another person(y / n) ? ";
        cin >> ch;
    } while (ch =='y');

    file.seekg(0); 
    file.read((char*)(&p), sizeof(p));
    
    while (!file.eof()) 
    {
        cout << "\nPerson :"; 
        p.disp();      
        file.read((char*)(&p), sizeof(p));
    }
    cout << endl;
    return 0;
}