//Name: Daryan Chan
//ID: 113973192
//Section NCC

#include "ReadWriteable.h"
#include <iostream>
namespace sdds{
	std::ostream& operator<<(std::ostream& os, const ReadWriteable& readWriteable){
		readWriteable.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, ReadWriteable& readWriteable){
		readWriteable.read(is);
		return is;
	}
}
