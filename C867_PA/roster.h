//
//  roster.h
//  C867_PA
//
//  Created by Jose D. Romero on 4/27/25.
//

#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster{
public:
    // destructor
    ~Roster();
    
    // add function - sets the instance variables from part D1 and updates the roster.
    void add(string studentID, string firstName, string lastName, string emailAddress,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    // remove function - removes students from the roster by student ID.
    // If the student ID does not exist, the function prints an error message
    // indicating that the student was not found.
    void remove(string studentID);
    
    // printAll function - prints a complete tab-separated list of student
    // data in the provided format: A1 [tab] First Name: John [tab] Last Name:
    // Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
    void printAll();
    
    // printAverageDaysInCourse function - prints a student’s average number of days in
    // the three courses. The student is identified by the studentID parameter.
    void printAverageDaysInCourse(string studentID);
    
    // printInvalidEmails function - verifies student email addresses and displays
    // all invalid email addresses to the user.
    // Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    void printInvalidEmails();
    
    // printByDegreeProgram function - prints out student information for a degree program specified by an enumerated type.
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // getter for classRosterArray
    Student* getStudentAtIndex(int index) const;
    
private:
    // Array of Student Pointers
    Student* classRosterArray[5];
};


#endif
