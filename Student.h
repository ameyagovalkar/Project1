#pragma once
#include <string>

using namespace std;

class Student {
public:
	Student(); // default constructor
	Student(const string &cwid) {
		// TO BE COMPLETED
		StudentCWID = cwid;
		courses = new string[50];
		grades = new char[50];
		gpa = 0.0;
		counter = 0;
	} // constructor with parameter
	~Student(); //deconstructor to delete the dynamically allocated arrays
	void addCourseGrade(const string &courseName, char grade); // add course name and grade to student's record
	double getGPA(); // calculate and return GPA
	void printTranscript(); // print transcript - see Student.cpp for the format
	string getCWID(); // return the CWID of this student
private:
	// any private member variables and methods go here
	// TO BE COMPLETED

	string StudentCWID;
	string * courses;
	char * grades;
	double gpa;
	int counter;
};
