// Robot.cpp
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Robot.h"
#include "Parts.h"

using namespace std;
namespace sdds
{

	Robot::Robot() {
		nickname[0] = '\0';
		durability = -1;
		arms = -1;
		legs = -1;
	}

	Robot::Robot(const char* Name, int newForce, int newSpeed, int dur) {
		if (Name == nullptr) 
			Robot();
		else {
			if (strlen(Name) > NICK_MAX_LEN + 1) 
				strncpy(nickname, Name, NICK_MAX_LEN + 1);
			else
				strcpy(nickname, Name);
			if (dur < 1) 
				durability = 100;
			else
				durability = dur;
			legs = Legs(newSpeed);
			arms = Arms(newForce);
		}
	}

	ostream& Robot::display() const {
		if (nickname != '\0' || durability != -1) {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
			cout << "Legs: " << legs.getSpeed() << endl;
		}
		else 
			cout << "This Robot isn't operational" << endl;
		return cout;
	}

	Robot::operator bool() const {
		return nickname == nullptr || durability < 0;
	}
	Arms Robot::getArms() const {
		Arms temp = this->arms;
		return temp;
	}
	Legs Robot::getLegs() const {
		Legs temp = this->legs;
		return temp;
	}
	Robot& Robot::operator-=(int dur) {
		durability -= dur;
		if (durability < 1) {
			durability = 0;
		}
		return *this;
	}
	void box(Robot& Robot1, Robot& Robot2) {								//THis function was taken from Terry, ID 141813188
		cout << "Attempting to begin a Robot boxing match" << endl;
		if (Robot1 || Robot2) {
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
		}
		else {
			cout << "Both participants are operational... beginning the bout" << endl;
			do {
				if (Robot1.getLegs() > Robot2.getLegs()) {
					Robot2 -= (Robot1.getArms().getForce());
					if (Robot2) 
						Robot1 -= (Robot2.getArms().getForce());
				}
				else {
					if (Robot1.getLegs() < Robot2.getLegs()) {
						Robot1 -= (Robot2.getArms().getForce());
						if (Robot1) 
							Robot2 -= (Robot1.getArms().getForce());
					}
				}
			} while ((Robot2.operator-= (Robot1.getArms().getForce()) < -1 && Robot1.operator-= (Robot2.getArms().getForce() >= 0)) || ((Robot2.operator-= (Robot1.getArms().getForce()) >= 0 && Robot2.operator-= (Robot1.getArms().getForce()) < -1)));
			cout << "The bout has concluded... the winner is: " << endl;
			if (Robot1) 
				Robot1.display();
			else 
				Robot2.display();
		}
	}
}


