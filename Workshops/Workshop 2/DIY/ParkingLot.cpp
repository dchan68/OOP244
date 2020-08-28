//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"
#include "ParkingSpot.h"
#include "ParkingLot.h"

using namespace std;
namespace sdds {

	//Initializaing  
	void setEmpty(ParkingLot& plot) {
		plot.noOfParkingSpot = 0;
		plot.ps = nullptr;
	}

	bool isEmpty(const ParkingLot& plot) {
		if (plot.ps == nullptr)
			return true;
		else
			return false;
	}

	void openParking(ParkingLot& lot, int noOfSpots) {
		lot.ps = new ParkingSpot[noOfSpots];  //dynamic memory allocation. 
		lot.noOfParkingSpot = noOfSpots;
		for (int i = 0; i < noOfSpots; i++) {
			setEmpty(lot.ps[i]);
		}
	}

	int parkCar(ParkingLot& plot) {

		for (int i = 0; i < plot.noOfParkingSpot; i++) {
			if (plot.ps[i].make_Model == nullptr) {
				parkCar(plot.ps[i]);
				return i;
			}
		}
		return -1;
	}

	bool returnCar(ParkingLot& recall, int spotNo) {

		if (spotNo >= 0 && spotNo < recall.noOfParkingSpot) {
			if (!isEmpty(recall.ps[spotNo])) {
				cout << "Returning ";
				print(recall.ps[spotNo]);
				freeSpot(recall.ps[spotNo]);
				return true;
			}
		}
		return false;
	}

	void closeParking(ParkingLot& plot) {

		for (int i = 0; i < plot.noOfParkingSpot; i++) {
			if (!isEmpty(plot.ps[i])) {
				returnCar(plot, i);
			}
		}

		delete[] plot.ps;
		setEmpty(plot);

	}
}

