//
//  student.h
//  C867_PA
//
//  Created by Jose D. Romero on 4/27/25.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
public:
    // Constructor
    Student(string studentId, string firstName, string lastName, string email, int age, int daysLeft[], DegreeProgram degree);
    
    // Getters
    string getStudentId() const;
    string getfirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int* getDaysLeft(); // pointer to daysLeft array
    DegreeProgram getDegree() const;
    
    // Setters
    void setStudentId(string newId);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setEmail(string newEmail);
    void setAge(int newAge);
    void setDaysLeft(int newDaysLeft[]);
    void setDegree(DegreeProgram newDegree);
    
    // Print function
    void print() const;
private:
    // Data Members
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysLeft[3];
    DegreeProgram degree;
};

#endif
