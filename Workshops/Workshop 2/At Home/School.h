//Workshop 2 at_home
//Name: Daryan Chan 
//id: 113973192
#ifndef SDDS_SCHOOL_H
#define SDDS_SCHOOL_H

#include "Subject.h"

namespace sdds {

	struct School {
		int m_noOfSubjects;
		Subject* m_subjects; //use pointers to access the struct Subject in Subject.h
		char* m_name;
	};

	void read(School& Sch);
	int report(const School& report);
	void freeMem(School& deleteLocate);


}

#endif
