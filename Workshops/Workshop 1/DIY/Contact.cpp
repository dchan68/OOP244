//Name: Daryan Chan     Username: dchan68

//contains the functions for contacts and everything contact related.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#include "Tools.h"

using namespace std;
namespace sdds {

	//Goes here since it creates a error message if you don't enter the contact info correctly. Therefore it relates to contacts
	long long getLongLong(long long min, long long max, const char* valueName) {
		long long val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Bad Number, try again: ";
			}
			else {
				if (!valid(min, max, val)) {
					cout << "Invalid " << valueName << "!" << endl
						<< "The " << valueName << " must be between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}

	//phone number is important and thus goes into contacts.
	long long getPhoneNumber() {
		return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
	}

	//Goes into contacts since it literally says get contacts and it's code clearly shows it.
	void getContact(Contact* C) {
		cout << "Name: ";
		getName(C->name);
		cout << "Phone Number: ";
		C->phoneNumber = getPhoneNumber();
	}

	// again it's dealing with contacts so it belongs here.
	void printContact(const Contact* C) {
		cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
	}

	//I assume it's also in contact module because the char string relates to contacts, like the name 
	void getStr(char* str, int len) {
		cin.getline(str, len, '\n');
	}

	//contact related function so it belongs here
	void getName(char* name) {
		getStr(name, 30);
	}

	//it's reading contact information and thus seems likely it relates to this module since instruction says contact should
	//contain all contact related functions
	bool readContact(Contact* C, FILE* fptr) {
		return fscanf(fptr, "%[^,],%lld", C->name, &C->phoneNumber) == 2;
	}

	//contact needs information and this function name seems to deals with the contact information
	void writeContact(FILE* fptr, const Contact* C) {
		fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
	}

	//placed this here since fopen is opening a file source, I assume it's trying to get contact information as well.
	int readContacts(Contact* contacts, const char* filename) {
		FILE* fptr = fopen(filename, "r");
		Contact C;
		int num;
		for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++) {
			contacts[num] = C;
		}
		return num;
	}

	//again, it seems to relate to anything contact related so I placed it here.
	void writeContacts(Contact* contacts, int cntno, const char* filename) {
		FILE* fptr = fopen(filename, "w");
		int num;
		for (num = 0; num < cntno; num++) {
			writeContact(fptr, &contacts[num]);
		}
		fclose(fptr);
	}

	//since this relates to name and contacts needs names, I placed it here.
	bool nameInContact(const Contact* C, const char* nameSubStr) {
		char name[31];
		char subName[31];
		toLowerCase(name, C->name);
		toLowerCase(subName, nameSubStr);
		return strstr(name, subName) != nullptr;
	}

	//contact related function so it belongs here.
	void printContacts(const Contact* C, int num) {
		for (int i = 0; i < num; i++) {
			printContact(&C[i]);
		}
	}
}