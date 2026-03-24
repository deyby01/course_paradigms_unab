#include "exercises.h"
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

    // Strength e1(1, "Mechanical stair", "Beginner", 30.0, "Burning calories and cardio", "yesterday");
    // e1.showDetail();

    // If you want to test basic functionality coment block of white and
    // uncomment and run the code above.
        // Arreglo dinámico de punteros (Polimorfismo / Memoria Dinámica)
    const int MAX_EJERCICIOS = 100; //Lugar donde guardamos los ejercicios que vamos creando
    Exercise* ejercicios[MAX_EJERCICIOS];
    int cantidadEjercicios = 0;

    while (true){
        cout << endl;
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) { //Preguntar si podemos usar switch 
            case 1: { // CREATE EXERCISE
                int typeOpt;
                cout << "Type of exercise to create:\n1. Cardio\n2. Strength\nChoose: ";
                cin >> typeOpt;
                
                // Aplicando Polimorfismo con new
                if (typeOpt == 1) {
                    ejercicios[cantidadEjercicios] = new Cardio();
                } else {
                    ejercicios[cantidadEjercicios] = new Strength();
                }
                ejercicios[cantidadEjercicios]->create();
                cantidadEjercicios++;
                break;
            }
            case 2: { // UPDATE EXERCISE
                int searchId;
                cout << "Enter the ID of the exercise to update: ";
                cin >> searchId;
                
                bool found = false;
                for (int i = 0; i < cantidadEjercicios; i++) {
                    // Tu método deleteExercise() pone el id=0, lo usamos para validar
                    if (ejercicios[i] != nullptr && ejercicios[i]->getId() == searchId && searchId != 0) {
                        ejercicios[i]->update();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Exercise not found." << endl;
                break;
            }
            case 3: { // DELETE EXERCISE
                int searchId;
                cout << "Enter the ID of the exercise to delete: ";
                cin >> searchId;
                
                bool found = false;
                for (int i = 0; i < cantidadEjercicios; i++) {
                    if (ejercicios[i] != nullptr && ejercicios[i]->getId() == searchId && searchId != 0) {
                        char confirm;
                        cout << "Are you sure you want to delete the exercise '" << ejercicios[i]->getName() << "'? (y/n): ";
                        cin >> confirm;
                        
                        // Pregunta de seguridad al usuario
                        if (confirm == 'y' || confirm == 'Y') {
                            ejercicios[i]->deleteExercise(); // Le cambiamos el id a 0 al ejercicio no lo borramos realmente
                            cout << "Exercise deleted successfully." << endl;
                        } else {
                            cout << "Operation cancelled." << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Exercise not found." << endl;
                break;
            }
            case 4: { // Muestra todos los ejercicios
                bool any = false;
                for (int i = 0; i < cantidadEjercicios; i++) {
                    if (ejercicios[i] != nullptr && ejercicios[i]->getId() != 0) {
                        ejercicios[i]->showDetail();
                        cout << "--------------------" << endl;
                        any = true;
                    }
                }
                if (!any) cout << "No exercises to show." << endl;
                break;
            }
            case 7: { // EXIT
                cout << "Exiting..." << endl;
                // Liberar memoria dinámica
                for (int i = 0; i < cantidadEjercicios; i++) {
                    if (ejercicios[i] != nullptr) {
                        delete ejercicios[i];
                    }
                }
                return 0; // Finaliza el programa
            }
            default:
                cout << "Coming soon." << endl;
        }
    }
}
