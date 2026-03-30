#include "exercises.h"
#include <iostream>
#include <string>
using namespace std;

// Initialize static variable.
int Exercise::nextId = 1;

// Constructors of father class.
Exercise::Exercise() {
    this->id = 0;
    this->name = "";
    this->type = "";
    this->intensity_level = "";
    this->estimated_time = 0.0;
    this->description = "";
    this->last_used = 0;
}

Exercise::Exercise(string name, string type, string intensity_level,
                   double estimated_time, string description, int last_used)
    : id(nextId++), name(name), type(type), intensity_level(intensity_level),
      estimated_time(estimated_time), description(description), last_used(last_used) {
}

Exercise::~Exercise(){
    cout << "Exercise destroyed." << endl;
}

// Getter and setters
int Exercise::getId() const {
    return id;
}
void Exercise::setId(int id){
    this->id = id;
}

string Exercise::getName() const {
    return name;
}
void Exercise::setName(string name){
    this->name = name;
}

string Exercise::getType() const {
    return type;
}
void Exercise::setType(string type) {
    this->type = type;
}

string Exercise::getIntensityLevel() const{
    return intensity_level;
}
void Exercise::setIntensityLevel(string intensity_level){
    this->intensity_level = intensity_level;
}

double Exercise::getEstimatedTime() const {
    return estimated_time;
}
void Exercise::setEstimatedTime(double estimated_time){
    this->estimated_time = estimated_time;
}

string Exercise::getDescription() const {
    return description;
}
void Exercise::setDescription(string description) {
    this->description = description;
}

int Exercise::getLastUsed() const {
    return last_used;
}
void Exercise::setLastUsed(int last_used) {
    this->last_used = last_used;
}

// Methods
void Exercise::create() {
    cout << "Create a New Exercise! " << endl;

    string name;
    cout << "Name of exercise: ";
    getline(cin, name);
    setName(name);

    string i_level;
    cout << "Intensity level: ";
    getline(cin, i_level);
    setIntensityLevel(i_level);

    double e_time;
    cout << "Estimated time of Exercise: ";
    cin >> e_time;
    cin.ignore();
    setEstimatedTime(e_time);

    string descript;
    cout << "Description of exercise: ";
    getline(cin, descript);
    setDescription(descript);

    int l_used;
    cout << "Last time used: ";
    cin >> l_used;
    cin.ignore();
    setLastUsed(l_used);
}

void Exercise::update(){
    cout << "Update an Exercise! " << endl;
    create();
}

void Exercise::deleteExercise() {
    cout << "Delete an Exercise!" << endl;
    id=0;
    name.clear();
    type.clear();
    intensity_level.clear();
    estimated_time=0.0;
    description.clear();
    last_used=0;
}

void Exercise::showDetail() const {
    cout << "Id: " << id << "\nName: " << name
        << "\nType: " << type << "\nIntensity level: " << intensity_level
        << "\nEstimated time: " << estimated_time << " minutes \nDescription: " << description
        << "\nLast time used: " << last_used << "\n";
}


// Class Strength.

Strength::Strength() : Exercise() {
    setType("Strength");
    cout << "Strength Exercise created by default." << endl;
}

Strength::Strength(string name, string intensity_level,
        double estimated_time, string description, int last_used)
    : Exercise(name, "Strength", intensity_level, estimated_time, description, last_used){

}

Strength::~Strength(){
    cout << "Strength Exercise destroyed" << endl;
}

void Strength::showDetail() const {
    cout << endl;
    cout << "Strength Exercise detail!" << endl;
    Exercise::showDetail();
    cout << endl;
}

// Class Cardio.

Cardio::Cardio() : Exercise() {
    setType("Cardio");
    cout << "Cardio Exercise created by default." << endl;
}

Cardio::Cardio(string name, string intensity_level,
        double estimated_time, string description, int last_used)
    : Exercise(name, "Cardio", intensity_level, estimated_time, description, last_used){

}

Cardio::~Cardio(){
    cout << "Cardio Exercise destroyed" << endl;
}

void Cardio::showDetail() const {
    cout << endl;
    cout << "Cardio Exercise detail!" << endl;
    Exercise::showDetail();
    cout << endl;
}
