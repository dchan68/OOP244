//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "ParkingLot.h"
#include "ParkingSpot.h"
#include "utils.h"
using namespace std;
namespace sdds {
	void setEmpty(ParkingSpot& pkingspot) {
		strcpy(pkingspot.licensePlate, "\0");  //initializing plate number to null terminator
		pkingspot.make_Model = nullptr;
	}

	bool isEmpty(const ParkingSpot& empty) {
		if (empty.make_Model == nullptr)
			return true;
		else
			return false;
	}

	void freeSpot(ParkingSpot& pspot) {
		delete[] pspot.make_Model;
		setEmpty(pspot);
	}

	void print(const ParkingSpot& pspot) {

		cout << pspot.make_Model << ", plate number: " << pspot.licensePlate << endl;
	}

	void parkCar(ParkingSpot& pspot) {
		pspot.make_Model = new char[61];

		cout << "Make and Model: ";
		read(pspot.make_Model, 61, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");
		cout << "License Plate: ";
		read(pspot.licensePlate, 9, "Too long, License Plate must be shorter than 8 characters\nRedo Entry: ");
	}
}