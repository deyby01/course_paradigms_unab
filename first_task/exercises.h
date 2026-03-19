#include <iostream>
using namespace std;

class Exercise{
    private:
        int id;
        string name;
        string type;
        string intensity_level;
        double estimated_time;
        string description;
        string last_used;

    public:
        Exercise();
        Exercise(int id, string name, string type, string intensity_level, double estimated_time, string description, string last_used);
        ~Exercise();

        void create();
        void update();
        void deleteExercise();
        void showDetail() const;
        void search();
        void generateRoute();

};
