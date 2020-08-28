// Robot.h
//Workshop 5 In Lab
//Name: Daryan Chan
//Section: NCC
//ID: 113973192
//Email: dchan68@myseneca.ca

#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include "Parts.h"

namespace sdds {
	const int NICK_MAX_LEN = 10;
	class Robot {
		char nickname[NICK_MAX_LEN + 1];
		int durability = 0;
		Arms arms;
	public:
		Robot();
		Robot(const char* Name, int newforce, int durab);
		~Robot();
		std::ostream& display() const;
		operator bool() const;
	};
}
#endif
