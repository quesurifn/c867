//
// Created by Kyle on 3/1/24.
//

#ifndef C867_ROSTER_H
#define C867_ROSTER_H
#include "student.h"
#include <vector>


class Roster {

public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    vector<Student*> getClassRoster();

private:
    vector<Student*> classRoster;
    ~Roster();
};

#endif //C867_ROSTER_H
