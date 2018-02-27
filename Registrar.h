#pragma once
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;

class Registrar {
public:
	void readTextfile(string filename); // Load information from a text file with the given filename: THIS IS COMPLETE
	void addLine(string courseName, string cwid, char grade); // process a line from the text file
	Student& getStudent(string cwid) const; // return the Student object corresponding to a given CWID
											// getStudent must throw an exception if cwid is invalid
											// add constructors, destructors, assignment operators if needed

	Registrar();                           //registrar constructor, creates dynamic array students
	~Registrar();                          //registrar destructor, deletes dynamic array students
	//Registrar(const Registrar& reg);       //copy constructor
	//Registrar& Registrar::operator=(const Registrar& reg);         //assignment operator

private:
	// Add private member variables for your class along with any 
	// other variables required to implement the public member functions
	// TO BE COMPLETED

	Student *students;
	int size;
	int stored;
};
