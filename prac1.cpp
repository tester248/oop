#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string address;
    string phoneNo;
    string licenseNo;
    static int count;

public:
    // Default Constructor
    Student() {
        name = "";
        rollNo = 0;
        className = "";
        division = 'A';
    }

    // Parameterized Constructor
    Student(string n, int r, string c, char d) {
        name = n;
        rollNo = r;
        className = c;
        division = d;
    }

    // Copy Constructor
    Student(const Student &s) {
        this->name = s.name;
        this->rollNo = s.rollNo;
        this->className = s.className;
        this->division = s.division;
        this->dob = s.dob;
        this->bloodGroup = s.bloodGroup;
        this->address = s.address;
        this->phoneNo = s.phoneNo;
        this->licenseNo = s.licenseNo;
    }

    // Destructor
    ~Student() {
    }

    // Static member function
    static int getCount() {
        return count;
    }

    friend class StudentDatabase;

    void getData() {
        try {
            cout << "\nEnter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Roll No: ";
            cin >> rollNo;
            if (rollNo <= 0) throw invalid_argument("Invalid Roll Number");

            cout << "Enter Class: ";
            cin.ignore();
            getline(cin, className);

            cout << "Enter Division: ";
            cin >> division;

            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            cin.ignore();
            getline(cin, dob);

            cout << "Enter Blood Group: ";
            getline(cin, bloodGroup);

            cout << "Enter Address: ";
            getline(cin, address);

            cout << "Enter Phone Number: ";
            getline(cin, phoneNo);
            if (phoneNo.length() != 10) throw invalid_argument("Invalid Phone Number");

            cout << "Enter License Number: ";
            getline(cin, licenseNo);
        }
        catch (invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            throw;
        }
    }

    void displayData() {
        cout << "\n----- Student Details -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNo << endl;
        cout << "License Number: " << licenseNo << endl;
    }

    // Static method to increment the count
    static void incrementCount() {
        count++;
    }
};

int Student::count = 0; 

class StudentDatabase {
private:
    Student* students;
    int size;
    int capacity;

public:
    StudentDatabase(int cap = 10) {
        capacity = cap;
        size = 0;
        students = new Student[capacity];
    }

    ~StudentDatabase() {
        delete[] students;
    }

    void addStudent() {
        if (size < capacity) {
            try {
                students[size].getData();
                Student::incrementCount();  
                size++;
            }
            catch (invalid_argument&) {
                cout << "Student not added due to invalid data" << endl;
            }
        }
        else {
            cout << "Database is full!" << endl;
        }
    }

    void displayAll() {
        for (int i = 0; i < size; i++) {
            students[i].displayData();
        }
        cout << "\nTotal Students: " << Student::getCount() << endl;
    }

    void searchByRoll(int roll) {
        for (int i = 0; i < size; i++) {
            if (students[i].rollNo == roll) {
                students[i].displayData();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

int main() {
    StudentDatabase db;
    int choice, roll;

    do {
        cout << "\n----- Student Database System -----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by Roll No" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                db.addStudent();
                break;
            case 2:
                db.displayAll();
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> roll;
                db.searchByRoll(roll);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}