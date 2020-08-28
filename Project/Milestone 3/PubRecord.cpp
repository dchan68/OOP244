//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "colors.h"
#include "PubRecord.h"
#include "ReadWriteable.h"
#include "Date.h"

using namespace std;
namespace sdds {
	const char* PubRecord::name() const {
		return publicationName;
	}

	void PubRecord::name(const char* name) {
		if (name != nullptr) {
			publicationName = new char[strlen(name) + 1];
			strcpy(publicationName, name);
		}
		else {
			publicationName = nullptr;
		}
	}

	PubRecord::PubRecord() {
		publicationName = nullptr;
		shelfNum = 0;
		m_mediaType = SDDS_CONSOLE;
	}

	PubRecord::PubRecord(const PubRecord& copy) {
		name(copy.publicationName);
		shelfNum = copy.shelfNum;
		m_mediaType = copy.m_mediaType;
	}

	PubRecord::~PubRecord() {
		delete[] publicationName;
	}

	PubRecord& PubRecord::operator=(const PubRecord& copy) {
		if (this != &copy) {
			name(copy.publicationName);
			shelfNum = copy.shelfNum;
			m_mediaType = copy.m_mediaType;
		}
		return *this;
	}

	void PubRecord::mediaType(int type) {
		m_mediaType = type;
	}

	int PubRecord::mediaType() const {
		return m_mediaType;
	}

	int PubRecord::shelfNo() const {
		return shelfNum;
	}

	void PubRecord::readShelfNo() {
		int numbers;
		readNum(numbers, 100, 999, "Invalid Shelf Number, Enter again: ");
		shelfNum = numbers;
	}

	void PubRecord::readNum(int& val, int min, int max, const char* errorMess) {
		bool trueFalse;
		char newLine;
		do {
			cin >> val;
			newLine = cin.get();
			if (!cin.fail() || newLine == '\n') {
				trueFalse = val >= min && val <= max;
			}
			else {
				trueFalse = false;
				cin.clear();
				cin.ignore(2000, '\n');
			}
		} while (!trueFalse && cout << errorMess);
	}

	bool PubRecord::operator==(const char match) {
		if (recID() == match) 
			return true;
		else 
			return false;
	}

	bool PubRecord::operator==(const char* cString) {
		if (strcmp(publicationName, cString)) 
			return true;
		else 
			return false;
	}

	PubRecord::operator bool() const {
		return (publicationName != nullptr);
	}

}