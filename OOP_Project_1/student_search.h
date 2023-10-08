#pragma once
#include<iostream>
#include<vector>
#include <iomanip>
#include "student.h"
using namespace std;


void students_search(vector<Student> v);
string erase_blank(string str);
string getToken(string s, string col);

void students_search(vector<Student> v) {

	string line;
	vector<Student> vec;		//Student 구조체를 담는 벡터 자료구조

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
			printf("\n%-16s%-11s%-21s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if ((v.at(i)).getName() == keyword)
					v.at(i).printInfo();
			}
			break;
		case 2:
			cout << "student ID keyword? ";
			getline(cin, keyword);
			printf("\n%-16s%-11s%-21s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if ((v.at(i)).getID() == keyword)
					v.at(i).printInfo();
			}
			break;
		case 3:
			cout << "admission year keyword? ";
			getline(cin, keyword);
			printf("\n%-16s%-11s%-21s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if (v.at(i).getID().substr(0, 4) == keyword)
					v.at(i).printInfo();
			}
			break;
		case 4:
			cout << "Department name keyword? ";
			getline(cin, keyword);
			printf("\n%-16s%-11s%-21s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
			for (int i = 0; i < v.size(); i++) {
				if ((v.at(i)).getDept() == keyword)
					v.at(i).printInfo();
			}
			break;
		case 5:
			printf("\n%-16s%-11s%-21s%-12s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
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



	//sort 후 출력

	/*if (!vec.empty()) {
		for (int i = 0; i < vec.size(); i++) {
			vec.at(i).printInfo();

		}
	}*/
}


//공백이 있는 문자열에서 우측 공백 제거하여 반환
/*string erase_blank(string str) {
	int n;
	n = str.find_last_not_of(' ') + 1;
	str = str.substr(0, n);
	return str;
}
string getToken(string s, string col)
{
	if (col == "Name")
		return 	erase_blank(s.substr(0, 15));
	else if (col == "ID")
		return erase_blank(s.substr(16, 10));
	else if (col == "Dept")
		return 	erase_blank(s.substr(27, 20));
	else if (col == "Year")
		return erase_blank(s.substr(16, 4));
	else if (col == "Birth")
		return erase_blank(s.substr(48, 4));
	else if (col == "Tel")
		return erase_blank(s.substr(53, 12));
}*/
