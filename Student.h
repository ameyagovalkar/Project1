#pragma once
#include <string>

using namespace std;

class Student {
public:
	Student(); // default constructor
	Student(const string& cwid);
	// constructor with parameter
	~Student(); //deconstructor to delete the dynamically allocated arrays
	void addCourseGrade(const string &courseName, char grade); // add course name and grade to student's record
	double getGPA(); // calculate and return GPA
	void printTranscript(); // print transcript - see Student.cpp for the format
	string getCWID(); // return the CWID of this student

	Student(const Student& stu);
	Student& Student::operator=(const Student& stu);

	friend class Registrar;
private:
	// any private member variables and methods go here
	// TO BE COMPLETED

	string StudentCWID;
	string *courses;
	char *grades;
	double gpa;
	int counter;

};
