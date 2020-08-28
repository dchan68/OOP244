//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "PubRecord.h"

namespace sdds{
	class Book : public PubRecord{
	private:
		unsigned long long ISBN_no;   
		int borrower_id;              
		Date due_date;				 		
	public:
		Book();
		Book(const Book& book);				
		Book& operator=(const Book& src);	
		int memberId() const;
		char recID() const;
		void checkIn();
		void checkOut();
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
	};
}
#endif
