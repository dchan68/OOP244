//DIY
//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email dchan68@myseneca.ca
#ifndef SDDS_PARKINGLOT_H__
#define SDDS_PARKINGLOT_H__
#include "ParkingSpot.h"

namespace sdds {
	struct ParkingLot
	{
		int noOfParkingSpot;
		ParkingSpot* ps;
	};

	void setEmpty(ParkingLot&);

	bool isEmpty(const ParkingLot&);

	void openParking(ParkingLot&, int noOfSpots);

	int parkCar(ParkingLot&);

	bool returnCar(ParkingLot&, int spotNo);

	void closeParking(ParkingLot&);

}
#endif
