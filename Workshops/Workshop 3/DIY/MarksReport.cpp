//DIY workshop 3
//Name: Daryan Chan
//Student ID: 113973192
//Section NCC
//Email: dchan68@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "MarksReport.h"
#include "ReportUtils.h"
#include "Mark.h"
using namespace std;
namespace sdds
{
	void flushkeyboard() {
		while (cin.get() != '\n');
	}
		
	void MarksReport::initialize(){
		strncpy(m_reportName, "", 70);
	}

	void MarksReport::getMarks(){		
		char name[70];
		cout << "Enter the report Name: ";
		cin.getline(name, 71); // 71 to include for null terminator
		

		if (cin.fail())	{
			cin.clear();
		}

		else {
			strncpy(m_reportName, name, 70);
		}

		cout << "Enter the number of marks: ";
		cin >> noOfmarks;
		
		m_markArray = new Mark[noOfmarks]; // dynamic memory allocation to adjust for data entered by user
		cout << "Please enter "<< noOfmarks <<" marks:"<< endl;

		flushkeyboard();

		for (int i = 0; i < noOfmarks; ++i){
			cout << i + 1;
			cout << ": ";
			m_markArray[i].readName("Subject Name: ", 6);
			m_markArray[i].read("Mark (mark/outof): ");			
		}
		cout << "Entry Completed!" << endl;
		cout << endl;
	}

	void MarksReport::print(){
		double result_gpa = 0;
		int lowest = 100;
		int highest = -1;
		
		//code below is the summary of the things entered into the system
		
			
		line(70, '-') << endl;
		cout << m_reportName << endl;
		line(70, '-') << endl;

		cout << "Marks entered:" << endl;
		
		for (int i = 0; i < noOfmarks; ++i){
			m_markArray[i].set(DSP_LETTER); 
			m_markArray[i].display(66) << endl;
			highest > m_markArray[i].percent() ? highest : highest = m_markArray[i].percent();
			lowest < m_markArray[i].percent() ? lowest : lowest = m_markArray[i].percent();	
		}

		line(70, '-') << endl;
		
		line(30, ' ');
		cout << "Lowest Mark";
		line(25, '.');
		cout << "%" << lowest << endl;

		line(30, ' ');
		cout << "Highest mark";
		line(24, '.');
		cout << "%" << highest << endl;

		line(30, ' ');
		cout << "GPA";
		line(33, '.');


		// Add up all of the GPAs and divide them by the number of marks given by the user
		for (int i = 0; i < noOfmarks; ++i){
			result_gpa += m_markArray[i].letterBasedGPA();
		}

		result_gpa = result_gpa / noOfmarks;
		
		cout << setprecision(1) << result_gpa << endl;
	}

	void MarksReport::terminate(){
		delete[] m_markArray;
	}



}