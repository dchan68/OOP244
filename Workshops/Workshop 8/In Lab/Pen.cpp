// Pen.cpp
//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include "Pen.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds{

	Pen::Pen(){
		safeEmptystate();
	}

	Pen::~Pen(){
		delete[] pen_style;
	}

	void Pen::safeEmptystate(){
		pen_ink = 0;
		pen_style = nullptr;
	}

	Pen::Pen(const char* newStyle, int newInk){
		if (newStyle == nullptr || newStyle[0] == '\0'){
			safeEmptystate();
		}
		else{
			pen_style = new char[strlen(newStyle) + 1];
			strcpy(pen_style, newStyle);

			if (newInk < 1 || newInk > 50){
				newInk = INK_MAX;
			}
			pen_ink = newInk;
		}
	}

    void Pen::write(const char* write){
		int text_length = strlen(write);
		if (pen_ink == 0){
			cout << "We can't write without ink!" << endl;
		}
		else {
			cout << "Writing out the following: " << write << " with a Pen!" << endl;

			for (int i = 0; i < text_length; ++i){
				if (write[i] != ' '){
					pen_ink -= 2;
					if (pen_ink < 0){
						pen_ink = 0;
					}
				}
			}
		}
	}

	void Pen::refill(int fillup){
		cout << "Refilling the pen with ink" << endl;

		if (fillup > INK_MAX){
			fillup = INK_MAX;
		}

		pen_ink += fillup;
	}

	bool Pen::filled() const{
		return pen_ink != 0;
	}

	std::ostream& Pen::display(std::ostream& os) const{
		if (pen_style == nullptr || pen_style[0] == '\0'){
			cout << "This is an empty Pen" << endl;
		}
		else {
			cout << "Pen Details" << endl;
			cout << "Style: " << pen_style << endl;
			cout << "Ink Remaining: " << pen_ink << endl;
		}
		return os;	
	}
}