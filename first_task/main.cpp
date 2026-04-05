#include "exercises.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Show the main menu options to the user.
void menu() {
    cout << "\n---- Main Menu ----" << endl;
    cout << "1. Create Exercise" << endl;
    cout << "2. Update Exercise" << endl;
    cout << "3. Delete Exercise" << endl;
    cout << "4. Show Exercise Detail" << endl;
    cout << "5. Search Exercise by Level" << endl;
    cout << "6. Generate Routine" << endl;
    cout << "7. Exit" << endl;
}

// Show the intensity levels options to the user.
void levels() {
    cout << endl;
    cout << "1. Beginner" << endl;
    cout << "2. Intermediate" << endl;
    cout << "3. Advanced" << endl;
    cout << "4. High Performance" << endl;
}

// Show the exercise types options to the user.
void exerciseType() {
    cout << "\nType of exercise:" << endl;
    cout << "1. Strength" << endl;
    cout << "2. Cardio" << endl;
}

/**
 * Converts a numeric choice for intensity level into its corresponding string representation.
 *
 * @param levelChoice An integer representing the user's choice of intensity level (1-4).
 * @return A string corresponding to the selected intensity level ("Beginner", "Intermediate", "Advanced", or "High Performance").
 */
string levelChoice(int levelChoice) {
    string level;

    if (levelChoice == 1) level = "Beginner";
    else if (levelChoice == 2) level = "Intermediate";
    else if (levelChoice == 3) level = "Advanced";
    else if (levelChoice == 4) level = "High Performance";

    return level;
}

/**
 * Validates that the user's input is a number within the specified range.
 * If the input is invalid, it prompts the user to enter a valid option until a correct one is provided.
 *
 * @param min The minimum valid option (inclusive).
 * @param max The maximum valid option (inclusive).
 * @return The validated option as an integer.
 */
int validateOption(int min, int max){
    cout << "¸\nEnter your option: ";
    int option;
    while (true) {
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number: ";

        } else if (option < min || option > max) {
            cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";

        } else {
            return option;
        }
    }
}

