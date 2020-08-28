// Parts.cpp
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#include<iostream>
#include"Parts.h"

using namespace std;
namespace sdds {


	Arms::Arms() {
		force = 0;
	}

	Arms::Arms(int arms_force) {
		if (arms_force < 1) 
			force = MIN_FORCE;
		else 
			force = arms_force;
	}

	Arms::~Arms() {
	}

	int Arms::getForce() const {
		return force;
	}

	Arms& Arms::operator++() {
		return(*this) += 10;
	}

	Arms Arms::operator++(int) {
		Arms before = *this;
		(*this) += 10;
		return before;
	}

	Arms& Arms::operator+=(int value) {
		force = force + value;
		if (force < 1) force = 0;
		return *this;
	}

	Legs::Legs() {
		speed = 0;
	}

	Legs::Legs(int legSpeed) {
		if (legSpeed < 1) 
			speed = MIN_SPEED;
		else 
			speed = legSpeed;
	}

	Legs::~Legs() {
		
	}
	int Legs::getSpeed()const {
		return speed;
	}

	Legs& Legs::operator-=(int value) {
		speed = speed - value;
		if (speed < 1)
			speed = 0;
		return *this;
	}

	bool operator>(const Legs& firstRobotLeg, const Legs& secondRobotLeg) {
		return firstRobotLeg.getSpeed() > secondRobotLeg.getSpeed();
	}

	bool operator<(const Legs& firstRobotLeg, const Legs& secondRobotLeg) {
		return firstRobotLeg.getSpeed() < secondRobotLeg.getSpeed();
	}
	
	bool operator>(const Arms& firstArms, const Arms& secondArms) {
		return firstArms.getForce() > secondArms.getForce();
	}

	bool operator<(const Arms& firstArms, const Arms& secondArms) {
		return firstArms.getForce() < secondArms.getForce();		
	}

}