#include <iostream>
#include "roster.h"

using namespace std;

int main() {
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "C++ 23" << endl;
    cout << "000522422" << endl;
    cout << "Kyle Fahey" << endl;

    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,Kyle,Fahey,kfahey1@wgu.edu,29,2,10,5,SOFTWARE" };


    Roster* roster = new Roster();

    for(auto str : studentData) {
        char* char_array = new char[str.length() + 1];
        strcpy(char_array, str.c_str());
        char* field = strtok(char_array, ",");

        vector<string> fields;
        while (field != NULL) // exit when no more data, which includes an emtpy line
        {
            fields.push_back(field); // got data, store it
            field = strtok(NULL, ",");
        }

        int parsedAge = atoi(fields[4].c_str());
        int parsedDay1 = atoi(fields[5].c_str());
        int parsedDay2 = atoi(fields[6].c_str());
        int parsedDay3 = atoi(fields[7].c_str());
        string degreeProgram = fields[8];


        DegreeProgram parsedProgram = SECURITY;
        if(degreeProgram == "SECURITY") {
            parsedProgram = SECURITY;
        }

        if(degreeProgram == "NETWORK") {
            parsedProgram = NETWORK;
        }

        if(degreeProgram == "SOFTWARE") {
            parsedProgram = SOFTWARE;
        }

        roster->add(fields[0], fields[1], fields[2], fields[3], parsedAge, parsedDay1, parsedDay2, parsedDay3, parsedProgram);
    }

    roster->printAll();
    roster->printInvalidEmails();

    vector<Student*> classRoster = roster->getClassRoster();


    for(auto s : classRoster) {
        roster->printAverageDaysInCourse(s->getStudentId());
    }

    roster->printByDegreeProgram(SOFTWARE);
    roster->remove("A3");
    roster->printAll();
    roster->remove("A3");
    return 0;
}
