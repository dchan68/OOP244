// Robot.h
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
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
		Legs legs;
	public:
		Robot();
		Robot(const char* Name, int newForce, int newspeed, int dur);
		std::ostream& display() const;
		operator bool() const;
		Arms getArms() const;
		Legs getLegs() const;
		Robot& operator-=(int);
	};

	void box(Robot&, Robot&);
}
#endif

