#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class person {
protected:
    string name;
    short age;

public:
    void getdata();
    void disp();
};

void person::getdata() {
    cout << "Enter your name:\n";
    cin>>name;
    cout << "Enter your age:\n";
    cin >> age;
}

void person::disp() {
    cout << "Name: " << name << endl
         << "Age: " << age << endl;
}

int main() {
    char ch;
    person p;
    fstream file;
    int choice;

    // Open the file in truncate mode to clear it at the start
    file.open("group.dat", ios::binary | ios::trunc | ios::in | ios::out);
    file.close(); // Close the file immediately after truncating

    
    do {
        cout << "\nChoose an option:\n";
        cout << "1. Write person data to file\n";
        cout << "2. Read person data from file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: { 
                file.open("group.dat", ios::in | ios:: out | ios::binary | ios::app); // Open in append mode
                do {
                    cout << "\nEnter person's data:\n";
                    p.getdata();
                    file.write((char*)(&p), sizeof(p));
                    cout << "Enter another person (y/n)? ";
                    cin >> ch;
                } while (ch == 'y');
                file.close(); 
                break;
            }

            case 2: { 
                file.open("group.dat", ios::binary | ios::in);
                cout << endl << "Reading from data file...";
                
                while (file.read((char*)(&p), sizeof(p))) {
                    cout << "\nPerson:\n";
                    p.disp();
                }
                file.close(); 
                break;
            }

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
