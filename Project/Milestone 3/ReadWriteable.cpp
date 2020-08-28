//Name: Daryan Chan
//ID: 113973192
//Section NCC

#include <iostream>
#include <cstring>
#include "ReadWriteable.h"
using namespace std;

namespace sdds {
	ostream& operator<<(ostream& os, const ReadWriteable& print) {
		return print.write(os);
	}

	istream& operator>>(istream& is, ReadWriteable& input) {
		return input.read(is);
	}
}