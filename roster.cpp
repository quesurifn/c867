//
// Created by Kyle on 3/1/24.
//
#include "roster.h"
#include <iostream>

using namespace std;

Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        rosterLength--;
        delete classRoster[i];
    }
}


array<Student*, 5> Roster::getClassRoster() {
    return classRoster;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    array<int, 3> daysInCourseField = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student *student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseField, degreeProgram);

    classRoster[rosterLength] = student;
    rosterLength++;
}

void Roster::remove(string studentID) {
    for (int i = 0; i < 5; i++) {
        string value = classRoster[i]->getStudentId();
        if(value == studentID) {
            rosterLength--;
            delete classRoster[i];
            // Assumption made here that there will be no duplicates
            return;
        }
    }
    cout << "Student ID: " + studentID + " not found";
}

void Roster::printAll() {
    for (int i = 0; i < 5; ++i) {
        classRoster[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    Student *student = nullptr;

    for (int i = 0; i < 5; i++) {
        string value = classRoster[i]->getStudentId();
        if(value == studentID) {
            student = classRoster[i];
            break;
        }
    }

    if(!student) {
        cout << "Student ID: " + studentID + " not found";
        return;
    }

    int sum_of_elems = 0;
    for (auto& n : student->getDaysInCourse()) {
        sum_of_elems += n;
    }


    cout << sum_of_elems / student->getDaysInCourse().size();
}

void Roster::printInvalidEmails() {
    for (auto& s : classRoster) {
        string email = s->getEmailAddress();

        bool hasPeriod = email.find(".") != string::npos;
        bool hasArroba = email.find("@") != string::npos;
        bool hasSpace = email.find(" ") != string::npos;

        if(!hasArroba || !hasPeriod || hasSpace) {
            cout << email;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (auto s : classRoster) {
        if(s->getDegreeProgram() == degreeProgram) {
            s->print();
        }
    }
}





