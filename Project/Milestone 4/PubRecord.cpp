//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "PubRecord.h"

using namespace std;
namespace sdds{
	PubRecord::PubRecord(): pubName(nullptr), shelfNum(0), m_mediaType(SDDS_CONSOLE){
	}

	PubRecord::~PubRecord(){
		delete[] pubName;
		pubName = nullptr;
	}

	void PubRecord::name(const char* p_name){
		delete[] pubName;
		if (p_name != nullptr){
			pubName = new char[strlen(p_name) + 1];
			strcpy(pubName, p_name);
		}
		else {
			pubName = nullptr;
		}
	}

	const char* PubRecord::name() const{
		return pubName;
	}

	void PubRecord::shelfNo(int value){
		shelfNum = value;
	}

	PubRecord::PubRecord(const PubRecord& src): pubName(nullptr){
		if (src.pubName != nullptr) {
			name(src.pubName);
		}
		shelfNum = src.shelfNum;
		m_mediaType = src.m_mediaType;
	}
	
	PubRecord& PubRecord::operator=(const PubRecord& src){
		if (this != &src) {
			if (src.pubName != nullptr) {
				name(src.pubName);
			}
			else
				name(nullptr);
			shelfNum = src.shelfNum;
			m_mediaType = src.m_mediaType;
		}
		return *this;
	}

	void PubRecord::mediaType(int m_type){
		m_mediaType = m_type;
	}

	int PubRecord::mediaType() const{
		return m_mediaType;
	}

	int PubRecord::shelfNo() const{
		return shelfNum;
	}

	void PubRecord::readShelfNo(){
		shelfNum = readInt(100, 999, "Invalid Shelf Number, Enter again: ");
	}

	bool PubRecord::operator==(char rec_id) const{
		return recID() == rec_id;        
	}

	bool PubRecord::operator==(const char* pub_name_cmp) const{
		return strstr(pubName, pub_name_cmp);
	}

	PubRecord::operator bool() const{
		return pubName != nullptr;
	}
}