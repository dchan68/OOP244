//Name: Daryan Chan     Username: dchan68

//contains the functions relating to user interface.


#include <iostream>
#include <cstdio> 
#include <cstring>
#include <iomanip>   //use this whenever you see cout
#include "PhoneDir.h"
#include "Contact.h"
#include "Tools.h"
#include "File.h"

using namespace std;
namespace sdds {

	// displays the user interface menu
	//belongs here since this clearly is for user interface as it lists the menu options
	int menu() {
		cout << endl
			<< "1- Add Phone Record " << endl;
		cout << "2- Search           " << endl;
		cout << "3- Sort             " << endl;
		cout << "4- List all         " << endl;
		cout << "0- Exit             " << endl;
		cout << "> ";
		return int(getLongLong(0, 4, "option"));
	}

	//the name of this function kind of gave it away.
	void phoneDir(const char* title, const char* filename) {
		int option;
		Contact C[MAX_REC_NO];
		Contact SearchRes[MAX_REC_NO];
		Contact temp;
		bool changed = false;
		int noOfRecs = readContacts(C, filename);
		int noOfSrchs;
		cout << title << ".................." << endl;
		do {
			switch (option = menu()) {
			case 0:
				cout << "Goodbye!" << endl;
				break;
			case 1: // add
				getContact(&temp);
				C[noOfRecs] = temp;
				noOfRecs++;
				changed = true;
				break;
			case 2: // search
				cout << "Name to search for: ";
				getStr(temp.name, 30);
				noOfSrchs = search(SearchRes, C, temp.name, noOfRecs);
				if (noOfSrchs) {
					printContacts(SearchRes, noOfSrchs);
				}
				else {
					cout << temp.name << ", not found!" << endl;
				}
				break;
			case 3:  // Sort
				sort(C, noOfRecs);
				cout << "Sorted!" << endl;
				changed = true;
				break;
			case 4:
				printContacts(C, noOfRecs);
				break;
			}
		} while (option);
		if (changed) {
			cout << endl << "The phone diecotry has changed!" << "Save changes? (Y/N): ";
			if (yes()) {
				writeContacts(C, noOfRecs, filename);
				cout << "Changes Saved!!" << endl;
			}
			else {
				cout << "Changes aborted!!" << endl;
			}
		}
	}
}