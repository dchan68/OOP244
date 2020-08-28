//Ore.h
//Name: Daryan Chan
//ID: 113973192
//Section: NCC

#ifndef SDDS_ORE_H
#define SDDS_ORE_H

#include <iostream>

namespace sdds{
	const double DEFAULT_WEIGHT = 300.50;
	const int DEFAULT_PURITY = 20;
	const int CLASS_LEN = 30;
	const double EMPTY_WEIGHT = 0.0;
	const int EMPTY_PURITY = 0;

	class Ore{
		double weight;
		int purity;
		char classification[CLASS_LEN + 1]; 
	public:
		Ore();
		Ore(double weight, int purity, const char* classification = "Unknown");
		bool refine();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& is);
	};
	std::ostream& operator<<(std::ostream& os, const Ore& ore);
	std::istream& operator>>(std::istream& os, Ore& ore);
}
#endif