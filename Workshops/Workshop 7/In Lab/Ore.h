// Ore.h
//Name: Daryan Chan
//ID 113973192
//Section NCC

#ifndef SDDS_ORE_H
#define SDDS_ORE_H

namespace sdds{	
	const double DEFAULT_WEIGHT = 300.50;
	const int DEFAULT_PURITY = 20;
	const int CLASS_LEN = 30;

class Ore {
	double weight;
	int purity;
	char classification[CLASS_LEN +1];

public:
	Ore();
	Ore(double, int, const char* c="Unknown");
	~Ore();
	bool refine();
	std::ostream& display(std::ostream& os) const;
	std::istream& input(std::istream& is);

};
std::ostream& operator<<(std::ostream& os, const Ore& ore);
std::istream& operator>>(std::istream& os, Ore& ore);
}
#endif