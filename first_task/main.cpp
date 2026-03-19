#include <iostream>
using namespace std;

void menu() {
    cout << "---- Main Menu ----" << endl;
    cout << "1. Create Exercise" << endl;
    cout << "2. Update Exercise" << endl;
    cout << "3. Delete Exercise" << endl;
    cout << "4. Show Exercise Detail" << endl;
    cout << "5. Search Exercise by Level" << endl;
    cout << "6. Generate Routine" << endl;
    cout << "7. Exit" << endl;
}

int main (int argc, char *argv[]) {
    while (true){
        cout << endl;
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice != 7) {
            cout << "comming soon." << endl;
        } else {
            break;
        }
    }
    return 0;
}
