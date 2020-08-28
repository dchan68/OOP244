//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"


namespace sdds
{

	void Mark::flushkeyboard() const {
		while (cin.get() != '\n');
	}
	void Mark::set(int displayMode) {
		m_displayMode = displayMode;
	}

	void Mark::set(double mark, int outOf) {
		m_mark = mark;
		m_outOf = outOf;
	}

	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
	}

	bool Mark::isEmpty()const {
		return  m_mark == -1; //set empty space to negative one since marks can never be empty. TA's advice.
	}

	int Mark::percent() const {
		double a;
		a = ((m_mark / m_outOf) * 100) + 0.5;
		return a;
	}

	double Mark::rawValue() const {
		double a;
		a = m_mark / m_outOf;
		return a;
	}

	bool Mark::read(const char* prompt) {
		bool ok;
		double a;
		int b;
		cout << prompt;
		cin >> a;
		cin.ignore();  //ignores the next character and Only the next character. 
		cin >> b;
		if (cin.fail()) {
			ok = false;
			cin.clear();
			setEmpty();
		}
		else {
			m_outOf = b;
			m_mark = a;
			ok = true;
		}
		cin.ignore(1000, '\n');
		return ok;
	}

	ostream& Mark::display() const
	{
		if (!isEmpty()) {
			switch (m_displayMode)
			{
			case (DSP_RAW):
				cout << rawValue();
				break;
			case (DSP_PERCENT):
				cout << "%" << percent();
				break;
			case (DSP_ASIS):
				cout << m_mark << "/" << m_outOf;
				break;
			case (DSP_UNDEFINED):
				cout << "Display mode not set!";
				break;
			default:
				cout << "Invalid Mark Display setting!";
				break;
			}
		}
		else {
			cout << "Empty Mark object!";
		}
		return cout;
	}
}