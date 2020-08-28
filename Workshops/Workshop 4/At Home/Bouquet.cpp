
//at_home Workshop 4
//Name:Daryan Chan
//Section NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include "Bouquet.h"
#include "utils.h"
#include "Flower.h"
#include <iomanip>
#include <iostream>
#include <cstring>


using namespace std;
namespace sdds
{
	void Bouquet::flushKeyboard() const
	{
		char ch;
		do {
			ch = cin.get();
		} while (ch != '\n'); 

	}

	Bouquet::Bouquet(){
		setEmpty();
	}

	Bouquet::Bouquet(const Flower* flowers, int noOfFlowers, const char* message){

		double price = 0.00;

		if (flowers == nullptr) 
			setEmpty();
		else{
			if (noOfFlowers < MAX_FLOWERS){
				b_flowerCount = noOfFlowers;
			}
			else {
				b_flowerCount = MAX_FLOWERS;
			}
			b_flowers = new Flower[b_flowerCount];
			
			for (int i = 0; i < b_flowerCount; i++){
				b_flowers[i].setName(flowers[i].name(), strlen(flowers[i].name()));
				b_flowers[i].setColour(flowers[i].colour(), strlen(flowers[i].colour()));
				b_flowers[i].setPrice(flowers[i].price());
				price += b_flowers[i].price();
			}

			b_price = price;
			b_message = new char[strlen(message) + 1];
			strcpy(b_message, message);
		}
	}

	Bouquet::~Bouquet(){
		if (isEmpty())
			cout << "An unknown bouquet has departed..." << endl;
		else
			cout << "A bouquet has departed with the following flowers..." << endl;
		delete[] b_flowers;
	}

	const char* Bouquet::message() const{
		return b_message;
	}

	double Bouquet::price() const{
		return b_price;
	}

	bool Bouquet:: isEmpty()const{
		if (b_price == 0 && b_message == nullptr && b_flowers == nullptr && b_flowerCount == 0)
			return true;
		else
			return false;
	}

	void Bouquet::setEmpty(){

		b_price = 0;
		b_message=nullptr;
		b_flowers = nullptr;
		b_flowerCount = 0;

	}

	void Bouquet::setMessage(const char* prompt) { 
		cout << prompt;
		char message[MESS_MAX_LEN];
		read(message, MESS_MAX_LEN+1, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");
		b_message = new char[strlen(message) + 1];
		strcpy(b_message, message);
	}

	void Bouquet::discardBouquet() {
		
		cout << "Discarding the current bouquet..." << endl;
		delete[] b_flowers;
		delete[] b_message;			
		setEmpty();
	}

	void Bouquet::arrangeBouquet(){ //this function was taken from Nisham Bohora ID 154469183

		bool data = false;
		char option;
		int validOption;
		double price = 0;
		cout <<"Arranging a new bouquet..." << endl;
		if (!isEmpty()){
			cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
			do {
				option=cin.get();
				if (option == 'Y' || option == 'N'){
					data= true;
					flushKeyboard();
				}
			} while (!data && cout << "The decision is either Y or N... Try again : ");
			if (option == 'Y')
				discardBouquet();
			else if (option == 'N')
				cout << "No new arrangement performed..." << endl;
		}

		if (isEmpty() || option ==  'Y'){
			bool ok = false;
			cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";
			do {
				cin >> validOption;
				if (validOption == 1 || validOption == 2 || validOption == 3)
					ok = true;
			}while(!ok && cout << "The valid range is 1-3... Try again: ");

			b_flowerCount = validOption;
			b_flowers = new Flower[b_flowerCount];
			for (int i = 0; i < b_flowerCount; i++){
				flushKeyboard();
				b_flowers[i].setFlower();
				price += b_flowers[i].price();
			}

			flushKeyboard();
			b_price = price;
			
			cout << "A bouquet has been arranged..." << endl;
			setMessage("Enter a message to send with the bouquet...: ");
		}
	}

	ostream& Bouquet::display() const{
		if (isEmpty()) 
			cout << "This is an empty bouquet..." << endl;
		else{
			cout << "This bouquet worth " << b_price << " " << fixed << setprecision(3) << "has the following flowers..." << endl;

			for (int i = 0; i < b_flowerCount; i++)
				cout << "Flower: " << b_flowers[i].colour() << " " << b_flowers[i].name() << " " << "Price: " << fixed << setprecision(2) << b_flowers[i].price() << endl;
		
			cout << "with a message of: " << b_message << endl;
		}
        return cout;
	}
}