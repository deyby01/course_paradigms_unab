#include "exercises.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void menu() {
    cout << "\n---- Main Menu ----" << endl;
    cout << "1. Create Exercise" << endl;
    cout << "2. Update Exercise" << endl;
    cout << "3. Delete Exercise" << endl;
    cout << "4. Show Exercise Detail" << endl;
    cout << "5. Search Exercise by Level" << endl;
    cout << "6. Generate Routine" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

void levels() {
    cout << "\nWhat level do you want to search?" << endl;
    cout << "1. Beginner" << endl;
    cout << "2. Intermediate" << endl;
    cout << "3. Advanced" << endl;
    cout << "4. High Performance" << endl;
    cout << "Enter your option: ";
}

int main () {

    Exercise* e1 = new Strength(1, "Skullbreaker", "Beginner", 20.0, "To work tricep", "last week");
    Exercise* e2 = new Strength(2, "Bench Press", "Intermediate", 40.5, "Enphazis on your chest", "This week");
    Exercise* e3 = new Strength(3, "Deadlift", "Advanced", 30.0, "To work tricep", "1 week ago");
    Exercise* e4 = new Strength(4, "Squat", "High Performance", 50.0, "To work legs", "2 weeks ago");
    Exercise* e5 = new Cardio(5, "Stair walk", "Beginner", 50.0, "To burn fat", "2 weeks ago");
    Exercise* e6 = new Cardio(6, "Jump rope", "Intermediate", 10.0, "To burn fat", "last week");
    Exercise* e7 = new Cardio(7, "Running", "Advanced", 30.0, "To burn fat", "This week");
    Exercise* e8 = new Cardio(8, "Cycling", "High Performance", 60.0, "To burn fat", "1 week ago");

    // This Vector gonna act like a BD to save all data.
    vector<Exercise*> exercises;

    // Add exercises to the vector.
    exercises.push_back(e1);
    exercises.push_back(e2);
    exercises.push_back(e3);
    exercises.push_back(e4);
    exercises.push_back(e5);
    exercises.push_back(e6);
    exercises.push_back(e7);
    exercises.push_back(e8);

    while (true){
        cout << endl;
        menu();
        int choice;
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
            int levelChoice;
            levels();
            cin >> levelChoice;

            if (levelChoice == 1) {
                level = "Beginner";
            } else if (levelChoice == 2) {
                level = "Intermediate";
            } else if (levelChoice == 3) {
                level = "Advanced";
            } else if (levelChoice == 4) {
                level = "High Performance";
            }

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

    // Clean up memory.
    for (size_t i = 0; i < exercises.size(); i++) {
        delete exercises[i];
    }

    return 0;
}
