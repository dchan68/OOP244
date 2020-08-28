//Name: Daryan Chan
//ID: 113973192
//Section 

#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H
#include "ReadWriteable.h"
#include "Date.h"

namespace sdds {
		const int SDDS_FILE = 0;
		const int SDDS_CONSOLE = 1;

	class PubRecord : public ReadWriteable {
		char* publicationName;
		int shelfNum;
		int m_mediaType;

	protected:
		const char* name() const;
		void name(const char* name);

	public:
		virtual char recID() const = 0;
		PubRecord();
		PubRecord(const PubRecord& copy);
		virtual ~PubRecord();
		PubRecord& operator=(const PubRecord& copy);
		void mediaType(int type);
		int mediaType() const;
		int shelfNo() const;
		void readShelfNo();
		bool operator==(const char match);
		bool operator==(const char* cString);
		operator bool() const;
		void readNum(int& val, int min, int max, const char* errorMess); // used in the readShelfNo function
	};
}
#endif
