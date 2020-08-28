//Workshop 2 at_home
//Name: Daryan Chan 
//id: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "School.h"
#include "utils.h"

using namespace std;
namespace sdds {
	void read(School& Sch) {
		char school_name[61];
		cout << "Please enter the name of the school:\n> ";
		read(school_name, 60, "Name is too long, only 60 characters allowed!\nRedo Entry: ");
		Sch.m_name = new char[strlen(school_name) + 1]; //+1 is for the null terminator
		strcpy(Sch.m_name, school_name);

		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");
		Sch.m_subjects = new Subject[Sch.m_noOfSubjects];  //Allocated array of subjects entered by users to m_subjects
		for (int i = 0; i < Sch.m_noOfSubjects; i++) {
			cout << i + 1 << ") ------------------------------" << endl;
			read(Sch.m_subjects[i]); //reading the subject's name
		}
	}
	int report(const School& schoolreport) {
		int final = 0, semi_final = 0;
		cout << schoolreport.m_name << endl;
		cout << "Subject Enrollments" << endl;
		for (int i = 0; i < schoolreport.m_noOfSubjects; i++) {
			for (int j = 0; j < *schoolreport.m_subjects[i].m_noOfSections; j++) {
				cout << schoolreport.m_subjects[i].m_noOfStdsInSecs[j];
				semi_final += schoolreport.m_subjects[i].m_noOfStdsInSecs[j];
				if (j == *schoolreport.m_subjects[i].m_noOfSections - 1) {
					cout << endl;
					cout << schoolreport.m_subjects[i].m_subjectName << ": " << semi_final << endl;
					final += semi_final;
				}
				if (j < *schoolreport.m_subjects[i].m_noOfSections - 1) {
					cout << ",";
				}
			}
			semi_final = 0;
		}
		cout << "Total enrollment: " << final << endl;
		return final;
	}
	void freeMem(School& free) {
		delete[] free.m_name;
		delete[] free.m_subjects;
	}
}
