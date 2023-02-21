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

int main(){
    
    int dept_prefs[DEPT_COUNT][PROG_COUNT];
    int prog_prefs[PROG_COUNT][DEPT_COUNT];
    read_file("matching-data.txt", dept_prefs, prog_prefs);

    vector<int> assigned_prog(5, 0);
    vector<int> assigned_dept(5, -1);






    return 0;
}