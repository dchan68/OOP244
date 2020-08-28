//metal.h
//Name: Daryan Chan
//ID: 113973192
//Section: NCC

#ifndef SDDS_METAL_H
#define SDDS_METAL_H

#include "Ore.h"
#include <iostream>

namespace sdds{
	const double DEFAULT_MOHS = 2.5;
	const double EMPTY_MOHS = 0.0;
	const int NAME_LEN = 10;

	class Metal : public Ore{
		char* name;
		double mohs;
	public:
		Metal();
		~Metal();
		Metal(double weight, int purity, const char* classification, const char* newName, double newMohs);
		void refine();
		bool isEmpty() const;
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& is);
	};
	std::ostream& operator<<(std::ostream& os, const Metal& met);
	std::istream& operator>>(std::istream& is, Metal& met);
}
#endif