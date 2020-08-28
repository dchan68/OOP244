//at_home Workshop 4
//Name:Daryan Chan
//Section NCC
//Email: dchan68@myseneca.ca

#ifndef SDDS_BOUQUET_H
#define SDDS_BOUQUET_H
#include "Flower.h"

namespace sdds {

	const int MESS_MAX_LEN = 25;
	const int MAX_FLOWERS = 3;
	
	class Bouquet {
		double b_price;
		char* b_message;
		Flower* b_flowers;
		int b_flowerCount;
		void flushKeyboard() const;

	public:
		Bouquet();
	    Bouquet(const Flower* flowers, int noOfFlowers = MAX_FLOWERS, const char* message="Congratulations");
		~Bouquet();
		const char* message() const;
		double price() const;
		bool isEmpty()const;
		void setEmpty();
		void setMessage(const char* prompt);
		void discardBouquet();
		void arrangeBouquet();
		std::ostream& display() const;
	};
}

#endif