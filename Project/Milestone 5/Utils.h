//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>

using namespace std;
namespace sdds {
	void flushKeyboard();
	void select_clear();
	int readInt(int min, int max, const char* ErrorMess = "");
	istream& readInt(int& val, int min, int max, const char* errorMessage = "", istream& is = cin);
	istream& readS(char* str, int len, const char* errorMessage = "", istream& is = cin);
	void readLNum(unsigned long long& val, unsigned long long min, unsigned long long max, const char* ErrorMess);
	ostream& printChar(int len, const char* ch, ostream& os = cout);
}
#endif