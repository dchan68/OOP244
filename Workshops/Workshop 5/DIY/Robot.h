// Robot.h
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#ifndef SDDS_Robot_H
#define SDDS_Robot_H
#include "Parts.h"

namespace sdds {

	int const NICK_MAX_LEN = 10;

	class Robot{
		char nickname[NICK_MAX_LEN];
		int durability;
		Arms arms;
		Legs legs;
	public:
		Robot();
		Robot(const char* Name, int newForce, int newSpeed, int dur);
		~Robot();
		std::ostream& display() const;
		operator bool() const;
		Arms getArms() const;
		Legs getLegs()const;
		Robot& operator-=(int);
	};

	void box(Robot& firstRobot, Robot& secondRobot);

}


#endif