//Workshop 2
//Name: Daryan Chan 
//id: 113973192


#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H

namespace sdds {
	struct Subject {
		int *m_noOfSections;
		int *m_noOfStdsInSecs;
		char *m_subjectName;
	};

	void read(char* SubjectName);
	void read(int& num);
	void read(int numInSec[], int noOfSec);
	void read(Subject& Sub);
	int report(const Subject& report);
	void freeMem(Subject& deleteLocate);
}

#endif


