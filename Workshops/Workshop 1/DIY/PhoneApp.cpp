//Name: Daryan Chan     Username: dchan68

//Is the main function. It calls on other functions

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio> 
#include <cstring>
#include "Contact.h"
#include "Tools.h"
#include "File.h"
#include "PhoneDir.h"

using namespace std;
using namespace sdds;

//it was told that main function belongs in PhoneApp
int main() {
	phoneDir("SDDS Phone Directory", "phones.txt");
	return 0;
}