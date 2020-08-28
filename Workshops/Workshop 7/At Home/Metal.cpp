//Metal.cpp
//Name: Daryan Chan
//ID: 113973192
//Section: NCC


#define _CRT_SECURE_NO_WARNINGS

#include "Metal.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds{

	Metal::Metal(){
		Ore();
		mohs = EMPTY_MOHS;
		name = nullptr;
	}

	Metal::~Metal(){
		delete[] name;
	}

	Metal::Metal(double weight, int purity, const char* classification, const char* newName, double newMohs) : Ore(weight, purity, classification){
		if (newName == nullptr || newName[0] == '\0'){
			mohs = EMPTY_MOHS;
			name = nullptr;
		}

		else {
			if (strlen(newName) > NAME_LEN){
				name = new char[NAME_LEN];
				strncpy(name, newName, NAME_LEN);
			}
			else {
				name = new char[strlen(newName) + 1];
				strncpy(name, newName, strlen(newName) + 1);
			}

			if (newMohs > 0){
				mohs = newMohs;
			}
			else {
				mohs = DEFAULT_MOHS;
			}
		}
	}

	bool Metal::isEmpty() const{
		return name == nullptr;
	}

	void Metal::refine(){
		if (Ore::refine() == true){
			mohs += 1;
		}
	}

	std::ostream& Metal::display(std::ostream& os) const{
		if (isEmpty()){
			os << "This metal is imaginary" << endl;
		}
		else {
			os << "Name: " << name << endl;
			Ore::display(os);
			os << "Mohs: " << mohs << endl;
		}
		return os;
	}

	ostream& operator<<(ostream& os, const Metal& met){
		os << "Metal" << endl;
		met.display(os);
		return os;
	}

	istream& Metal::input(istream& is){		
		// prevent memory leak with dynamic allocation
		if (name != nullptr){
			delete[] name;
			name = nullptr;
		}

		char temp[NAME_LEN + 1]; 
		strcpy(temp, "");
		double temp_mohs = EMPTY_MOHS;

		cout << "Enter a value for this metal's name: ";

		is.getline(temp, NAME_LEN);

		name = new char[strlen(temp) + 1];
		strcpy(name, temp);

		cout << "Enter a value for this metal's mohs: ";

		is >> temp_mohs;

		is.clear();
		is.ignore(2000, '\n');

		if (temp_mohs > 0){
			mohs=DEFAULT_MOHS;
		}

		mohs = temp_mohs;

		Ore::input(is);
		return is;
	}

	istream& operator>>(istream& is, Metal& met){
		met.input(is);
		return is;
	}

}