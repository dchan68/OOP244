//DIY workshop 3
//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Mark.h"


using namespace std;
namespace sdds {
	void Mark::flushkeyboard()const{
		while (cin.get() != '\n');
	}

	void Mark::prnLetter()const {
		if (!isEmpty()) {
			if (percent() >= 0 && percent() <= 49)
				cout << "F";
			else if (percent() >= 50 && percent() <= 54)
				cout << "D";
			else if (percent() >= 55 && percent() <= 59)
				cout << "D+";
			else if (percent() >= 60 && percent() <= 64)
				cout << "C";
			else if (percent() >= 65 && percent() <= 69)
				cout << "C+";
			else if (percent() >= 70 && percent() <= 74)
				cout << "B";
			else if (percent() >= 75 && percent() <= 79)
				cout << "B+";
			else if (percent() >= 80 && percent() <= 89)
				cout << "A";
			else if (percent() >= 90 && percent() <= 100)
				cout << "A+";
			else if (percent() > 100)
				cout << "?";
		}
	}

	void Mark::set(int displayMode){
		m_displayMode = displayMode;
	}

	void Mark::set(double mark, int outof) {
		m_mark = mark;
		m_outOf = outof;
	}

	void Mark::setEmpty(){
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
		strcpy(m_name, "");
	}

	bool Mark::isEmpty()const{
		return  m_mark == -1; //set empty space to negative one since marks can never be empty. TA's advice.
	}

	int Mark::percent()const{
		double a;
		a = ((m_mark / m_outOf) * 100) + 0.5;
		return a;
	}

	double Mark::rawValue()const {
		double a;
		a = m_mark / m_outOf;
		return a;
	}

	bool Mark::read(const char* prompt) {
		bool success = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			success = false;

		}
		flushkeyboard();
		return success;
	}
	ostream& Mark::display(int width) const //function to print in format as output required output
	{
		cout.setf(ios::fixed);
		if (isEmpty())
		{
			cout << "Empty Mark object!";
		}
		else {
			if (m_name[0] != '\0') {
				cout.fill('.');
				cout.width(width);
				cout.setf(ios::left);
				cout << m_name;
			}
			if (m_displayMode == DSP_RAW){
				cout.precision(2);
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT){
				cout << "%" << percent();
			}
			else if (m_displayMode == DSP_ASIS){
				cout.precision(1);
				cout << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_LETTER){
				prnLetter();
			}
			else if (m_displayMode == DSP_GPA) {
				cout.precision(1);
				cout << GPA();
			}
			else if (m_displayMode == DSP_UNDEFINED){
				cout << "Display mode not set";
			}
			else {
				cout << "Invalid Mark Display setting!";
			}
		}
		return cout;

	}
	//this copies the name into m_name
	void Mark::set(const char* name) {
		strncpy(m_name, name, 50);
	}

	//sets up the name and outOf
	void Mark::set(const char* name, double rawMark, int outof){ 
		set(name);
		set(rawMark, outof);
	}
	//Makes sures the char length is within the proper limits
	bool Mark::readName(const char* prompt, int maxLen) {
		bool pass = true;
		cout << prompt;
		cin.getline(m_name, maxLen + 1);
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			flushkeyboard();
			pass = false;
		}
		return pass;
	}
	// setting up empty state
	void Mark::changeOutOf(int value) {
		if (value < 1){
			value = 100;
		}
		m_mark = m_mark * ((double)value / m_outOf);
		m_outOf = value;
	}
	// return rawValue * 4
	double Mark::GPA()const{
		return rawValue() * 4;
	}

	double Mark::letterBasedGPA()const //Function defination for point based GPA
	{
		double gpa=0;
		if (percent() >= 0 && percent() <= 49) 
			gpa = 0.0;
		else if (percent() >= 50 && percent() <= 54) 
			gpa = 1.0;
		else if (percent() >= 55 && percent() <= 59) 
			gpa = 1.5;
		else if (percent() >= 60 && percent() <= 64) 
			gpa = 2.0;
		else if (percent() >= 65 && percent() <= 69) 
			gpa = 2.5;
		else if (percent() >= 70 && percent() <= 74) 
			gpa = 3.0;
		else if (percent() >= 75 && percent() <= 79) 
			gpa = 3.5;
		else if (percent() >= 80 && percent() <= 89) 
			gpa = 4.0;
		else if (percent() >= 90 && percent() <= 100) 
			gpa = 4.0;
		return gpa;
	}
}

