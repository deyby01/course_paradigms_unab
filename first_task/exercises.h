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
        int last_used;

        // Static variable to asign unique IDs to exercises.
        static int nextId;

    public:
        Exercise();
        Exercise(string name, string type, string intensity_level, double estimated_time, string description, int last_used);
        virtual ~Exercise();

        // Getter's and setter's
        int getId() const;
        void setId(int id);

        string getName() const;
        void setName(string name);

        string getType() const;
        void setType(string type);

        string getIntensityLevel() const;
        void setIntensityLevel(string intensity_level);

        double getEstimatedTime() const;
        void setEstimatedTime(double estimated_time);

        string getDescription() const;
        void setDescription(string description);

        int getLastUsed() const;
        void setLastUsed(int last_used);

        void create();
        void update();
        void deleteExercise();
        virtual void showDetail() const;

};

class Strength: public Exercise {
    public:
        Strength();
        Strength(string name, string intensity_level, double estimated_time,
                string description, int last_used);
        ~Strength();

        void showDetail() const override;
};

class Cardio: public Exercise {
    public:
        Cardio();
        Cardio(string name, string intensity_level, double estimated_time,
              string description, int last_used);
        ~Cardio();

        void showDetail() const override;
};
