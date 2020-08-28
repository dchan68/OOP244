//Name: Daryan Chan     Username: dchan68

//functions relating to file management

#include <iostream>
#include <cstdio> 
#include <cstring>
#include "Contact.h"
#include "Tools.h"
#include "File.h"

using namespace std;
namespace sdds {

	//I think it belongs here since compare can be used for file management. Like maybe if you have one contact
	//and you want to see if that contact is valid based on existing pre-existing contacts.
	int compare(const Contact* A, const Contact* B) {
		return strcmp(A->name, B->name);
	}

	//belongs here since sort can help with file management.
	void sort(Contact c[], int n) {
		Contact temp;
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (compare(&c[j], &c[j + 1]) > 0) {
					temp = c[j];
					c[j] = c[j + 1];
					c[j + 1] = temp;
				}
			}
		}
	}
	//also belongs here since search can be used for file management if this function searches for something
	int search(Contact* found, const Contact* C, const char* name, int noOfRecs) {
		int i;
		int noOfMatches = 0;
		for (i = 0; i < noOfRecs; i++) {
			if (nameInContact(&C[i], name)) {
				found[noOfMatches] = C[i];
				noOfMatches++;
			}
		}
		return noOfMatches;
	}
}