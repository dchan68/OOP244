// RobotSquad.h
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#ifndef SDDS_ROBOTSQUAD_H
#define SDDS_ROBOTSQUAD_H
#include "Robot.h"
#include "Parts.h"

namespace sdds
{
	class RobotSquad {
		char* name;
		Robot* Robots;
		int count;
		
	public:
		RobotSquad(const char* r_name = "No Name");
		~RobotSquad();
		const char* getName()const;
		int getCount()const;
		std::ostream& display() const;
		Robot* getRoster() const;
		RobotSquad& operator+=(Robot& robots);
		RobotSquad& operator--();

	};
}
#endif