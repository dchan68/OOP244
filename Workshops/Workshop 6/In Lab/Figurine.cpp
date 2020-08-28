#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <iomanip>

#include "Figurine.h"

using namespace std;

namespace sdds {

	Figurine::Figurine() {

		name[0] = '\0';
		pose = nullptr;
		price = -1;

	}

	Figurine::Figurine(const char* newName, const char* newPose, double newPrice) {

		if (newName == nullptr || newPose == nullptr || newName[0] == '\0') {

			name[0] = '\0';
			pose = nullptr;
			price = -1;

		}

		else {
			setName(newName);
			setPose(newPose);
			setPrice(newPrice);
		}


	}

	Figurine::Figurine(const Figurine& figurine) {

		setName(figurine.name);
		setPrice(figurine.price);
		setPose(figurine.pose);

	}

	Figurine::~Figurine() {

		delete[] pose;

	}

	void Figurine::setName(const char* newName) {

		if (strlen(newName) < MAX_NAME_LEN) {

			strcpy(name, newName);

		}

		else {
			strncpy(name, newName, MAX_NAME_LEN);
			name[MAX_NAME_LEN] = '\0';

		}

	}

	void Figurine::setPose(const char* newPose) {

		if (newPose == nullptr) {
			pose = nullptr;
		}

		else {
			pose = new char[strlen(newPose) + 1];
			strcpy(pose, newPose);

		}
	}

	void Figurine::setPrice(double newPrice) {
		price = newPrice < 1 ? DEFAULT_PRICE : newPrice;

	}

	ostream& Figurine::display()const {

		if (pose == nullptr) {
			cout << "This Figurine has not yet been sculpted" << endl;
		}
		else {
			cout << "Figurine Details" << endl << "Name: " << name
				<< endl << "Pose: " << pose
				<< endl << "Price: " << fixed << setprecision(2) << price << endl;
		}
		return cout;
	}

	Figurine::operator bool()const {
		return (name[0] == '\0');
	}
}