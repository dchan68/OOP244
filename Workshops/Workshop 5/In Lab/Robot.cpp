// Parts.cpp
//Workshop 5 In Lab
//Name: Daryan Chan
//Section: NCC
//ID: 113973192
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Robot.h"
#include "Parts.h"

using namespace std;
namespace sdds {

	Robot::Robot() {
		nickname[NICK_MAX_LEN] = '\0';
		durability = -1;
		arms = -1;
	}

	Robot::Robot(const char* Name, int newforce, int dur) {
		if (Name == nullptr) {
			Robot();
		}
		else {
			if (strlen(Name) > NICK_MAX_LEN + 1) {
				strncpy(nickname, Name, NICK_MAX_LEN + 1);
			}
			else{
				strcpy(nickname, Name);
			}
			if (dur < 1) {
				durability = 100;
			}
			else{
				durability = dur;
			}
			arms = newforce;
		}
	}

	Robot::~Robot() {
	}

	ostream& Robot::display() const {
		if (nickname == '\0' || durability == -1) {
			cout << "This Robot isn't operational" << endl;
		}
		else {

			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
		}
		return cout;
	}

	Robot::operator bool() const {
		return nickname == nullptr || durability == -1;
	}
}
