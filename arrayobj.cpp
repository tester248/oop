#include <iostream>
using namespace std;

class Demo 
{
    int id;
    string name;
    public:
        void getdata();
        void display();
};

void Demo::getdata()
{
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
}

void Demo::display()
{
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
}

int main() 
{
    Demo d[5];
    for (int i = 0; i < 5; i++)
    {
        d[i].getdata();
    }
    for (int i = 0; i < 5; i++)
    {
        d[i].display();
    }
}