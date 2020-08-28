// Parts.cpp
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Parts.h"

using namespace std;
namespace sdds {

	Arms::Arms() {
		force = -1;
	}

	Arms::Arms(int armsForce) {
		if (armsForce < 1) 
			force = MIN_FORCE;
		else 
			force = armsForce;
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

	int Arms::getForce() const {
		return force;
	}

	int Legs::getSpeed() const {
		return speed;
	}

	Arms& Arms::operator++() {
		force += 10;
		return *this;
	}

	Arms Arms::operator++(int) {
		Arms temp = *this;
		operator+=(10);
		return temp;
	}

	Arms& Arms::operator+=(int value) {
		force += value;
		if (force < 1) 
			force = 0;
		return *this;
	}
	Legs& Legs::operator-=(int value) {
		speed -= value;
		if (speed < 1) {
			speed = 0;
		}
		return *this;
	}

	bool operator>(const Legs& leg1, const Legs& leg2) {
		return leg1.getSpeed() > leg2.getSpeed();
	}

	bool operator<(const Legs& leg1, const Legs& leg2) {
		return leg1.getSpeed() < leg2.getSpeed();
	}


	bool operator>(const Arms& arms1, const Arms& arms2) {
		return arms1.getForce() > arms2.getForce();
	}

	bool operator<(const Arms& arms1, const Arms& arms2) {
		return arms1.getForce() < arms2.getForce();
	}
}
