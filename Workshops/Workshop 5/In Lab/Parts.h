// Parts.h
//Workshop 5 In Lab
//Name: Daryan Chan
//Section: NCC
//ID: 113973192
//Email: dchan68@myseneca.ca

#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H

namespace sdds {
	const int MIN_FORCE = 50;
	
	class Arms {
		int force;
	public:
		Arms();
		Arms(int force_);
		int getForce() const;
		Arms& operator++();
		Arms operator++(int);
		Arms& operator+=(int);

	};
}

#endif