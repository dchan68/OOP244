//Workshop 2
//Name: Daryan Chan
//ID: 113973192

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Subject.h"
#include "utils.h"

using namespace std;

namespace sdds {
	
	
	// return void and receives a char pointer
	void read(char* SubjectName) {
		cout << "Enter subject name: ";
		read(SubjectName, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
	}

	// return void and receives a reference to an integer number
	void read(int& num) {
		cout << "Enter number of sections: ";
		read(num, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
	}

	// return void and receives interger array. receives an integer argument int number
	void read(int numInSec[], int noOfSec) {
		cout << "Enter the number of students in each one of the " << noOfSec << " sections:" << endl;
		for (int i = 0; i < noOfSec; i++) {
			cout << i + 1 << ": ";
			read(numInSec[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}
	}

	// last three read function
	void read(Subject& Sub) {
		Sub.m_subjectName = new char[71];
		read(Sub.m_subjectName);
		Sub.m_noOfSections = new int;
		read(*Sub.m_noOfSections);
		Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
		read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);//////
	}
	int report(const Subject& report) {
		int sum = 0;
		for (int i = 0; i < *report.m_noOfSections; i++) {
			cout << report.m_noOfStdsInSecs[i];
			if (i < *report.m_noOfSections - 1) {
				cout << ",";
			}
			sum += report.m_noOfStdsInSecs[i];
		}
		cout << endl;
		cout << report.m_subjectName << ": " << sum << endl;
		return sum;
	}

	void freeMem(Subject& deleteLocate) {
		delete[] deleteLocate.m_subjectName;
		delete[] deleteLocate.m_noOfStdsInSecs;
		delete deleteLocate.m_noOfSections;
	}
}