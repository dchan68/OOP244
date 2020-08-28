// Figurine.h
//Name: Daryan Chan
//Section NCC
//ID: 113973192
//email: dchan68@myseneca.ca

#ifndef SDDS_FIGURINE_H
#define SDDS_FIGURINE_H
#include <iostream>

namespace sdds {
	const int MAX_NAME_LEN = 20;
	const double DEFAULT_PRICE = 25.25;

	class Figurine {
		char name[MAX_NAME_LEN+1];
		char* pose;
		double price;
	public:
		Figurine();
		Figurine(const char*, const char*, double);
		Figurine(const Figurine&);
		~Figurine();
		void setName(const char*);
		void setPose(const char*);
		void setPrice(double);
		std::ostream& display() const;
		operator bool() const;
	};
}

#endif
