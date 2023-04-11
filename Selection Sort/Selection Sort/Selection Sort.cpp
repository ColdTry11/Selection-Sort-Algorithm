#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Employee.h"

using namespace std;

int main(int argc, char** argv)
{
    //Check for command line error
    if (argc == 1) {
        cout << "You forgot the command line parameter" << endl;
        exit(0);
    }

    //Check for file
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not find file " << argv[1] << endl;
        exit(0);
    }

    //Get how many lines
    string line;
    getline(ifs, line);
    int n = stoi(line);

    //initializing an array
    Employee** employee = new Employee * [n];

    //loop through file
    for (int i = 0; i < n; i++) {
        int age;
        int id;
        int year;
        string name;
        string job;
        string ids;
        string a;
        string y;
        getline(ifs, name, '|');
        getline(ifs, ids, '|');
        getline(ifs, a, '|');
        getline(ifs, job, '|');
        getline(ifs, y);
        id = stoi(ids);
        age = stoi(a);
        year = stoi(y);
        Employee* emp = new Employee(name, id, age, job, year);

        //Add to array
        employee[i] = emp;


    }

    //SELECTION SORT
    int i, j;
    int comparison = 0;
    for (i = 0; i < n - 1; i++) {
        auto minIndex = i;
        //Find smallest value in array
        for (j = i + 1; j < n; j++) {
            comparison++;
            if (employee[j]->getID() < employee[minIndex]->getID()) {
                minIndex = j;
            }
        }
        //Move smallest value to the left side of array
        auto temp = employee[minIndex];
        employee[minIndex] = employee[i];
        employee[i] = temp;
        for (int k = 0; k < n; k++) {
            cout << employee[k]->getID() << " ";
        }
        cout << endl;
    }

    //Print total comparison
    cout << "It took " << comparison << " comparisons to sort this list." << endl;

}