// RobotSquad.cpp
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "RobotSquad.h"

using namespace std;
namespace sdds
{
	RobotSquad::RobotSquad(const char* r_name) { 
		name = new char[11];
		strncpy(name, r_name, 10);
		name[10] = '\0';
		count = 0;
		Robots = nullptr;
	}

	RobotSquad::~RobotSquad(){
		delete[] name;
		delete[] Robots;
	}

	const char* RobotSquad::getName()const{
		return name;
	}

	int RobotSquad::getCount()const {
		return count;
	}

	Robot* RobotSquad::getRoster() const {
		return this->Robots;
	}
	ostream& RobotSquad::display() const {//Function defination to Display in order
		{
			if (count == 0)  // Checking empty state
			{
				cout << "Squad **" << name << "** has no members" << endl;
			}
			else
			{
				cout << "***Squad Summary***" << endl;
				cout << "Name: " << name << endl;
				cout << "Roster Count: " << count << endl;
				cout << "Roster:" << endl;
				for (int i = 0; i < count; i++)
				{
					Robots[i].display();
				}
			}
			return cout;
		}
	}

	RobotSquad& RobotSquad::operator+=(Robot& robots){
		Robot* temp = new Robot[count + 1];
		for (int i = 0; i < count; i++) {
			temp[i] = Robots[i];
		}

		count++;
		delete[] Robots;//delete current arrays
		Robots = temp;//change to point to temp
		Robots[count - 1] = robots;
		return *this;

	}
	RobotSquad& RobotSquad::operator--(){
		if (Robots == nullptr) {//checking empty state
			cout << "This squad **" << name << "** has no members or is uninitialized. Can't do --." << endl;
		}
		else
		{
			if (count == 0){
				Robots = nullptr; //safe empty space
			}
			else{
				Robot* temp = new Robot[count - 1];
				for (int i = 0; i < count - 1; i++){
					temp[i] = Robots[i];
				}
				delete[] Robots;
				Robots = temp;
				count--;
			}
		}
		return *this;
	}


}