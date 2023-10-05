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
	void initial_get_info() {
		string line;
		ifstream file("students.txt");

		if (file.is_open()) {
			cout << "파일 열림\n";
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
			file.close();
		}
		else
			cout << "파일 안열림\n";
	}

public:
	void menu() {
		while (true) {
			cout << "1. Insertion " << endl;
			cout << "2. Search" << endl;
			cout << "3. Sorting Option" << endl;
			cout << "4.Exit" << endl;
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