//Ore.cpp
//Name: Daryan Chan
//ID: 113973192
//Section: NCC

#define _CRT_SECURE_NO_WARNINGS

#include "Ore.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

namespace sdds{

	Ore::Ore() : weight(EMPTY_WEIGHT), purity(EMPTY_PURITY){
		strcpy(classification, "");
	}

	Ore::Ore(double newWeight, int newPurity, const char* newClassification){
		if (newWeight < 1){
			weight = DEFAULT_WEIGHT;
		}
		else {
			weight = newWeight;
		}

		if (newPurity < 1 || newPurity > 100){
			purity = DEFAULT_PURITY;
		}
		else {
			purity = newPurity;
		}

		if (strlen(newClassification) > CLASS_LEN){
			strncpy(classification, newClassification, CLASS_LEN);
		}

		else {
			strncpy(classification, newClassification, strlen(newClassification) + 1);
		}
	}

	// Refine function
	bool Ore::refine(){

		bool successful = false;

		if (purity > 100){
			cout << "Can no longer be refined" << endl;
			purity = 100;
		}
		else {
			weight -= 20;
			purity += 10;
			successful = true;
		}
		return successful;
	}

	ostream& Ore::display(ostream& os) const{
		if (classification[0] == '\0'){
			os << "This ore is imaginary" << endl;
		}
		else {
			os << "Weight: " << fixed << setprecision(2) << weight << endl; // print until 2 decimal points
			os << "Purity: " << purity << endl;
			os << "Classification: " << classification << endl;
		}
		return os;
	}

	ostream& operator<<(ostream& os, const Ore& ore){
		os << "Ore" << endl;
		ore.display(os);
		return os;
	}

	istream& Ore::input(istream& is){
		double temp_weight = 0.0;
		int temp_purity = 0;
		char temp_classification[CLASS_LEN + 1];
		strcpy(temp_classification, "");

		cout << "Enter a value for this ore's weight: ";
		is >> temp_weight;

		cout << "Enter a value for this ore's purity: ";
		is >> temp_purity;

		// clear the buffer
		is.clear();
		is.ignore(2000, '\n');

		cout << "Enter a classification for the ore (MAX 30 chars): ";
		is.getline(temp_classification, CLASS_LEN);

		Ore temp(temp_weight, temp_purity, temp_classification);

		weight = temp.weight;
		purity = temp.purity;
		strcpy(classification, temp.classification);
		return is;
	}

	istream& operator>>(istream& is, Ore& ore){
		ore.input(is);
		return is;
	}
}
