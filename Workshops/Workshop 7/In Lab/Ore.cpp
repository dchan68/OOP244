// Ore.cpp
//Name: Daryan Chan
//ID 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Ore.h"

using namespace std;
namespace sdds {
	Ore::Ore() {
		weight = 0.00;
		purity = 0;
		classification[0] = '\0';
	}

	Ore::Ore(double weight_, int purity_, const char* classification_) {
		if (weight_ < 1) {
			weight = DEFAULT_WEIGHT;
		}
		else {
			weight = weight_;
		}
		if (purity_ <1 || purity_ > 100) {

			purity = DEFAULT_PURITY;
		}
		else {
			purity = purity_;
		}
		strncpy(classification, classification_, CLASS_LEN);
		//classification[CLASS_LEN] = 0;
		int len = strlen(classification_) > CLASS_LEN ? CLASS_LEN : strlen(classification_);
		classification[len] = '\0';
	}

	Ore::~Ore() {

	}

	bool Ore::refine() {
		bool success = false;

		if (purity >= 100) {
			cout << "Can no longer be refined" << endl;
		}
		else {
			weight -= 20;
			purity += 10;
			if (purity > 100) {
				purity = 100;
			
			}
			success = true;
		}
		return success;
	}

	ostream& Ore::display(ostream& os)const {
		if (classification[0]=='\0' ) {//&& purity ==0 && weight == 0.00
			os << "This ore is imaginary" << endl;
		}
		else {
			os.setf(ios::fixed); 
			os.precision(2);
			os << "Weight: "<< weight << endl;
			os << "Purity: " << purity << endl;
			os << "Classification: " << classification << endl;
		}
		return os;
	}

	istream& Ore::input(istream& is) {
		double newWeight;
		int newPurity;
		char newClassification[CLASS_LEN+1];
		cout << "Enter a value for this ore's weight: ";
		is >> newWeight;
		cout << "Enter a value for this ore's purity: ";
		is >> newPurity;
		is.ignore();
		cout << "Enter a classification for the ore (MAX 30 chars): ";
		is.getline(newClassification, CLASS_LEN);

		Ore temp(newWeight, newPurity, newClassification);  //this line was added on the advice of the TA
		*this = temp;

		return is;
	}

	ostream& operator <<(ostream& os, const Ore& ore) {

		os << "Ore" << endl;
		ore.display(os);
		return os;
	}

	istream& operator >>(istream& is, Ore& ore) {
		ore.input(is);
		return is;
	}
}
