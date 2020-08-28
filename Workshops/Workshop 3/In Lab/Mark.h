//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca
#ifndef SDDS_MARK_H
#define SDDS_MARK_H  
#include <iostream>

using namespace std;
namespace sdds
{
	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;

	class Mark{
		int m_displayMode;
		double m_mark;
		int m_outOf;
		void flushkeyboard()const;
		

	public:
		void set(int displayMode);
		void set(double mark, int outOf = 1);
		void setEmpty();
		bool isEmpty() const;
		int percent() const;
		double rawValue() const;
		bool read(const char* prompt);
		ostream& display() const;
	};
}
#endif
