#include <iostream>
#include <fstream>
using namespace std;

const long MAX = 1000000;

int buff[MAX]; //buffer array

int main()
{
    for(int i = 0; i < MAX ; i++) //fill buffer
        buff[i] = i;
    
    ofstream os("bdata.txt", ios::binary);

    os.write(reinterpret_cast<char*>(buff), MAX*sizeof(long));
    os.close();

    for(int i = 0; i < MAX; i++)  //empty the buffer array
        buff[i] = 0;

    ifstream is("bdata.txt", ios::binary);

    is.read(reinterpret_cast<char*>(buff), MAX*sizeof(long));

    for(int i = 0 ; i<MAX ; i++)
    {
        cout << buff[i] << ' ';
    }

    is.close();


}

