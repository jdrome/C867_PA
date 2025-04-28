//
//  main.cpp
//  C867_PA
//
//  Created by Jose D. Romero on 4/27/25.
//

#include "roster.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // Task A: Modify the “studentData Table” to include your personal information as the last item.
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                    "A5,Jose,Romero,jrom387@wgu.edu,26,20,25,30,SOFTWARE"};
    
    // Print Student Info
    cout << " Course Title: C867 Scripting and Programming - Applications \n Language: C++ \n Student ID: 011832100 \n Name: Jose D. Romero" << endl;
    
    // Create Roster instance, classRoster
    Roster classRoster;
    
    // Parse student Data and add each student to classRoster
    for (int i = 0; i < 5; ++i) {
        stringstream ss(studentData[i]);
        string studentIDStr, firstNameStr, lastNameStr, emailStr, ageStr, day1Str, day2Str, day3Str, degreeStr;
        
        // Split strings using getline()
        getline(ss, studentIDStr, ',');
        getline(ss, firstNameStr, ',');
        getline(ss, lastNameStr, ',');
        getline(ss, emailStr, ',');
        getline(ss, ageStr, ',');
        getline(ss, day1Str, ',');
        getline(ss, day2Str, ',');
        getline(ss, day3Str, ',');
        getline(ss, degreeStr, ',');
        
        // Convert strings to integers
        int age = stoi(ageStr);
        int day1 = stoi(day1Str);
        int day2 = stoi(day2Str);
        int day3 = stoi(day3Str);
        
        // Convert string to degreeProgram enum
        DegreeProgram degreeProgram;
        if (degreeStr == "SECURITY") degreeProgram = SECURITY;
        else if (degreeStr == "NETWORK") degreeProgram = NETWORK;
        else degreeProgram = SOFTWARE;
        
        // Add each student to class roster
        classRoster.add(studentIDStr, firstNameStr, lastNameStr, emailStr, age, day1, day2, day3, degreeProgram);
    }
    cout << endl;
    
    // Print all students
    cout << "Printing all students:" << endl;
    classRoster.printAll();
    cout << endl;
    
    // Print all invalid emails
    cout << "Printing all invalid emails" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    // Loop through classRoster and for each element, print the average days in the course
    cout << "Printing average days in course for each student:" << endl;
    for (int i = 0; i < 5; ++i) {
        Student* student = classRoster.getStudentAtIndex(i);
        if (student != nullptr) {
            classRoster.printAverageDaysInCourse(student->getStudentId());
        }
    }
    cout << endl;
    
    // Print students in SOFTWARE degree program
    cout << "Displaying students by degree program SOFTWARE:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    // Remove student A3
    cout << "Removing student A3:" << endl;
    classRoster.remove("A3");
    cout << endl;
    
    // Print all students in classRoster
    cout << "Printing all students in classRoster" << endl;
    classRoster.printAll();
    cout << endl;
    
    // Try to remove student A3 again.
    cout << "Trying to remove student A3 again:" << endl;
    classRoster.remove("A3");
    cout << endl;
    
    classRoster.printInvalidEmails();
    
    return 0;
}
