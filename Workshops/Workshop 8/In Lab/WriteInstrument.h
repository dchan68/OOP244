// WriteInstrument.h
//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_WRITEINSTRUMENT_H
#define SDDS_WRITEINSTRUMENT_H

#include <iostream>

namespace sdds{
	class WriteInstrument {
		
	public:
		virtual ~WriteInstrument() {};
		virtual void write(const char* write) = 0;
		virtual void refill(int refill) = 0;
		virtual bool filled() const = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;
	};
}
#endif