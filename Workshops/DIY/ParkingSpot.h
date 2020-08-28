//DIY
//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email dchan68@myseneca.ca

#ifndef SDDS_PARKINGSPOT_H__
#define SDDS_PARKINGSPOT_H__

namespace sdds {
	struct ParkingSpot
	{
		char licensePlate[9];
		char* make_Model = nullptr;
	};

	void setEmpty(ParkingSpot&);

	bool isEmpty(const ParkingSpot&);

	void freeSpot(ParkingSpot&);

	void print(const ParkingSpot&);

	void parkCar(ParkingSpot&);

}

#endif