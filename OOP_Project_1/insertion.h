#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"student.h"

using namespace std;

vector<Student> student;

void insertion() {
	string stuName;
	string stuID;
	string stuBirth;
	string stuDept;
	string stuTel;

	bool idExists = false;
	bool isBlank = false;
	cin.ignore();

	cout << "Name : ";
	getline(cin, stuName);
	if (stuName.empty() || stuName.find_first_not_of(' ') == string::npos) {
		isBlank = true;
		cerr << "Error : Name should not be blank";

	}

	cout << "Student ID : ";
	cin >> stuID;
	for (int i = 0; i < student.size(); ++i) {
		if (student[i].getID() == stuID) {
			idExists = true;
			cerr << "Error : Already inserted";
			break;
		}
	}
	cout << "Birth Year : ";
	cin >> stuBirth;

	cout << "Department : ";
	cin >> stuDept;

	cout << "Tel : ";
	cin >> stuTel;

	if (!idExists && !isBlank) {
		Student newStudent(stuName, stuID, stuDept, stuBirth, stuTel);
		student.push_back(newStudent);
	}
}