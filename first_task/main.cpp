#include "exercises.h"
#include <iostream>
#include <vector>
#include <string>
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

int main () {

    Exercise* e1 = new Strength(1, "Skullbreaker", "Beginner", 20.0, "To work tricep", "yesterday");
    Exercise* e2 = new Strength(2, "Bench Press", "Intermediate", 40.5, "Enphazis on your chest", "today");
    Exercise* e3 = new Strength(3, "Deadlift", "Advanced", 30.0, "To work tricep", "yesterday");
    Exercise* e4 = new Cardio(4, "Stair walk", "Beginner", 50.0, "To burn fat", "2 days ago");
    Exercise* e5 = new Cardio(5, "Jump rope", "Intermediate", 10.0, "To burn fat", "last week");

    // This Vector gonna act like a BD to save all data.
    vector<Exercise*> exercises;

    // Add exercises to the vector.
    exercises.push_back(e1);
    exercises.push_back(e2);
    exercises.push_back(e3);
    exercises.push_back(e4);
    exercises.push_back(e5);

    while (true){
        cout << endl;
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Comming soon :)" << endl;
        } else if (choice == 2) {
            cout << "Comming soon :)" << endl;
        } else if (choice == 3) {
            cout << "Comming soon :)" << endl;
        } else if (choice == 4) {
            cout << "Comming soon :)" << endl;
        } else if (choice == 5) {
            string level;
            cout << "Please enter you level(Beginner, Intermediate, Advanced): ";
            cin.ignore();
            getline(cin, level);
            for (size_t i = 0; i < exercises.size(); i++) {
                if (exercises[i]->getIntensityLevel() == level) {
                    exercises[i]->showDetail();
                }
            }
        } else if (choice == 6) {
            cout << "Comming soon :)" << endl;
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
