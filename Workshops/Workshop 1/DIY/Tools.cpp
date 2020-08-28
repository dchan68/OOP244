//Name: Daryan Chan     Username: dchan68

// Functions in here are all the helper functions with no relation with phone book and are used as utilities.

#include <iostream>
#include <cstdio> 
#include <cstring>
#include <iomanip>   //use this whenever you see cout
#include "Contact.h"
#include "Tools.h"

using namespace std;
namespace sdds {

	//Same reason as above. Doesn't belong in any of the other modules since it doesn't pertain to their responsilities.
	//I see this as a helper function
	void toLowerCase(char* lowerCase, const char* str) {
		int i;
		for (i = 0; str[i] && i < 30; i++) {
			lowerCase[i] = str[i] | 0x20;
		}
		lowerCase[i] = 0;
	}

	//Again, looks like a helper function and thus belongs in tools
	bool yes() {
		char ch;
		ch = cin.get();
		cin.ignore(1000, '\n');
		return ch == 'y' || ch == 'Y';
	}

	//also as tools since I believe this function is validating something, therefore as goes in tools
	bool valid(long long min, long long max, long long val) {
		return min <= val && val <= max;
	}
}