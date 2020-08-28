//Name: Daryan Chan
//ID: 113973192
//Section NCC

#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H
#include <iostream>
#include "ReadWriteable.h"
#include "Utils.h"
#include "Date.h"

namespace sdds{
	const int SDDS_CONSOLE = 555;
	const int SDDS_FILE = 666;

	class PubRecord : public ReadWriteable{
	private:
		char* pubName;      
		int shelfNum;		
		int m_mediaType;		  

	protected:
		void name(const char* p_name);        
		const char* name() const;			 
		void shelfNo(int value);					
	public:
		PubRecord();
		virtual~PubRecord();                        
		PubRecord(const PubRecord&);           
		PubRecord& operator=(const PubRecord&); 
		void mediaType(int m_type); 
		int mediaType()const;		
		int shelfNo() const;        
		void readShelfNo();
		bool operator==(char)const;     
		bool operator==(const char*) const;
		virtual char recID() const = 0;        
		operator bool()const;                  

		//Milestone 4
		virtual void checkIn() = 0; 
		virtual void checkOut() = 0;
	};
}
#endif