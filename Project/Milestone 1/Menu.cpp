//Name: Daryan Chan
//ID: 113973192
//section NCC

#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include <cstring>

using namespace std;
namespace sdds {

	MenuItem::MenuItem() {
		m_description = nullptr;
	}

	MenuItem::MenuItem(const char* selection) {
		m_description = new char[strlen(selection) + 1];
		strcpy(m_description, selection);
	}

	MenuItem::~MenuItem() {
		delete[] m_description;
	}

	MenuItem::operator bool const() {
		return(m_description != nullptr && m_description[0] != '\0');
	}

	MenuItem::operator const char* () const{
		return m_description;
	}

	ostream& MenuItem::display(ostream & os)const {
		os << m_description << endl;
		return os;
	}

	Menu::Menu() :title(), item {nullptr}{
		num_pointers = 0;
	}

	Menu::Menu(const char* menu) : title(menu), item{nullptr}{
		num_pointers = 0;
	}

	Menu::~Menu() {
		for (int i = 0; i < num_pointers; i++) {
			delete item[i];
		}
	}

	Menu::operator bool const() {
		return(item[0] != nullptr);
	}

	Menu::operator unsigned int() {
		return num_pointers;
	}

	const char* Menu::operator[] (int num)const {
		while (num > num_pointers) {
			num -= num_pointers;
		}
		return item[num]->m_description;
	}

	int Menu::operator~() {
		return getSelection();
	}

	Menu& Menu::operator<<(const char* num) {
		if ((unsigned)num_pointers < MAX_MENU_ITEMS) {
			num_pointers++;
			item[num_pointers - 1] = new MenuItem(num);
		}
		return *this;
	}

	//display the menu and get the user input
	unsigned int Menu::getSelection() {
		int number;
		int success = 0;
		menuItems();

		do {
			cin >> number;
			if (cin.fail() || number > num_pointers || number < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
			}
			else {
				success = 1;
				cin.ignore(1000, '\n');
			}
		} while (success == 0);
		return number;
	}

	ostream& Menu::menuTitle(ostream& os) const {
		if (title.m_description != nullptr) {
			os << title.m_description;
		}
		return os;
	}

	ostream& Menu::menuItems(ostream& os) const {
		if (title.m_description != nullptr) {
			os << title.m_description << ':' << endl;
		}
		os.setf(ios::right);
		for (int i = 0; i < num_pointers; i++) {
			os.width(1);
			os << " " << i + 1 << "- "; item[i]->display();
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}

	ostream& operator<<(ostream& os, const Menu& menu) {
		menu.menuTitle(os);
		return os;
	}
}
