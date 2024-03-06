//
// Created by Kyle on 3/1/24.
//
#include "roster.h"
#include <iostream>

using namespace std;

Roster::~Roster() {
    classRoster.clear();
    classRoster.shrink_to_fit();
}

vector<Student*> Roster::getClassRoster() {
    return classRoster;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    vector<int> daysInCourseField = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student *student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseField, degreeProgram);
    classRoster.push_back(student);
}

void Roster::remove(string studentID) {
    for(auto it=classRoster.begin(); it!=classRoster.end(); ){
        string value = it.operator*()->getStudentId();
        if(value == studentID) {
            classRoster.erase(it);
            // Assumption made here that there will be no duplicates
            return;
        }
        advance(it, 1);
    }

    cout << "Student ID: " + studentID + " not found";
}

void Roster::printAll() {
    for (auto &student : classRoster) {
        student->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    Student *student = nullptr;
    for(auto it=classRoster.begin(); it!=classRoster.end(); ){
        string value = it.operator*()->getStudentId();
        if(value == studentID) {
            student = it.operator*();
            break;
        }
        advance(it, 1);
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





