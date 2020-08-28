/***********************************************************************
// OOP244 Project Milestone 4
// File	library.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019/12/01      intial release
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "PubApp.h"
int main(void) {
	sdds::PubApp library("libdatat.dat");
	return library.run();
}