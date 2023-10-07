#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<vector>

#include "student.h"
#include"insertion.h"
#include "student_search.h"
#include"sort.h"

using namespace std;

class Management {
	vector<Student> student;

private:
	/*vector<Student> initial_get_info(vector<Student> student) {
		string line;
		ifstream file("Student_INFO.txt");

		if (file.is_open()) {
			cout << "���� ����\n";
			while (!file.eof())
			{
				getline(file, line);
				cout << line << "\n";
				student.push_back(Student(getToken(line, "Name"),
					getToken(line, "ID"),
					getToken(line, "Dept"),
					getToken(line, "Birth"),
					getToken(line, "Tel")));
				cout << student.back().getName();

			}
			return student;
			file.close();
		}
		else
			cout << "���� �ȿ���\n";
	}*/

	vector<Student> getInfo(vector<Student> student) { // ���Ͽ��� ������ �о���� �Լ�
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

public:
	void menu() {
		student = getInfo(student);

		while (true) {
			cout << "1. Insertion " << endl;
			cout << "2. Search" << endl;
			cout << "3. Sorting Option" << endl;
			cout << "4. Exit" << endl;
			cout << "> ";

			int option; cin >> option;

			if (option == 1) {
				insertion();
			}

			else if (option == 2) {
				students_search(student);
			}

			else if (option == 3) {
				sort_menu(student);
			}

			else if (option == 4) {
				cout << "Bye bye" << endl;
				break;
			}

			else {
				cout << "Error. Please do again." << endl;
				break;
			}
		}
		}
};