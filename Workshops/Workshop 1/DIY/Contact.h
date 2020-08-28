// name: Daryan Chan   ID:dchan68

//Contains the prototypes for Contact.cpp

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#define MAX_REC_NO 100

namespace sdds{

	struct Contact {
		char name[31];
		 long long phoneNumber;
    };

	long long getLongLong(long long min, long long max, const char* valueName);
	long long getPhoneNumber();
	void getContact(Contact* C);
	void printContact(const Contact* C);
	void getStr(char* str, int len);
	void getName(char* name);
	bool readContact(Contact* C, FILE* fptr);
	void writeContact(FILE* fptr, const Contact* C);
	int readContacts(Contact* contacts, const char* filename);
	void writeContacts(Contact* contacts, int cntno, const char* filename);
	bool nameInContact(const Contact* C, const char* nameSubStr);
	void printContacts(const Contact* C, int num);
}

#endif
