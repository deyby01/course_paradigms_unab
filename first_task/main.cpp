#include "exercises.h"
#include <iostream>
#include <vector>
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

    vector<Exercise*> exercises;
    // Strength e1(1, "Mechanic stair", "Beginner", 30.0, "For burn calories", "yestarday");
    // e1.showDetail();

    // If you want to test basic functionality coment block of white and
    // uncomment and run the code above.

    while (true){
        cout << endl;
        menu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            int tipo;
            cout << "\nType of exercise:" << endl;
            cout << "1. Strength" << endl;
            cout << "2. Cardio" << endl;
            cout << "Option: ";
            cin >> tipo;

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

            // Crear ejercicio
            nuevo->create();

            // Guardar
            exercises.push_back(nuevo);

            // Verificación
            cout << "\nExercise created successfully:\n";
            nuevo->showDetail();
        }

        else if (choice == 7) {
            break;
        }

        else {
            cout << "Option not available." << endl;
        }
    }

    return 0;
}