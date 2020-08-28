//Figurine.cpp
//Name: Daryan Chan
//Section NCC
//ID: 113973192
//email: dchan68@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Figurine.h"

using namespace std;
namespace sdds {

	Figurine::Figurine() {
		name[0] = '\0';
		pose = nullptr;
		price = -1;
		copy = false;
	}

	Figurine::Figurine(const char* newName, const char* newPose, double newPrice) {
		if (newName == nullptr || newPose == nullptr ||  newName[0] == '\0') {
			name[0] = '\0';
			pose = nullptr;
			price = -1;
			copy = false;
		}
		else {
			if (strlen(newName) < MAX_NAME_LEN) {
				strcpy(name, newName);
			}
			else {
				strncpy(name, newName, MAX_NAME_LEN);
				name[MAX_NAME_LEN] = '\0';
			}
			pose = new char[strlen(newPose) + 1];
			strcpy(pose, newPose);
			if (newPrice < 1) {
				price = DEFAULT_PRICE;
			}
			else {
				price = newPrice;
			}
			copy = false;
		}
	}

	Figurine::Figurine(const Figurine& figurine) {
		price = figurine.price;
		strncpy(name, figurine.name, MAX_NAME_LEN);
		if (figurine.pose != nullptr) {
			pose = new char[strlen(figurine.pose) + 1];
			strcpy(pose, figurine.pose);
		}
		else {
			pose = nullptr;
		}
		copy = true;
	}

	Figurine::~Figurine() {
		delete[] pose;
	}

	void Figurine::setName(const char* newName) {
		strncpy(name, newName, MAX_NAME_LEN);
	}

	void Figurine::setPose(const char* newPose) {
		pose = new char[strlen(newPose) + 1];
		strcpy(pose, newPose);
	}

	void Figurine::setPrice(double newPrice) {
		if (newPrice < 1) {
			price = DEFAULT_PRICE;
		}
		else {
			price = newPrice;
		}
	}

	Figurine::operator bool() const {
		return name == nullptr || name[0] == '\0';
	}

	Figurine& Figurine::operator=(const Figurine& figurine) {
		if (this != &figurine) {
			delete[] pose;
			setPrice(figurine.price);
			setName(figurine.name);
			if (figurine.pose == nullptr) {
				pose = nullptr;
			}
			else {
				setPose(figurine.pose);
			}
			copy = true;
		}
		return *this;
	}

	bool Figurine::isCopy() const {
		return copy;
	}

	ostream& Figurine::display() const {
		if (*this) {
			cout << "This Figurine has not yet been sculpted" << endl;
		}
		if (*this && isCopy()) {
			cout << "This is a replica of emptiness" << endl;
		}
		if (!*this) {
			cout << "Figurine Details" << endl;
			cout << "Name: " << name << endl;
			cout << "Pose: " << pose << endl;
			cout << "Price: " << fixed << setprecision(2) << price << endl;
			if (!*this && isCopy()) {
				cout << "This is a replica" << endl;
			}
		}
		return cout;
	}

	const char* Figurine::getName() const {
		return name;
	}

	const char* Figurine::getPose() const {
		return pose;
	}

	const double Figurine::getPrice() const {
		return price;
	}

	bool operator==(const Figurine& lo, const Figurine& ro) {
		bool result = false;
		if (lo.getName() == ro.getName() && lo.getPose() == ro.getPose() && lo.getPrice() == ro.getPrice() && (lo.isCopy() == false || ro.isCopy())) {
			result = true;
		}
		return result;
	}
}
