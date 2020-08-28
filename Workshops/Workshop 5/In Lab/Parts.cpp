// Parts.cpp
//Workshop 5 In Lab
//Name: Daryan Chan
//Section: NCC
//ID: 113973192
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Parts.h"
#include "Robot.h"

using namespace std;
namespace sdds {
	Arms::Arms() {
		force = 0;
	}

	Arms::Arms(int force_) {
		if (force_ < 1)
			force = MIN_FORCE;
		else
			force = force_;
	}

	int Arms::getForce() const {
		return force;
	}

	Arms& Arms::operator++() {
		force += 10;
		return *this;
	}

	Arms Arms::operator++(int) {
		Arms temp = *this;
		operator += (10);    
		return temp;
	}

	Arms& Arms::operator+=(int value) {
		force += value;
		if (force < 1)
			force = 0;
		return *this;
	}
}