//Name: Daryan Chan     Username: dchan68

//containts the prototypes for File.cpp

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {

	void sort(Contact c[], int n);
	int compare(const Contact* A, const Contact* B);
	int search(Contact* found, const Contact* C, const char* name, int noOfRecs);

}

#endif