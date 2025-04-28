//
//  student.cpp
//  C867_PA
//
//  Created by Jose D. Romero on 4/27/25.
//

# include "student.h"
# include <iostream>
using namespace std;

// Constructor
Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysLeft[], DegreeProgram degree) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for(int i = 0; i < 3; ++i){
        this->daysLeft[i] = daysLeft[i];
    }
    this->degree = degree;
}

// Getters
string Student::getStudentId() const { return studentId; }
string Student::getfirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmail() const { return email; }
int Student::getAge() const { return age; }
int* Student::getDaysLeft() { return daysLeft; } // pointer to daysLeft array
DegreeProgram Student::getDegree() const { return degree; }

// Setters
void Student::setStudentId(string newId) { studentId = newId; }
void Student::setFirstName(string newFirstName) { firstName = newFirstName; }
void Student::setLastName(string newLastName) { lastName = newLastName; }
void Student::setEmail(string newEmail) { email = newEmail; }
void Student::setAge(int newAge) { age = newAge; }
void Student::setDaysLeft(int newDaysLeft[]) {
    for (int i = 0; i < 3; ++i) {
        daysLeft[i] = newDaysLeft[i];
    }
}
void Student::setDegree(DegreeProgram newDegree){ degree = newDegree; }

// Print function
void Student::print() const {
    cout << studentId << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {" << daysLeft[0] << ", " << daysLeft[1] << ", " << daysLeft[2] << "} ";
    cout << "Degree Program: ";
    switch (degree) {
        case SECURITY:
            cout << "Security" << endl;
            break;
        case NETWORK:
            cout << "Network" << endl;
            break;
        case SOFTWARE:
            cout << "Software" << endl;
            break;
    }
}
