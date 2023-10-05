#pragma once
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

void name_sort(vector<Student> student);
void ID_sort(vector<Student> student);
void Year_sort(vector<Student> student);
void Dept_sort(vector<Student> student);

void sort_menu(vector<Student> student) {
	cout << "1. Sort by Name" << endl;
	cout << "2. Sort by Student ID " << endl;
	cout << "3. Sort by Admission Year " << endl;
	cout << "4. Sort by Department name " << endl;
	cout << ">> ";

	int select; cin >> select;


	if (select == 1) name_sort(student);
	else if (select == 2) ID_sort(student);
	else if (select == 3) Year_sort(student);
	else if (select == 4) Dept_sort(student);

	else {
		cout << "Error!" << endl << endl;
		return;
	}
}

vector<Student> getInfo(vector<Student> student) { // 파일에서 정보를 읽어오는 함수
	string line; int count = 0;
	fstream f;
	f.open("student_INFO.txt");

	if (f.is_open()) {
		while (getline(f, line)) {
			istringstream ss(line);

			string Name;
			string ID;
			string Dept;
			string Birth;
			string Tel;

			ss >> Name >> ID >> Dept >> Birth >> Tel;

			Student s(Name, ID, Dept, Birth, Tel);

			student.push_back(s);
		}

		f.close();
	}

	else {
		cout << "Unable to open file while getInfo()" << endl << endl;
	}

	return student;
}

void writeInfo(vector<Student> student) { // 파일에 정보를 입력하는 함수
	fstream f;
	f.open("student_INFO.txt");

	if (f.is_open()) {
		for (int i = 0; i < student.size(); i++) {
			student[i].printInfo();
			f << student[i].getName() << " " << student[i].getID() << " " << student[i].getBirth() << " " << student[i].getDept() << " " << student[i].getTel() << " " << endl;
		}

		f.close();
	}

	else {
		cout << "Unable to open file while writeInfo()" << endl << endl;
		return;
	}
}

bool name_cmp(Student& a, Student& b) {
	return a.getName() < b.getName();
}

bool ID_cmp(Student& a, Student& b) {
	return a.getID() < b.getID();
}

bool Year_cmp(Student& a, Student& b) {
	return (a.getID()).substr(0, 4) < (b.getID()).substr(0, 4);
}

bool dept_cmp(Student& a, Student& b) {
	return a.getDept() < b.getDept();
}


void name_sort(vector<Student> student) {
	student = getInfo(student);

	sort(student.begin(), student.end(), name_cmp);

	writeInfo(student);
}

void ID_sort(vector<Student> student) {
	student = getInfo(student);

	sort(student.begin(), student.end(), ID_cmp);

	writeInfo(student);
}

void Year_sort(vector<Student> student) {
	student = getInfo(student);

	sort(student.begin(), student.end(), Year_cmp);

	writeInfo(student);
}

void Dept_sort(vector<Student> student) {
	student = getInfo(student);

	sort(student.begin(), student.end(), dept_cmp);

	writeInfo(student);
}