// Load a set of predefined exercises into the provided vector to serve as initial data for the application.
void loadFixtures(vector<Exercise*>& exercises) {
    // ===================== STRENGTH =====================
    // --- Beginner ---
    exercises.push_back(new Strength("Skull Crusher", "Beginner", 15.0, "Lie on a bench holding a barbell with arms extended, lower the bar toward your forehead by bending your elbows, then extend back up to target triceps", 3));
    exercises.push_back(new Strength("Dumbbell Curl", "Beginner", 12.0, "Stand with a dumbbell in each hand, curl them up by bending your elbows while keeping upper arms still, then lower slowly to work biceps", 5));
    exercises.push_back(new Strength("Knee Push-Up", "Beginner", 10.0, "Place your knees on the floor with hands shoulder-width apart, lower your chest to the ground and push back up to build chest and tricep strength", 2));
    exercises.push_back(new Strength("Goblet Squat", "Beginner", 15.0, "Hold a dumbbell vertically against your chest, squat down keeping your back straight and knees over toes, then stand back up to work quads and glutes", 7));
    exercises.push_back(new Strength("Lat Pulldown", "Beginner", 14.0, "Sit at the pulldown machine, grip the bar wide and pull it down to your upper chest while squeezing your shoulder blades together to target lats", 1));
    exercises.push_back(new Strength("Leg Press", "Beginner", 16.0, "Sit on the leg press machine with feet shoulder-width apart on the platform, lower the weight by bending your knees, then push back up to work quads and glutes", 4));
    exercises.push_back(new Strength("Dumbbell Shoulder Press", "Beginner", 12.0, "Sit on a bench with back support, hold dumbbells at shoulder height and press them overhead until arms are fully extended to work deltoids", 6));
    exercises.push_back(new Strength("Cable Row", "Beginner", 14.0, "Sit at the cable row machine with feet on the platform, pull the handle toward your abdomen while keeping your back straight to target mid-back muscles", 8));
    exercises.push_back(new Strength("Tricep Pushdown", "Beginner", 10.0, "Stand at a high pulley cable, grip the bar with palms facing down and push it toward the floor by extending your elbows to isolate triceps", 3));
    exercises.push_back(new Strength("Leg Curl", "Beginner", 12.0, "Lie face down on the leg curl machine, hook your ankles under the pad and curl your heels toward your glutes to work hamstrings", 9));
    // --- Intermediate ---
    exercises.push_back(new Strength("Bench Press", "Intermediate", 25.0, "Lie on a flat bench, grip the barbell slightly wider than shoulder-width, lower it to your mid-chest and press back up to work pectorals and triceps", 10));
    exercises.push_back(new Strength("Barbell Row", "Intermediate", 20.0, "Hinge forward at the hips with a slight knee bend, pull the barbell from arm's length up to your lower ribcage squeezing your back at the top", 12));
    exercises.push_back(new Strength("Overhead Press", "Intermediate", 18.0, "Stand with the barbell at shoulder height, press it straight overhead locking out your arms while bracing your core for stability", 11));
    exercises.push_back(new Strength("Romanian Deadlift", "Intermediate", 22.0, "Hold a barbell at hip height, push your hips back and lower the bar along your legs keeping a slight knee bend until you feel a hamstring stretch, then drive hips forward", 14));
    exercises.push_back(new Strength("Incline Dumbbell Press", "Intermediate", 20.0, "Set the bench at 30-45 degrees, press dumbbells up from chest level until arms are extended to emphasize the upper chest", 13));
    exercises.push_back(new Strength("Barbell Curl", "Intermediate", 15.0, "Stand holding a barbell with an underhand grip, curl it up toward your shoulders without swinging your body, then lower with control to work biceps", 15));
    exercises.push_back(new Strength("Dumbbell Lunge", "Intermediate", 20.0, "Hold a dumbbell in each hand, step forward and lower your back knee toward the floor, then push through the front foot to return and work quads and glutes", 16));
    exercises.push_back(new Strength("Face Pull", "Intermediate", 12.0, "Set a cable pulley at face height with a rope attachment, pull toward your face spreading the rope ends apart to target rear delts and rotator cuff", 10));
    exercises.push_back(new Strength("Dips", "Intermediate", 15.0, "Grip parallel bars, lower your body by bending your elbows until your upper arms are parallel to the floor, then press back up to work chest and triceps", 17));
    exercises.push_back(new Strength("Hack Squat", "Intermediate", 22.0, "Position yourself in the hack squat machine with shoulders under the pads, squat down until thighs are parallel, then push up to target quads with less spinal load", 18));
    // --- Advanced ---
    exercises.push_back(new Strength("Deadlift", "Advanced", 30.0, "Stand with feet hip-width apart over the barbell, grip it firmly, drive through your heels and extend hips and knees simultaneously keeping the bar close to your body", 20));
    exercises.push_back(new Strength("Front Squat", "Advanced", 28.0, "Rest the barbell on your front deltoids with elbows high, squat deep keeping your torso upright to heavily target quads and core", 22));
    exercises.push_back(new Strength("Weighted Pull-Up", "Advanced", 20.0, "Attach extra weight to a dip belt, hang from a bar with arms extended and pull yourself up until your chin clears the bar to build lats and biceps", 19));
    exercises.push_back(new Strength("Paused Bench Press", "Advanced", 25.0, "Perform a standard bench press but pause the bar on your chest for 2 seconds before pressing up to build explosive strength off the chest", 21));
    exercises.push_back(new Strength("Barbell Hip Thrust", "Advanced", 22.0, "Sit on the floor with your upper back against a bench, place a loaded barbell across your hips and drive upward squeezing glutes hard at the top", 23));
    exercises.push_back(new Strength("Pendlay Row", "Advanced", 20.0, "With the barbell on the floor, hinge forward until your back is parallel to the ground and explosively row the bar to your lower chest, returning it to the floor each rep", 24));
    exercises.push_back(new Strength("Bulgarian Split Squat", "Advanced", 24.0, "Place your rear foot on a bench behind you, hold dumbbells and squat on the front leg until your rear knee nearly touches the floor for unilateral quad and glute work", 25));
    exercises.push_back(new Strength("Close Grip Bench Press", "Advanced", 22.0, "Lie on a flat bench and grip the barbell with hands about shoulder-width apart, lower to your chest and press up to shift emphasis onto triceps", 20));
    exercises.push_back(new Strength("Deficit Deadlift", "Advanced", 30.0, "Stand on a raised platform or plates and perform a deadlift from this lower starting position to increase range of motion and build strength off the floor", 26));
    exercises.push_back(new Strength("Weighted Dips", "Advanced", 18.0, "Attach weight to a dip belt and perform dips on parallel bars going deeper than bodyweight dips to increase stimulus on chest and triceps", 27));
    // --- High Performance ---
    exercises.push_back(new Strength("Power Clean", "High Performance", 35.0, "Start with the barbell on the floor, pull explosively by extending hips and knees, then catch the bar at shoulder height in a front rack position", 30));
    exercises.push_back(new Strength("Snatch", "High Performance", 40.0, "Grip the barbell wide, pull it from the floor and in one explosive motion receive it overhead with arms locked out while dropping into a squat", 32));
    exercises.push_back(new Strength("Clean and Jerk", "High Performance", 40.0, "Clean the barbell to your shoulders in one pull, then dip your knees and drive the bar overhead locking your arms while splitting your feet", 35));
    exercises.push_back(new Strength("Back Squat", "High Performance", 45.0, "Place a heavy barbell across your upper traps, unrack it and squat deep with control, then drive through your feet to stand for maximum leg and core development", 33));
    exercises.push_back(new Strength("Pause Deadlift", "High Performance", 35.0, "Perform a deadlift but pause for 3 seconds at knee height to build isometric strength and reinforce proper positioning in the hardest part of the lift", 31));
    exercises.push_back(new Strength("Push Press", "High Performance", 25.0, "Hold the barbell at shoulder height, dip your knees slightly and use leg drive to help press the bar overhead allowing you to move more weight than a strict press", 34));
    exercises.push_back(new Strength("Zercher Squat", "High Performance", 30.0, "Cradle the barbell in the crook of your elbows against your torso and squat deep to heavily challenge your core, upper back and quads simultaneously", 36));
    exercises.push_back(new Strength("Rack Pull", "High Performance", 28.0, "Set the barbell on safety pins at knee height in the rack, grip and pull to lockout to overload the top portion of the deadlift and build back thickness", 37));
    exercises.push_back(new Strength("Muscle-Up", "High Performance", 20.0, "Hang from a bar, perform an explosive pull-up and transition over the bar into a dip to complete the rep, working your entire upper body in one movement", 38));
    exercises.push_back(new Strength("Pistol Squat", "High Performance", 18.0, "Stand on one leg with the other extended in front of you, squat all the way down and stand back up for maximum single-leg strength and balance", 39));

    // ===================== CARDIO =====================
    // --- Beginner ---
    exercises.push_back(new Cardio("Stair Walk", "Beginner", 20.0, "Walk up and down a flight of stairs at a steady pace to gradually raise your heart rate with a low-impact activity", 4));
    exercises.push_back(new Cardio("Brisk Walking", "Beginner", 30.0, "Walk at a fast pace where you can still talk but feel slightly out of breath to build a basic cardiovascular foundation", 2));
    exercises.push_back(new Cardio("Stationary Bike", "Beginner", 25.0, "Pedal at low to moderate resistance on a stationary bike keeping a consistent rhythm to improve heart and lung endurance", 5));
    exercises.push_back(new Cardio("Elliptical Trainer", "Beginner", 20.0, "Move at a steady pace on the elliptical machine using both arms and legs for a full-body low-impact cardio session", 3));
    exercises.push_back(new Cardio("Light Dancing", "Beginner", 15.0, "Follow simple dance routines or move freely to music to raise your heart rate in an enjoyable way", 1));
    exercises.push_back(new Cardio("Slow Jump Rope", "Beginner", 10.0, "Jump rope at a slow controlled pace focusing on timing and coordination rather than speed", 6));
    exercises.push_back(new Cardio("Water Walking", "Beginner", 25.0, "Walk back and forth in a pool using the water resistance to get a gentle cardio workout with minimal joint stress", 7));
    exercises.push_back(new Cardio("Low Impact Aerobics", "Beginner", 20.0, "Perform aerobic movements like step-touches and marches keeping at least one foot on the ground at all times to reduce joint impact", 8));
    exercises.push_back(new Cardio("Marching in Place", "Beginner", 15.0, "March on the spot lifting your knees to hip height in a rhythmic pattern to get your blood flowing with zero equipment needed", 2));
    exercises.push_back(new Cardio("Gentle Hiking", "Beginner", 40.0, "Walk on trails with mild elevation changes at a comfortable pace to combine light cardio with outdoor exploration", 9));
    // --- Intermediate ---
    exercises.push_back(new Cardio("Jump Rope", "Intermediate", 15.0, "Skip rope at a steady moderate pace alternating between both feet and single-leg hops to improve coordination and burn calories", 12));
    exercises.push_back(new Cardio("Jogging", "Intermediate", 30.0, "Run at a pace where you can speak in short sentences but feel challenged, maintaining good upright posture throughout", 11));
    exercises.push_back(new Cardio("Rowing Machine", "Intermediate", 20.0, "Row with proper form driving first with legs then leaning back then pulling arms, reversing the sequence on the return for full-body cardio", 14));
    exercises.push_back(new Cardio("Swimming Laps", "Intermediate", 25.0, "Swim continuous laps in a pool alternating strokes every few lengths to build endurance with minimal joint impact", 13));
    exercises.push_back(new Cardio("Box Step-Ups", "Intermediate", 18.0, "Step up onto a box or bench quickly alternating legs each rep to combine cardio demand with lower body strengthening", 15));
    exercises.push_back(new Cardio("Kickboxing Cardio", "Intermediate", 25.0, "Throw punches and kicks into the air or at a bag in rapid combinations to build endurance while improving coordination and agility", 10));
    exercises.push_back(new Cardio("Battle Ropes", "Intermediate", 12.0, "Grip both ends of a heavy rope and make alternating wave motions as fast as possible to spike your heart rate and work your upper body", 16));
    exercises.push_back(new Cardio("Mountain Climbers", "Intermediate", 10.0, "Start in a plank position and drive your knees toward your chest one at a time as fast as you can to work both your core and cardiovascular system", 17));
    exercises.push_back(new Cardio("Stair Running", "Intermediate", 15.0, "Sprint up a flight of stairs then walk back down to recover, repeating for interval-style cardio that builds leg power and endurance", 18));
    exercises.push_back(new Cardio("Circuit Training", "Intermediate", 30.0, "Rotate through several exercises with no rest between stations mixing bodyweight moves and light weights to keep your heart rate elevated throughout", 11));
    // --- Advanced ---
    exercises.push_back(new Cardio("Running", "Advanced", 35.0, "Run at a fast sustained pace with long strides and controlled breathing pushing your aerobic capacity toward its limit", 22));
    exercises.push_back(new Cardio("Cycling Intervals", "Advanced", 30.0, "Alternate between 1-minute all-out sprints at high resistance and 2 minutes of easy pedaling on a stationary bike to build power and endurance", 20));
    exercises.push_back(new Cardio("Burpees", "Advanced", 15.0, "From standing drop your hands to the floor, kick your feet back into a plank, do a push-up, jump your feet forward and leap into the air, repeat without rest", 24));
    exercises.push_back(new Cardio("HIIT Treadmill", "Advanced", 25.0, "Alternate between 30-second all-out sprints and 60-second walking intervals on a treadmill to maximize calorie burn in a short session", 21));
    exercises.push_back(new Cardio("Assault Bike", "Advanced", 20.0, "Pedal and push the handles simultaneously on an air bike at maximum effort where resistance increases the harder you go", 23));
    exercises.push_back(new Cardio("Hill Sprints", "Advanced", 20.0, "Find a steep hill and sprint to the top as fast as possible then walk back down to recover before repeating for explosive cardio conditioning", 25));
    exercises.push_back(new Cardio("Sled Push", "Advanced", 15.0, "Load a sled with weight, lean into the handles and drive it forward with powerful leg strides down the track for high-resistance cardio", 26));
    exercises.push_back(new Cardio("Ski Erg", "Advanced", 18.0, "Pull the handles of the ski erg downward using a full-body motion starting from overhead to work arms, core and legs in one cardio movement", 27));
    exercises.push_back(new Cardio("Agility Ladder Drills", "Advanced", 12.0, "Perform rapid footwork patterns through an agility ladder on the ground to develop speed, coordination and cardiovascular fitness simultaneously", 22));
    exercises.push_back(new Cardio("Trail Running", "Advanced", 40.0, "Run on uneven off-road terrain with elevation changes to challenge your balance, ankle stability and aerobic endurance beyond flat-surface running", 28));
    // --- High Performance ---
    exercises.push_back(new Cardio("Cycling Long Distance", "High Performance", 60.0, "Ride for extended distances maintaining a high cadence and effort level close to your anaerobic threshold to build elite-level cycling endurance", 35));
    exercises.push_back(new Cardio("Tabata Protocol", "High Performance", 16.0, "Perform 8 rounds of 20 seconds at absolute maximum effort followed by 10 seconds rest to push your anaerobic capacity to its peak", 33));
    exercises.push_back(new Cardio("Open Water Swimming", "High Performance", 45.0, "Swim in a lake or ocean adapting to currents, waves and sighting challenges for real-world endurance that pool swimming cannot replicate", 36));
    exercises.push_back(new Cardio("Rowing Intervals", "High Performance", 25.0, "Row 500-meter repeats at maximum power on the ergometer with 1-minute easy rowing between each to develop peak rowing capacity", 34));
    exercises.push_back(new Cardio("Sprint Repeats", "High Performance", 20.0, "Run 200-meter sprints at top speed with 2-minute walk recoveries between each to develop maximum speed and anaerobic power", 37));
    exercises.push_back(new Cardio("Plyometric Circuit", "High Performance", 22.0, "Cycle through box jumps, lateral bounds and depth jumps without rest between exercises to build explosive power and cardiovascular endurance", 38));
    exercises.push_back(new Cardio("Versa Climber", "High Performance", 15.0, "Climb the vertical machine at an intense pace pulling and stepping simultaneously for one of the highest calorie-burning cardio exercises available", 39));
    exercises.push_back(new Cardio("Sand Running", "High Performance", 30.0, "Run on soft sand which forces your muscles to work much harder than firm ground dramatically increasing cardiovascular and muscular demand", 40));
    exercises.push_back(new Cardio("CrossFit WOD", "High Performance", 35.0, "Complete the workout of the day combining heavy lifts, gymnastics movements and high-intensity cardio as fast as possible with proper form", 42));
    exercises.push_back(new Cardio("Triathlon Training", "High Performance", 60.0, "Complete a swim, bike and run session back to back to simulate race conditions and build multi-discipline endurance for competition", 45));
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
        int choice = validateOption(1, 7);

        if (choice == 1) {
            exerciseType();
            Exercise* nuevo;
            int option = validateOption(1, 2);

            if (option == 1) {
                nuevo = new Strength();
            }
            else if (option == 2) {
                nuevo = new Cardio();
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
            int searchId;
            cout << " " << endl;
            cout << "---------------------" << endl;
            cout << "Enter the id of the exercise to update: " << endl;

            cin >> searchId;

            bool found = false;
            for (size_t i = 0; i < exercises.size(); i++) {
                if (exercises[i]->getId() == searchId) {
                    exercises[i]->update();
                    found = true;
                    cout << "      " << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "||  Exercise updated correctly!  ||" << endl;
                    cout << "-----------------------------------" << endl;
                    exercises[i]->showDetail();
                    break;
                }

            }
            if (!found) cout << "Exercise not found." << endl;
        }

        else if (choice == 3) {
            int searchId;
            cout << "Enter the ID of the exercise to delete: ";
            cin >> searchId;

            bool found = false;
            for (size_t i = 0; i < exercises.size(); i++) {
                if (exercises[i]->getId() == searchId) {
                    char confirm;
                    cout << "Are you sure you want to delete the exercise '" << exercises[i]->getName() << "'? (y/n): ";
                    cin >> confirm;

                    if (confirm == 'y' || confirm == 'Y') {
                        delete exercises[i]; // Delete the exercise object to free memory.
                        // Remove the pointer from the vector, and .erase() method will reorganize the vector to fill the gap left by the removed element.
                        // More documentation: https://www.w3schools.com/cpp/ref_vector_erase.asp
                        exercises.erase(exercises.begin() + i);
                        cout << "Exercise deleted successfully." << endl;
                    } else {
                        cout << "Operation cancelled." << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Exercise not found." << endl;
        }


        else if (choice == 4) {
            cout << "======================" << endl;
            cout << "|| Exercise Details ||" << endl;
            cout << "======================" << endl;
            for (size_t i = 0; i < exercises.size(); i++) {
                cout << exercises[i]->getId() << ". " << exercises[i]->getName() << endl;
            }

            // .back() does the same thing as writing exercises[exercises.size() - 1] to get the last element of the vector.
            int exerciseChoice = validateOption(1, exercises.back()->getId());
            bool found = false;
            for (size_t i = 0; i < exercises.size(); i++) {
                if (exercises[i]->getId() == exerciseChoice) {
                    exercises[i]->showDetail();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Exercise not found." << endl;
        }

        else if (choice == 5) {
            cout << "What level do you want to search?" << endl;

            levels();
            int op = validateOption(1, 4);
            string level = levelChoice(op);

            for (size_t i = 0; i < exercises.size(); i++) {
                if (exercises[i]->getIntensityLevel() == level) {
                    exercises[i]->showDetail();
                }
            }
        }

        else if (choice == 6) {
            cout << "======================" << endl;
            cout << "|| Exercise Routine ||" << endl;
            cout << "======================" << endl;

            cout << "== How much exercises do you want ==" << endl;
            size_t numExercises = (size_t)validateOption(1, exercises.size());

            cout << "What level do you want for your routine?" << endl;

            levels();
            int op = validateOption(1, 4);
            string level = levelChoice(op);

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
