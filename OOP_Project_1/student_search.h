#pragma once
#include<iostream>
#include<vector>
#include <iomanip>
#include "student.h"
using namespace std;

void students_search(vector<Student> v) {

	string line;

	string menu_msg = "\n- Search -\n"
		"1. Search by name\n"
		"2. Search by student ID (10 numbers)\n"
		"3. Search by admission year (4 numbers)\n"
		"4. Search by department name\n"
		"5. List All\n\n";
	cout << menu_msg << ">";

	int select_menu;
	cin >> select_menu;
	cin.ignore();


	string keyword = "";
	if (!v.empty()) {
		switch (select_menu) {
		case 1:
			cout << "Name keyword? ";
			getline(cin,keyword);
			printf("\n%-22s%-11s%-25s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if ((v.at(i)).getName() == keyword)
					v.at(i).printInfo();
			}
			break;
		case 2:
			cout << "student ID keyword? ";
			getline(cin, keyword);
			printf("\n%-22s%-11s%-25s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if ((v.at(i)).getID() == keyword)
					v.at(i).printInfo();
			}
			break;
		case 3:
			cout << "admission year keyword? ";
			getline(cin, keyword);
			printf("\n%-22s%-11s%-25s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if (v.at(i).getID().substr(0, 4) == keyword)
					v.at(i).printInfo();
			}
			break;
		case 4:
			cout << "Department name keyword? ";
			getline(cin, keyword);
			printf("\n%-22s%-11s%-25s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if ((v.at(i)).getDept() == keyword)
					v.at(i).printInfo();
			}
			break;
		case 5:
			printf("\n%-22s%-11s%-25s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			if (!v.empty()) {
				for (int i = 0; i < v.size(); i++) {
					v.at(i).printInfo();
				}
			}
			break;
		default:break;
		}

		cout << endl << endl;
	}



}


