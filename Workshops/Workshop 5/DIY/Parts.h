// Parts.h
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H

namespace sdds{
	const int  MIN_SPEED = 25;
	const int MIN_FORCE = 50;

	class Legs {
		int speed;

	public:
		Legs();
		Legs(int);
		~Legs();
		int getSpeed()const;
		Legs& operator-=(int);
	};
		
	class Arms {
		int force;
	public:
		Arms();
		Arms(int armsForce);
		~Arms();
		int getForce() const;
		Arms& operator++();
		Arms operator++(int);
		Arms& operator+=(int);

	};

	bool operator>(const Legs&, const Legs&);
	bool operator<(const Legs&, const Legs&);
	bool operator>(const Arms&, const Arms&);
	bool operator<(const Arms&, const Arms&);

}
#endif