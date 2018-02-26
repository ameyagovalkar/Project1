#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <typeinfo>
#include "Registrar.h"
//#pragma warning (disable: 4101)

using namespace std;

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE

void Registrar::readTextfile(string filename) {
	ifstream myfile(filename);
	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			// cout << cwid << " " << grade << endl;
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}
// return Student object corresponding to a given CWID
// getStudent must throw an exception if cwid is invalid

Student& Registrar::getStudent(string cwid) const {
	// TO BE COMPLETED

	for (int i = 0; i < size; i++)
	{
		if (cwid == students[i].getCWID())
		{
			return students[i];
		}
		else if (i == size - 1)
		{
			throw invalid_argument("Invalid CWID: " + cwid);
		}
	}
}


// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) {
	// TO BE COMPLETED

	for (int i = 0; i < size; i++)
	{
		if (cwid == students[i].getCWID())
		{
			students[i].addCourseGrade(courseName, grade);
			return;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (students[i].getCWID() == "0")
		{
			students[i].StudentCWID = cwid;
			students[i].addCourseGrade(courseName, grade);
			return;
		}
	}
}

Registrar::~Registrar() {
	delete[] students;

}

Registrar::Registrar()
{
	size = 50000;
	students = new Student[size];
}

Registrar::Registrar(const Registrar& reg)
{
	students = new Student[size];
	for (int i = 0; i < size; i++)
	{
		students[i] = reg.students[i];
	}
}
