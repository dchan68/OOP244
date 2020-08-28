//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Magazine.h"

using namespace std;
namespace sdds{
	Magazine::Magazine() : PubRecord(), volume(0), Issue_no(0) {
	}
	
	Magazine::Magazine(const Magazine& mag) : PubRecord(mag){
		this->volume = mag.volume;
		this->Issue_no = mag.Issue_no;
	}

	Magazine& Magazine::operator=(const Magazine& mag){
		PubRecord::operator=(mag);
		this->volume = mag.volume;
		this->Issue_no = mag.Issue_no;
		return *this;
	}

	char Magazine::recID() const{
		return 'M';
	}

	void Magazine::checkIn(){
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	void Magazine::checkOut(){
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	istream& Magazine::read(istream& is){
		if (mediaType() == SDDS_CONSOLE) {
			char magName[41];  
			cout << "Magazine Name: ";
			readS(magName, 40, "Magazine name too long, Enter nagain: ", is);
			PubRecord::name(magName);
			cout << "Volume: ";
			readInt(volume, 1, 99, "Invalid Volume number, Enter again: ", is);  
			cout << "Issue: ";
			readInt(Issue_no, 1, 99, "Invalid Issue number, Enter again: ", is); 
			cout << "Shelf Number: "; 
			PubRecord::readShelfNo();  
		}
		else if(mediaType() == SDDS_FILE){
			char magazine_name[41];
			int tempShelfNo;
			is.getline(magazine_name, 40, '\t');
			PubRecord::name(magazine_name);
			is >> volume;
			is >> Issue_no;
			is >> tempShelfNo;
			PubRecord::shelfNo(tempShelfNo);
			is.ignore();
		}
		else{
			cout << "You have to set the media type first!" << endl;
		}
		return is;
	}

	ostream& Magazine::write(ostream& os) const{	
		if (mediaType() == SDDS_CONSOLE)
		{
			os << setw(41) << setfill(' ') << left << name();   
			printChar(7, " ", os);								
			os.setf(ios::right);
			os << setw(2) << setfill('0') << volume << "(" << setw(2) << setfill('0') << Issue_no << ")";														 						  			
			os << ' ' << ' ';  
			os << shelfNo();                                    
		}
		else if (mediaType() == SDDS_FILE){
			os << recID() << name() << '\t' << volume << '\t' << Issue_no << '\t' << PubRecord::shelfNo() << endl;
		}
		else {
			os << "You have to set the media type first!" << endl;
		}
		return os;
	}
}