// Pencil.cpp
//Name: Daryan Chan
//ID: 113973192
//Section NCC

#define _CRT_SECURE_NO_WARNINGS

#include "Pencil.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds{

	Pencil::Pencil(){
		safeEmptyState();
	}

	void Pencil::safeEmptyState(){
		graphite = 0;
		strcpy(HB_scale, "");
	}
	
	Pencil::Pencil(const char* hb_scale, int newGraphite){
		if(hb_scale==nullptr||hb_scale[0]=='\0'){
			safeEmptyState();
	    }
		else {
			strncpy(HB_scale, hb_scale, HB_MAX);
			HB_scale[HB_MAX] = '\0';

			if (newGraphite < 1 || newGraphite > 100){
				newGraphite = GRAPHITE_MAX;
			}
			graphite = newGraphite;
		}
	}

	void Pencil::write(const char* write){
		int text_length = strlen(write);
		if (graphite == 0){
			cout << "We can't write without graphite!" << endl;
		}
		else{
			cout << "Writing out the following: " << write << " with a Pencil!" << endl; 
			for (int i = 0; i < text_length; ++i){
				if (write[i] == ' '){
					graphite -= 5;
					if (graphite < 0){
						graphite = 0;
					}
				}
			}
		}	
	}


	void Pencil:: refill(int fillup){
		cout << "Refilling the pencil with graphite" << endl;
		graphite += fillup;
		if (graphite > GRAPHITE_MAX){
			graphite = GRAPHITE_MAX;
		}
	}

	bool Pencil:: filled() const{
		return graphite > 0;
	}

	std::ostream& Pencil::display(std::ostream& os) const{
		if (HB_scale[0]=='\0'){
			os << "This is an empty Pencil" << endl;
		}
		else {
			os << "Pencil Details" << endl;
			os << "HB Value: "<<HB_scale << endl;
			os << "Graphite Remaining: " << graphite<< endl;
		}
		return os;
    }
}
