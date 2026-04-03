#include "exercises.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

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
    cout << endl;
    cout << "1. Beginner" << endl;
    cout << "2. Intermediate" << endl;
    cout << "3. Advanced" << endl;
    cout << "4. High Performance" << endl;
    cout << "Enter your option: ";
}

int exerciseType() {
    int tipo;
    cout << "\nType of exercise:" << endl;
    cout << "1. Strength" << endl;
    cout << "2. Cardio" << endl;
    cout << "Option: ";
    cin >> tipo;
    return tipo;
}

void comingSoon() {
    cout << "Coming soon :)" << endl;
}

string levelChoice(int levelChoice) {
    string level;
    while (levelChoice < 1 || levelChoice > 4) {
        cout << "Invalid level choice. Please enter a number between 1 and 4." << endl;
        cout << "Enter your option: ";
        cin >> levelChoice;
    }

    if (levelChoice == 1) level = "Beginner";
    else if (levelChoice == 2) level = "Intermediate";
    else if (levelChoice == 3) level = "Advanced";
    else if (levelChoice == 4) level = "High Performance";

    return level;
}

void loadFixtures(vector<Exercise*>& exercises) {
    // (Tu carga de datos se mantiene igual aquí)
}

int main () {

    // This Vector gonna act like a BD to save all data.
    vector<Exercise*> exercises;
    loadFixtures(exercises);

    // Get the current week number to track exercise usage.
    time_t now = time(0);
    tm* date = localtime(&now);
    int currentWeek = date->tm_yday / 7;

    while (true){
        cout << endl;
        menu();

        int choice;
        cin >> choice;

        // Validación de input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {

            int tipo = exerciseType();

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            cin.ignore();

            Exercise* nuevo;

            if (tipo == 1) {
                nuevo = new Strength();
            } 
            else if (tipo == 2) {
                nuevo = new Cardio();
            } 
            else {
                cout << "Invalid option." << endl;
                continue;
            }

            // Create exercise
            nuevo->create();

            // Save
            exercises.push_back(nuevo);

            // Verification
            cout << "\nExercise created successfully:\n";
            nuevo->showDetail();
        }

        else if (choice == 2) {
            comingSoon();
        }

        else if (choice == 3) {
            comingSoon();
        }

        else if (choice == 4) {
            cout << "Exercise Details:" << endl;

            for (size_t i = 0; i < exercises.size(); i++) {
                cout << i + 1 << ". " << exercises[i]->getName() << endl;
            }

            cout << "Select an exercise to view details: ";
            size_t exerciseChoice;
            cin >> exerciseChoice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            if (exerciseChoice < 1 || exerciseChoice > exercises.size()) {
                cout << "Invalid exercise choice." << endl;
            } else {
                exercises[exerciseChoice - 1]->showDetail();
            }
        }

        else if (choice == 5) {
            cout << "What level do you want to search?" << endl;

            int levelOption;
            levels();
            cin >> levelOption;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            string level = levelChoice(levelOption);

            for (size_t i = 0; i < exercises.size(); i++) {
                if (exercises[i]->getIntensityLevel() == level) {
                    exercises[i]->showDetail();
                }
            }
        }

        else if (choice == 6) {
            cout << "===== Exercise Routine =====" << endl;

            cout << "How much exercises do you want: ";
            size_t numExercises;
            cin >> numExercises;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            cout << "What level do you want for your routine?" << endl;

            int levelOption;
            levels();
            cin >> levelOption;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            string level = levelChoice(levelOption);

            double totalTime = 0.0;
            vector<Exercise*> routine;

            for (size_t i = 0; i < exercises.size(); i++) {
                if (exercises[i]->getIntensityLevel() == level &&
                    currentWeek - exercises[i]->getLastUsed() >= 2) {

                    routine.push_back(exercises[i]);
                    exercises[i]->setLastUsed(currentWeek);

                    if (routine.size() == numExercises) break;
                }
            }

            if (routine.size() < numExercises) {
                cout << "Not enough exercises available for the selected level." << endl;
            } else {
                cout << "====== Generated Routine =====" << endl;

                for (size_t i = 0; i < numExercises; i++) {
                    routine[i]->showDetail();
                    totalTime += routine[i]->getEstimatedTime();
                }

                cout << "Total Estimated Time: " << totalTime << " minutes" << endl;
            }
        }

        else if (choice == 7) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        else {
            cout << "Invalid choice." << endl;
        }
    }

    // Clean up memory.
    for (size_t i = 0; i < exercises.size(); i++) {
        delete exercises[i];
    }

    return 0;
}