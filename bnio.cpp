#include <iostream>
#include <fstream>
using namespace std;

const long MAX = 100;

int buff[MAX]; //buffer array

int main()
{
    for(int i = 0; i < MAX ; i++) //fill buffer
        buff[i] = i;
    
    fstream file("bdata.txt", ios::binary);

    file.write(reinterpret_cast<char*>(buff), MAX*sizeof(int));
    file.close();

    for(int i = 0; i < MAX; i++)  //empty the buffer array
        buff[i] = 0;

    fstream file1("bdata.txt", ios::binary|ios::in);
    file1.read(reinterpret_cast<char*>(buff), MAX*sizeof(int));

    for(int i = 0 ; i<MAX ; i++)
    {
        cout << buff[i] << ' ';
    }

    file1.close();

    return 0;

}

