//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

namespace sdds {
	class ReadWriteable {
	public:
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
		virtual std::istream& read(std::istream& is = std::cin) = 0;
	};
	std::ostream& operator<<(std::ostream& os, const ReadWriteable& readWriteable);
	std::istream& operator>>(std::istream& is, ReadWriteable& readWriteable);
}
#endif
