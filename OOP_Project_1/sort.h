#pragma once
#include <iostream>
#include<fstream>
#include<algorithm>

using namespace std;

class Student {
	string name;
	int64_t ID;
	int Birth;
	string Dept;
	int64_t Tel;

public:
	Student(string name, int64_t ID, int Birth, string Dept, int64_t Tel) {
		this->name = name;
		this->ID = ID;
		this->Birth = Birth;
		this->Dept = Dept;
		this->Tel = Tel;
	}
};

class Management {

public:
	void sort_menu() {
		cout << "1. Sort by Name" << endl;
		cout << "2. Sort by Student ID " << endl;
		cout << "3. Sort by Admission Year " << endl;
		cout << "4. Sort by Department name " << endl;

		int select; cin >> select;

		if (select == 1)
			name_sort();
		else if (select == 2)
			ID_sort();
		else if (select == 3)
			Year_sort();
		else if (select == 4)
			Dept_sort();
		else {
			cout << "Error!" << endl << endl;
			return;
		}
	}

private:
	void name_sort() {
		fstream f;
		f.open("student_INFO.txt");

		if (f.is_open()) {


			f.close();
		}

		else cout << "Unable to open file" << endl << endl;
	}

	void ID_sort() {
		fstream f;
		f.open("student_INFO.txt");

		if (f.is_open()) {


			f.close();
		}

		else cout << "Unable to open file" << endl << endl;
	}

	void Year_sort() {
		fstream f;
		f.open("student_INFO.txt");

		if (f.is_open()) {


			f.close();
		}

		else cout << "Unable to open file" << endl << endl;
	}

	void Dept_sort() {
		fstream f;
		f.open("student_INFO.txt");

		if (f.is_open()) {


			f.close();
		}

		else cout << "Unable to open file" << endl << endl;
	}
};