//DIY workshop 3
//Name: Daryan Chan
//Student ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca
#ifndef SDDS_MARKSREPORT_H
#define SDDS_MARKSREPORT_H

#include "Mark.h"

namespace sdds{	
	class MarksReport{
		Mark* m_markArray;
		char m_reportName[70];
		int noOfmarks;
	
	public:
		void initialize();
		void getMarks();
		void print();
		void terminate();
	};
}
#endif
