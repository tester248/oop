#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
    string name;
    string dob;
    string phone;

    Person(string n, string d, string p) {
        name = n;
        dob = d;
        phone = p;
    }

    bool operator<(const Person& other) const {
        return name < other.name;
    }
};

void printRecord(const Person& p) {
    cout << "Name: " << p.name << ", DOB: " << p.dob << ", Phone: " << p.phone << endl;
}

int main() {
    vector<Person> people;
    people.push_back(Person("Demo Person", "2001-04-11", "1234567890"));
    people.push_back(Person("Random Name", "1975-02-17", "5825839592"));
    people.push_back(Person("Ashwin Mathur", "1965-06-16", "9999998888"));

    sort(people.begin(), people.end());

    cout << "Sorted Records:" << endl;
    for (const auto& person : people) {
        printRecord(person);
    }

    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);

    auto it = find_if(people.begin(), people.end(), [&searchName](const Person& p) {
        return p.name == searchName;
    });

    if (it != people.end()) {
        cout << "Record found: " << endl;
        printRecord(*it);
    } else {
        cout << "Record not found." << endl;
    }

    return 0;
}
