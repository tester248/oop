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
    cout<<"Enter your name:\n";
    cin>>name;
    cout<<"Enter your age\n";
    cin>>age;
}

void person::disp()
{
    cout<<"Name: "<<name<<endl<<"Age: "<<age;
}

int main()
{
    person p1;
    person p2;
    p1.getdata();

    ofstream out("person.dat", ios::binary);
    out.write(reinterpret_cast<char*>(&p1),sizeof(p1));
    cout<<"Object written to file."<<endl;
    out.close();

    ifstream in("person.dat", ios::binary);
    cout<<"Reading File..."<<endl;
    in.read(reinterpret_cast<char*>(&p2),sizeof(p1));
    p2.disp();
    in.close();
    

}