//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "ReadWriteable.h"

using namespace std;

namespace sdds {
	ostream& operator<<(ostream& os, const ReadWriteable& readWriteable){
		return readWriteable.write(os);
	}

	istream& operator>>(istream& is, ReadWriteable& readWriteable){
		return readWriteable.read(is);
	}
}