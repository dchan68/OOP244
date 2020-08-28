// Robot.cpp
//Name: Daryan Chan
//ID: 113973192
//Section: NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include "Robot.h"
#include "Parts.h"
#include <cstring>

using namespace std;
namespace sdds {
	Robot::Robot() {
		nickname[0] = '\0';
		durability = 0;
	}

	Robot::Robot(const char* nick_name, int arms_force, int legs_force, int durability_robot) {
		if (nick_name == nullptr || nick_name[0] == '\0') {
			nickname[0] = '\0';
			durability = 0;
		}
		else {
			if (strlen(nick_name) > NICK_MAX_LEN) {
				strncpy(nickname, nick_name, NICK_MAX_LEN + 1);
			}
			else {
				strcpy(nickname, nick_name);
			}
			if (durability_robot < 1) {
				durability = 100;
			}
			else {
				durability = durability_robot;
			}
			arms = arms_force;
			legs = legs_force;
		}
	}
	Robot::~Robot() {
	}
	ostream& Robot::display() const {
		if (nickname == '\0' || durability == 0) {
			cout << "This Robot isn't operational" << endl;
		}
		else {

			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
			cout << "Legs: " << legs.getSpeed() << endl;
		}
		return cout;
	}

	Robot::operator bool() const {
		return nickname == nullptr || durability == 0;
	}

	Arms Robot::getArms() const{
		return arms;
	}

	Legs Robot::getLegs() const{
		return legs;
	}

	Robot& Robot:: operator -=(int val){
		durability = durability - val;

		if (durability < 1){
			durability = 0;
		}
		return *this;
	}

	void box(Robot& robot1, Robot& robot2)  {

		cout << "Attempting to begin a Robot boxing match" << endl;

		if (robot1 || robot2){
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
		}
		else{
			cout << "Both participants are operational... beginning the bout" << endl;
			while (!robot1 && !robot2){
				if (robot1.getLegs().getSpeed() > robot2.getLegs().getSpeed()){
					robot2 -= robot1.getArms().getForce();
					if (!robot2){
						robot1 -= robot2.getArms().getForce();
					}
				}
				else{
					robot1 -= robot2.getArms().getForce();
					if (!robot1){
						robot2 -= robot1.getArms().getForce();
					}
				}
			}
			if (!robot1){
				cout << "The bout has concluded... the winner is: " << endl;
				robot1.display();
			}
			else if (!robot2){
				cout << "The bout has concluded... the winner is: " << endl;
				robot2.display();
			}
			else{
				cout << "No bout will begin" << endl;
			}
		}
	}
}
