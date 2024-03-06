//
// Created by Kyle on 3/1/24.
//
#include "student.h"
#include <iostream>


using namespace std;


Student::Student(string id, string fn, string ln, string e, int a,
                 array<int, 3> d, DegreeProgram p) {
    studentId = id;
    firstName = fn;
    lastName = ln;
    emailAddress = e;
    age = a;
    daysInCourse = d;
    program = p;
}

string Student::getFirstName() const {
    return firstName;
}

void Student::setFirstName(string fn) {
    firstName = fn;
}

string Student::getLastName() const {
    return lastName;
}

void Student::setLastName(string ln) {
    lastName = ln;
}

string Student::getStudentId() const {
    return studentId;
}

void Student::setStudentId(string id) {
    studentId = id;
}

string Student::getEmailAddress() const {
    return emailAddress;
}

void Student::setEmailAddress(string e) {
    emailAddress = e;
}

array<int,3> Student::getDaysInCourse() const {
    return daysInCourse;
}

void Student::setDaysInCourse(array<int,3> days) {
    daysInCourse = days;
}

void Student::setDegreeProgram(DegreeProgram d) {
    program = d;
}

DegreeProgram Student::getDegreeProgram() const {
    return program;
}

void Student::print() {
    string output = "StudentID: " + studentId + "\t" + "FirstName: " + firstName + "\t" + "LastName: " + lastName + "\t" + "EmailAddress: " + emailAddress + "\t" + "Age: " + to_string(age) + "\t";

    string daysInClass = "DaysInClass: ";
    for(auto d: daysInCourse) {
        daysInClass += to_string(d);
    }

    output += daysInClass;
    output += "\t";
    cout << output;
}