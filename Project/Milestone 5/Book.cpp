//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds
{
	Book::Book() : PubRecord(), ISBN_no(0), borrower_id(0){
	}

	Book::Book(const Book& book) : PubRecord(book){
		this->ISBN_no = book.ISBN_no;
		this->borrower_id = 0;
	}

	Book& Book::operator=(const Book& src){
		if (this != &src){
			PubRecord::operator=(src);
			this->ISBN_no = src.ISBN_no;
			this->borrower_id = 0;
		}
		return *this;
	}
	char Book::recID() const{
		return 'B';
	}

	int Book::memberId() const{
		return borrower_id;    
	}

	void Book::checkIn(){
		borrower_id = 0;
		cout << name() << " checked in!" << endl;
	}

	void Book::checkOut(){
		Date temp;   
		bool valid;
		cout << "Enter Member id: ";
		borrower_id = readInt(10000, 99999, "Invalid Member ID, Enter again: ");  
		do {
			valid = true;
			cout << "Enter return date: "; 
			due_date.read();     
			if (due_date - temp < 0)  {
				cout << "Please enter a future date." << endl;
				flushKeyboard();
				valid = false;
			}
			else if (due_date - temp > 30)  {
				cout << "The return date must be earlier than 30 days away from today." << endl;
				flushKeyboard();
				valid = false;
			}
		} while (!valid);
	}

	istream& Book::read(istream& is){
		if (mediaType() == SDDS_CONSOLE){
			char book_name[41];   
			borrower_id = 0;
			cout << "Book Name: ";
			readS(book_name, 40, "Book name too long, Enter again: ", is);
			this->name(book_name);     
			cout << "ISBN: ";
			readLNum(ISBN_no, 1000000000000, 9999999999999, "Invalid ISBN, Enter again: "); 
			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE){
			char book_name[41];
			int temp_shelf;
			is.getline(book_name, 40, '\t');
			this->name(book_name);
			is >> ISBN_no;
			is >> temp_shelf;
			shelfNo(temp_shelf);
			is >> borrower_id;
			if (borrower_id == 0){
				is.ignore();
				is >> borrower_id;
			}
			else{
				is.ignore();
				is >> due_date;
			}
			is.ignore();
		}
		else {
			cout << "You have to set the media type first!" << endl;
		}
		return is;
	}

	ostream& Book::write(ostream& os) const	{
		if (mediaType() == SDDS_CONSOLE){
			os << setw(41) << setfill(' ') << left << name(); 
			os << ISBN_no;									   
			printChar(2, " ", os); // Print 2 spaces 
			os << shelfNo();								   
			if (borrower_id != 0){
				os << ' ' << borrower_id;					   
				printChar(3, " ", os);						
				os << due_date;								  
			}
		}
		else if (mediaType() == SDDS_FILE){
			os << recID() << name() << '\t' << ISBN_no << '\t' << shelfNo() << '\t' << borrower_id;
			if (borrower_id != 0){
				os << '\t' << due_date;
			}
			os << endl;
		}
		else {
			os << "You have to set the media type first!" << endl;
		}
		return os;
	}
}