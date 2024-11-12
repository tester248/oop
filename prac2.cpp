#include <iostream>
#include <string>
#include <limits>


using namespace std;

class publication {
private:
    string title;
    float price;

public:
    void add() {
        try {
            cout << "\nEnter the Publication information: " << endl;
            cout << "Enter Title of the Publication: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter Price of Publication: ";
            if (!(cin >> price)) throw invalid_argument("Invalid price input.");
        }
        catch (const invalid_argument& e) {
            cout << e.what() << " Resetting values to default.\n";
            reset();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void display() const {
        cout << "\nTitle of Publication: " << title;
        cout << "\nPublication Price: " << price;
    }

    void reset() {
        title = "";
        price = 0.0;
    }
};

class book : public publication {
private:
    int page_count;

public:
    void add_book() {
        try {
            add();
            cout << "Enter Page Count of Book: ";
            if (!(cin >> page_count)) throw invalid_argument("Invalid page count input.");
        }
        catch (const invalid_argument& e) {
            cout << e.what() << " Resetting values to default.\n";
            reset();
            page_count = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void display_book() const {
        display();
        cout << "\nPage Count: " << page_count;
        cout << "\n";
    }
};

class tape : public publication {
private:
    float play_time;

public:
    void add_tape() {
        add();
        try {
            cout << "Enter Play Duration of the Tape: ";
            if (!(cin >> play_time)) throw invalid_argument("Invalid play time input.");
        }
        catch (const invalid_argument& e) {
            cout << e.what() << " Resetting values to default.\n";
            reset();
            play_time = 0.0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void display_tape() const {
        display();
        cout << "\nPlay Time: " << play_time << " min";
        cout << "\n";
    }
};

int main() {
    book b1[10];
    tape t1[10];
    int ch, b_count = 0, t_count = 0;

    do {
        cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
        cout << "\n1. Add Book";
        cout << "\n2. Add Tape";
        cout << "\n3. Display All Books";
        cout << "\n4. Display All Tapes";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                if (b_count < 10) {
                    b1[b_count].add_book();
                    b_count++;
                } else {
                    cout << "\nBook limit reached!";
                }
                break;
            case 2:
                if (t_count < 10) {
                    t1[t_count].add_tape();
                    t_count++;
                } else {
                    cout << "\nTape limit reached!";
                }
                break;
            case 3:
                cout << "\n* * * * * DISPLAYING ALL BOOKS * * * * *";
                for (int i = 0; i < b_count; i++) {
                    b1[i].display_book();
                }
                break;
            case 4:
                cout << "\n* * * * * DISPLAYING ALL TAPES * * * * *";
                for (int i = 0; i < t_count; i++) {
                    t1[i].display_tape();
                }
                break;
            case 5:
                cout << "\nExiting the system.";
                break;
            default:
                cout << "\nInvalid choice! Please try again.";
        }
    } while (ch != 5);

    return 0;
}
