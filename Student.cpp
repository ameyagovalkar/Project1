#include "Student.h"
#include <iostream>

using namespace std;


Student::Student() {
	// TO BE COMPLETED
	StudentCWID = "0";
	courses = new string[50];
	grades = new char[50];
	gpa = 0.0;
	counter = 0;
}
Student::~Student() {
	//delete[] courses;
	//delete[] grades;
}
string Student::getCWID() {
	// TO BE COMPLETED

	return StudentCWID;
}
void Student::addCourseGrade(const string &courseName, char grade) {
	// TO BE COMPLETED
	courses[counter] = courseName;
	grades[counter] = grade;
	if (counter >= 50)
		counter = 50;
	else
		counter++;
}

double Student::getGPA() {
	// TO BE COMPLETED
	double points = 0.0;
	double classes = 0.0;

	for (int i = 0; i < counter; i++) {
		if (grades[i] == 'A' || grades[i] == 'B' || grades[i] == 'C' || grades[i] == 'D' || grades[i] == 'F')
		{
			classes++;
			if (grades[i] == 'A')
				points += 4.0;
			else if (grades[i] == 'B')
				points += 3.0;
			else if (grades[i] == 'C')
				points += 2.0;
			else if (grades[i] == 'D')
				points += 1.0;
		}

	}

	gpa = (points / classes);
	return gpa;
}
// print transcript in this (sample) format:
// TRANSCRIPT FOR CWID=279750343
// CS 121		C
// CS 253		B
// CS 131		B
// GPA = 2.6667

void Student::printTranscript() {
	// TO BE COMPLETED

	cout << endl << "TRANSCRIPT FOR CWID = " << StudentCWID << endl;
	for (int i = 0; i < counter; i++) {
		cout << courses[i] << "		" << grades[i] << endl;
	}
	cout << "GPA = " << getGPA() << endl;
}

Student::Student(const string& cwid)
{
	// TO BE COMPLETED
	StudentCWID = cwid;
	courses = new string[50];
	grades = new char[50];
	gpa = 0.0;
	counter = 0;
}

Student::Student(const Student& stu)
{
	Student studentTemp1;
	int count = stu.counter;
	studentTemp1.StudentCWID = stu.StudentCWID;

	for (int i = 0; i < count; i++)
	{
		studentTemp1.grades[i] = stu.grades[i];
		studentTemp1.courses[i] = stu.courses[i];
	}
	studentTemp1.gpa = stu.gpa;
}

Student& Student::operator=(const Student& stu)
{
	Student studentTemp;
	int count = stu.counter;
	studentTemp.StudentCWID = stu.StudentCWID;

	for (int i = 0; i < count; i++)
	{
		studentTemp.grades[i] = stu.grades[i];
		studentTemp.courses[i] = stu.courses[i];
	}
		studentTemp.gpa = stu.gpa;
		return *this;

}
