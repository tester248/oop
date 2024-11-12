/*
Formatted I/O
using insertion and extraction operators
>> and <<
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch = 'a';
    int i = 10;
    double d = 10.11;
    string str1 = "Ashwin";
    string str2 = "Mathur";
    string str3 = "Appended text";

    ofstream outfile("demo.txt");

    outfile << ch <<endl
        << i << ' ' << d << endl << str1 << ' ' << str2 << endl << "Random text";
    cout <<"Data written to file"<<endl;

    outfile.close();

    ifstream infile;
    infile.open("demo.txt");

    cout<<"Reading file..."<< endl <<infile.rdbuf()<<endl;

    infile.close();


    ofstream ofile;
    ofile.open("demo.txt", ios::app);
    ofile << endl;
    for(int i = 0; i < str3.size(); i++)
    {
        ofile.put( str3[i] );
    }

    cout << "str3 appended to file."<<endl;
    ofile.close();


    ifstream ifile("demo.txt");
    cout<<endl<<"Reading file again..."<<endl;
    while (!ifile.eof()) 
    {
        ifile.get(ch);
        if (!ifile.eof()) 
        {
            cout << ch;
        }
    }

    cout<<endl;
    ifile.close();


    return 0;
}