//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std;
namespace sdds{	
	void flushKeyboard() {
		char ch;
		do {
			ch = cin.get();
		} while (ch != '\n');
	}

	void select_clear(){
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	int readInt(int min, int max, const char* ErrorMess) {
		bool ok;
		int val;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
		return val;
	}

	void readLNum(unsigned long long& val, unsigned long long min, unsigned long long max, const char* ErrorMess){
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
	}

	ostream& printChar(int len, const char* character, ostream& os){
		for (int i = 0; i < len; i++, os << character);
		return os;
	}

	istream& readInt(int& val, int min, int max, const char* errorMessage, istream& is){
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << errorMessage);
		return is;
	}

	istream& readS(char* str, int len, const char* errorMessage, istream& is) {
		bool ok;
		do {
			ok = true;
			is.getline(str, len + 1, '\n');
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
				ok = false;
			}
		} while (!ok && cout << errorMessage);
		return is;
	}
}