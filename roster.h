//
// Created by Kyle on 3/1/24.
//

#ifndef C867_ROSTER_H
#define C867_ROSTER_H
#include "student.h"
using namespace std;

class Roster {

public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    array<Student*, 5> getClassRoster();

    int rosterLength;
private:
    array<Student *, 5> classRoster;
    ~Roster();
};

#endif //C867_ROSTER_H
