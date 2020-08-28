//in_lab Workshop 4
//Name:Daryan Chan
//Section NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Flower.h"
#include "utils.h"

using namespace std;
namespace sdds {
	Flower::Flower() {
		setEmpty();
	}

	Flower::Flower(const char* name, const char* colour, double price){
		if (name[0] != 0 && name != nullptr && colour != nullptr && colour[0] != 0 && price > 0){

			f_name = new char[strlen(name) + 1];
			f_colour = new char[strlen(colour) + 1];
			f_price = price;

			strcpy(f_name, name);
			strcpy(f_colour, colour);
		}
		else 
			setEmpty();	
	}

	const char* Flower::name() const {
		return f_name;
	}

	const char* Flower::colour() const {
		return f_colour;
	}

	double Flower::price() const {
		return f_price;
	}

	bool Flower::isEmpty() const {
		if (f_name == nullptr && f_colour == nullptr && f_price == 0) {
			return true;
		}
		else 
			return false;
	}

	void Flower::setEmpty() {
		f_name = nullptr;  //nullptr makes it points to nothing. Unlike NULL, where the string starts with a 0
		f_colour = nullptr;
		f_price = 0;
	}

	void Flower::setName(const char* prompt) {
		delete[] f_name;
		char flowerName[NAME_MAX_LEN + 1];
		cout << prompt;
		read(flowerName, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");
		f_name = new char[NAME_MAX_LEN + 1];
		strcpy(f_name, flowerName);
	}

	void Flower::setColour(const char* prompt) {
		delete[] f_colour;
		char flowerColour[COL_MAX_LEN + 1];
		cout << prompt;
		read(flowerColour, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");
		f_colour = new char[COL_MAX_LEN + 1];
		strcpy(f_colour, flowerColour);
	}

	void Flower::setPrice(const char* prompt) {
		cout << prompt;
		do 
			cin >> f_price;
		while (f_price <= 0 && cout << "A flower's price is a non-negative number... Try again: ");
	}

	void Flower::setFlower() {
		cout << "Beginning the birth of a new flower..." << endl;
		setName("Enter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");
		cout << "The flower's current details..." << endl;
		display();
	}

	std::ostream& Flower::display() const {
		if (isEmpty())
			cout << "This is an empty flower..." << endl;
		else
			cout << "Flower: " << colour() << " " << name() << " " << "Price: " << price() << endl;
		return cout;
	}

	Flower::~Flower() {
		if (!isEmpty()) 
			cout << colour() << " " << name() << " " << "has departed..." << endl;
		else {
			cout << "An unknown flower has departed..." << endl;
			delete[] f_colour;
			delete[] f_name;
		}
	}
}