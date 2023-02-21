// David Westerhaus
// Extra Credit Lab 1

// including things
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Define the preferences for each department
const int DEPT_COUNT = 5;
const int PROG_COUNT = 5;

// read file (first 5 rows are preferences of department, next 5 are programmer preferences)
void read_file(string filename, int dept_prefs[5][5], int prog_prefs[5][5]){
    ifstream file(filename); // class to read from files
    string line; // each line is a string

    for (int i = 0; i < 10; i++) { // from 0->10
        getline(file, line); // get the line
        stringstream ss(line); // read line

        for (int j = 0; j < 5; j++) { // nested loop from 0->5
            int val;
            ss >> val;
            if (i < 5) {
                dept_prefs[i][j] = val; // add values to department preference array
            } else {
                prog_prefs[i-5][j] = val; // add values to programmer preference array
            }
        }
    }


}


int main() {
    int dept_prefs[DEPT_COUNT][PROG_COUNT];  // initialize department and programmer preferences
    int prog_prefs[PROG_COUNT][DEPT_COUNT];
    read_file("matching-data.txt", dept_prefs, prog_prefs); // read file and load preferences

    vector<int> assigned_prog(5, 0); // create vectors
    vector<int> assigned_dept(5, -1);

    for (int i = 0; i < 5; i++) {
        // Find the first programmer in the department's preferences who hasn't been assigned
        int prog = -1;
        for (int j = 0; j < 5; j++) {
            int preferred_prog = dept_prefs[i][j];
            if (assigned_prog[preferred_prog-1] == 0) {
                prog = preferred_prog;
                break;
            }
        }

        // If no unassigned programmer is found, look for a preferred assigned programmer
        if (prog == -1) {
            for (int j = 0; j < 5; j++) {
                int preferred_prog = dept_prefs[i][j];
                int curr_dept = assigned_dept[preferred_prog-1];
                if (curr_dept != -1 && prog_prefs[preferred_prog-1][i] < prog_prefs[preferred_prog-1][curr_dept-1]) {
                    assigned_dept[curr_dept-1] = -1;
                    prog = preferred_prog;
                    break;
                }
            }
        }

        // Assign the programmer to the department
        assigned_prog[prog-1] = 1;
        assigned_dept[i] = prog;
    }
    
   
    for (int i = 0; i < DEPT_COUNT; i++) {
        cout << "Department #" << i+1 << " is assigned Programmer #" << assigned_dept[i] << endl;
    }
    return 0;
}
