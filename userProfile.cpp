#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UserProfile {
private:
    string name;
    string fitnessGoal;
    int workOutDaysPerWeek;
    vector<string> availableDays;

public:
    // constructor
    UserProfile() {
        name = "";
        fitnessGoal = "";
        workOutDaysPerWeek = 0;
    }

    //Adding getter functions to access in main
    string getFitnessGoal() {
        return fitnessGoal;
    }

    int getWorkOutDaysPerWeek() {
        return workOutDaysPerWeek;
    }
    vector<string> getAvailableDays() {
        return availableDays;
    }

    // set name
    void setName(string n) 
    {
        name = n;
    }

    // set goal
    void setFitnessGoal(string goal) 
    {
        fitnessGoal = goal;
    }

    // set workout days
    void setWorkoutDaysPerWeek(int days) {
        workOutDaysPerWeek = days;
    }

    // add day
    void addAvailableDay(string day) {
        availableDays.push_back(day);
    }

    // checks if the day was already entered
    bool dayExists(string day) {
        for (int i = 0; i < availableDays.size(); i++) {
            if (availableDays[i] == day) {
                return true;
            }
        }
        return false;
    }

    // display profile
    void displayProfile() {
        cout << endl;
        cout << "======================================" << endl;
        cout << "           USER PROFILE               " << endl;
        cout << "======================================" << endl;
        cout << "Name: " << name << endl;
        cout << "Goal: " << fitnessGoal << endl;
        cout << "Workout Days Per Week: " << workOutDaysPerWeek << endl;

        cout << "Available Days: ";
        for (int i = 0; i < availableDays.size(); i++) {
            cout << availableDays[i];
            if (i < availableDays.size() - 1) {
                cout << ", ";
            }
        }

        cout << endl;
        cout << "======================================" << endl;
    }
};


