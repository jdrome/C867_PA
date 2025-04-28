//
//  roster.cpp
//  C867_PA
//
//  Created by Jose D. Romero on 4/27/25.
//

#include "roster.h"

// add function - sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string email,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    // add new student into first empty slot in array.
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysArray, degreeProgram);
            break;
        }
    }
}

// remove function - removes students from the roster by student ID.
// If the student ID does not exist, the function prints an error message
// indicating that the student was not found.
void Roster::remove(string studentID) {
    // Tracks if you found the student.
    bool found = false;
    
    // Locate student. If the pointer is not null and the student ID matches, remove the student.
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            found = true;
            break;
        }
    }
    
    // Handle case where the student does not exist
    if (!found) {
        cout << "ERROR: Student with ID " << studentID << " was not found in classRosterArray." << endl;
    }
}

// printAll function - prints a complete tab-separated list of student
// data in the provided format: A1 [tab] First Name: John [tab] Last Name:
// Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
void Roster::printAll() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

// printAverageDaysInCourse function - prints a student’s average number of days in
// the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
    // locate the student based on the ID
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
            int* days = classRosterArray[i]->getDaysLeft();
            int average = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID: " << studentID << ", average days in course: " << average << endl;
            return;
        }
    }
    cout << "ERROR: Student with ID " << studentID << " not found in classRosterArray." << endl;
}

// printInvalidEmails function - verifies student email addresses and displays
// all invalid email addresses to the user.
// Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
    // Check all students
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getEmail();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << "Invalid email: " << email << endl;
            }
        }
    }
}

// printByDegreeProgram function - prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegree() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
