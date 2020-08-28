// Pencil.h
//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_PENCIL_H
#define SDDS_PENCIL_H

#include "WriteInstrument.h"

namespace sdds{
	const int HB_MAX = 2;
	const int GRAPHITE_MAX =100;

	class Pencil: public WriteInstrument{
		char HB_scale[HB_MAX+1];
		int graphite;

	public:
		Pencil();
		void safeEmptyState();
		Pencil(const char*,int);		
	    void write(const char*);
		void refill(int);
		bool filled() const;
		std::ostream& display(std::ostream& os) const;
	};


}
#endif