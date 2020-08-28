//DIY workshop 3
//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca

#ifndef SDDS_MARK_H
#define SDDS_MARK_H

#include <iostream>

namespace sdds {

	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;
	const int DSP_GPA = 4;
	const int DSP_LETTER = 5;

	class Mark {
		char m_name[51];
		int m_displayMode;
		double m_mark;
		int m_outOf;
		void flushkeyboard()const;
		void prnLetter()const;

	public:
		void set(int displayMode);
		void set(double mark, int outof = 1);
		void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		std::ostream& display(int width = 55)const;
		void set(const char* name);
		void set(const char* name, double rawMark, int outof = 1);
		bool readName(const char* prompt, int maxLen = 50);
		void changeOutOf(int value);
		double GPA()const;
		double letterBasedGPA()const;
	};
}
#endif