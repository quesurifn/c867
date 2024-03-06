//
// Created by Kyle on 3/1/24.
//

#ifndef C867_STUDENT_H
#define C867_STUDENT_H

#include <vector>
#include <string>
#include "degree.h"

using namespace::std;


class Student{
private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    vector<int> daysInCourse;
    DegreeProgram program;

public:
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, vector<int> daysInCourse, DegreeProgram program);

    void setStudentId(string id);
    string getStudentId() const;

    void setFirstName(string fn);
    string getFirstName() const;

    void setLastName(string ln);
    string getLastName() const;

    void setEmailAddress(string e);
    string getEmailAddress() const;

    void setAge(int a);
    int getAge() const;

    void setDaysInCourse(vector<int> d);
    vector<int> getDaysInCourse() const;

    void setDegreeProgram(DegreeProgram d);
    DegreeProgram getDegreeProgram() const;


    void print();
};

#endif //C867__STUDENT_H
