//DIY workshop 3
//Name: Daryan Chan
//ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca

#include "ReportUtils.h"

#include <iostream>

namespace sdds {
	std::ostream& line(int len, char ch)
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << ch;
		}

		return std::cout;
	}
}
