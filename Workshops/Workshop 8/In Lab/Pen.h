// Pen.h
//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_PEN_H
#define SDDS_PEN_H

#include "WriteInstrument.h"

namespace sdds{
	const int INK_MAX =50;

	class Pen :public WriteInstrument{
		char* pen_style;
		int pen_ink;

	public:
		Pen();
		~Pen();
		void safeEmptystate();
		Pen(const char* style, int ink);
		void write(const char* write);
		void refill(int refill_ink);
		bool filled() const;
		std::ostream& display(std::ostream& os) const;
	};
}
#endif