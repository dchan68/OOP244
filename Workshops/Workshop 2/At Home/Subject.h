//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H

namespace sdds {
	struct Subject {
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};

	void read(char* SubjectName);
	void read(int& num);
	void read(int numInSec[], int noOfSec);
	void read(Subject& Sub);
	int report(const Subject& report);
	void freeMem(Subject& deleteLocate);
}
#endif // !SDDS_SUBJECT_H

