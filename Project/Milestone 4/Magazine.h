//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_MAGAZINE_H
#define SDDS_MAGAZINE_H
#include <iostream>
#include "PubRecord.h"

namespace sdds{
	class Magazine :public PubRecord{
		private:
			int volume;    
			int Issue_no;   
		public:
			Magazine();
			Magazine(const Magazine&);   
			Magazine& operator=(const Magazine&);
			char recID() const;
			void checkIn();
			void checkOut();
			std::istream& read(std::istream& is = std::cin);
			std::ostream& write(std::ostream& os = std::cout) const;
	};
}
#endif