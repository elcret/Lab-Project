#include <iostream>
#include <string>
#include <cctype>
#include "userProfile.cpp"
using namespace std;

class WorkoutPlan {
private:
    //Member variables
    vector<string> workoutSchedule;
    string workoutType;
    int totalDays;

public:
    //Function to set workout type based on what goal they chosse
    void setWorkoutTypeBasedOnGoal(string goal) {
        if (goal == "Get Lean") {
            workoutType = "Cardio";
        }
        else if (goal == "Grow Muscle") {
            workoutType = "Strength";
        }
        else {
            workoutType = "Mixed";
        }
    }

    //generating workout plan based on days and days available
    void generatePlan(int days, vector<string> availableDays) {
        totalDays = days;

        for (int i = 0; i < days; i++) {
            string activity;

            if (workoutType == "Cardio") {
                if (i % 3 == 0)
                    activity = "Running";
                else if (i % 3 == 1)
                    activity = "HIIT Workout";
                else
                    activity = "Brisk Walking";
            }
            else if (workoutType == "Strength") {
                if (i % 2 == 0)
                    activity = "Upper Body Workout";
                else
                    activity = "Lower Body Workout";
            }
            else {
                if (i % 2 == 0)
                    activity = "Full Body Strength";
                else
                    activity = "Light Cardio";
            }

            string fullPlan = availableDays[i] + " - " + activity;
            workoutSchedule.push_back(fullPlan);
        }
    }

    //Displaying plan
    void displayPlan() {
        cout << "\n========== WORKOUT PLAN ==========" << endl;
        cout << "Workout Type: " << workoutType << endl;

        for (int i = 0; i < workoutSchedule.size(); i++) {
            cout << workoutSchedule[i] << endl;
        }

        cout << "==================================" << endl;
    }
};

// converts user input into full day names
string formatDay(string day) {
    for (int i = 0; i < day.length(); i++) {
        day[i] = tolower(day[i]);
    }

    if (day == "mon" || day == "monday") return "Monday";
    else if (day == "tue" || day == "tuesday") return "Tuesday";
    else if (day == "wed" || day == "wednesday") return "Wednesday";
    else if (day == "thu" || day == "thursday") return "Thursday";
    else if (day == "fri" || day == "friday") return "Friday";
    else if (day == "sat" || day == "saturday") return "Saturday";
    else if (day == "sun" || day == "sunday") return "Sunday";
    else return "Invalid";
}

int main() {
    UserProfile user;

    string name;
    int goalChoice;
    int daysPerWeek;
    string day;
    string goal;

    // ask for name
    cout << "Enter your name: ";
    getline(cin, name);
    user.setName(name);

    // ask for goal
    cout << endl;
    cout << "Choose your fitness goal:" << endl;
    cout << "1. Get Lean" << endl;
    cout << "2. Grow Muscle" << endl;
    cout << "3. Maintain Muscle" << endl;
    cout << "4. Healthy Movement" << endl;
    cout << "Enter choice: ";
    cin >> goalChoice;

    // validate goal choice
    while (cin.fail() || goalChoice < 1 || goalChoice > 4) {
        cin.clear();              // clears the error
        cin.ignore(1000, '\n');   // throws away bad input
        cout << "Invalid choice. Enter a number 1-4: ";
        cin >> goalChoice;
    }

    // set goal
    if (goalChoice == 1) {
        goal = "Get Lean";
    }
    else if (goalChoice == 2) {
        goal = "Grow Muscle";
    }
    else if (goalChoice == 3) {
        goal = "Maintain Muscle";
    }
    else {
        goal = "Healthy Movement";
    }

    user.setFitnessGoal(goal);

    // ask for number of workout days
    cout << "How many days do you want to work out per week? ";
    cin >> daysPerWeek;

    // validate days
    while (cin.fail() || daysPerWeek <= 0 || daysPerWeek > 7) {
        cin.clear();              // clears the error
        cin.ignore(1000, '\n');   // throws away bad input
        cout << "Invalid input. Enter a number between 1 and 7: ";
        cin >> daysPerWeek;
    }

    user.setWorkoutDaysPerWeek(daysPerWeek);

    cin.ignore();

    // ask for available days
    for (int i = 0; i < daysPerWeek; i++) {
        cout << "Enter available day " << i + 1 << ": ";
        getline(cin, day);

        string fixedDay = formatDay(day);

        if (fixedDay != "Invalid") {
            user.addAvailableDay(fixedDay);
        }
        else {
            cout << "Invalid day. Example entry: Mon or Monday." << endl;
            i--;
        }
    }

    // display final profile
    user.displayProfile();

    //Making workoutPlan
    WorkoutPlan plan;


    plan.setWorkoutTypeBasedOnGoal(user.getFitnessGoal());

    plan.generatePlan(user.getWorkOutDaysPerWeek(), user.getAvailableDays());

    plan.displayPlan();

    return 0;
}