//Done by student: Vitaliy Syniak
//Group: 121-1
//Lab2.2, 14 variant

#include <iostream>

using namespace std;

int main() {

    enum Names {Samuel, John, Peter, Emma, George, Leonardo, Adam};

    // Task #1
    {
        struct Student
        {
            Names name;
            int courseNum;
            bool armyCourses;
        };

        Student myStudent[7];
        myStudent[0] = {Samuel, 2, true};
        myStudent[1] = {John, 1, true};
        myStudent[2] = {Peter, 1, false};
        myStudent[3] = {Emma, 4, false};
        myStudent[4] = {George, 3, true};
        myStudent[5] = {Leonardo, 5, true };
        myStudent[6].name = Adam;
        myStudent[6].courseNum = 1;
        myStudent[6].armyCourses = true;

        int countStudents = 0;
        for(int i = 0; i < 7; i++) {
            if(myStudent[i].courseNum == 1 && myStudent[i].armyCourses == true) {
                countStudents++;
            }
        }

        float studentsPercent = (float)countStudents * 100 / 7;

        cout << studentsPercent << endl;
    }

    // Task #2
    {
        struct Student
        {
            Names name;
            double avgScore;
            bool danceCourses;
        };

        Student myStudent[7];
        myStudent[0] = {Samuel, 5, true};
        myStudent[1] = {John, 3.9, true};
        myStudent[2] = {Peter, 3.7, false};
        myStudent[3] = {Emma, 5, false};
        myStudent[4] = {George, 2.9, true};
        myStudent[5] = {Leonardo, 5, true };
        myStudent[6].name = Adam;
        myStudent[6].avgScore = 5;
        myStudent[6].danceCourses = true;

        int countStudents = 0;
        for(int i = 0; i < 7; i++) {
            if(myStudent[i].avgScore == 5 && myStudent[i].danceCourses == true) {
                countStudents++;
            }
        }
        float studentsPercent = (float)countStudents * 100 / 7;

        cout << studentsPercent << endl;
    }

    return 0;
}