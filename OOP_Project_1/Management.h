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
	vector<Student> initial_get_info(vector<Student> student) {
		string line;
		ifstream file("file1.txt");

		if (file.is_open()) {
			while (!file.eof())
			{
				getline(file, line);

				string Name;
				string ID;
				string Dept;
				string Birth;
				string Tel;

				int cur_position = 0;
				int position;
				string temp[5]; int i = 0;

				while ((position = line.find(',', cur_position)) != std::string::npos) {
					int len = position - cur_position;
					string result = line.substr(cur_position, len);
					temp[i] = result;
					cur_position = position + 1; i++;
				}

				temp[4] = line.substr(cur_position);

				Student s(temp[0], temp[1], temp[2], temp[3], temp[4]);
				student.push_back(s);

			}
			name_sort(student);
			return student;
			file.close();
		}
		else
			cout << "파일 안열림\n";
	}

	void writeInfo(vector<Student> student) { // 파일에 정보를 입력하는 함수
		fstream f;
		f.open("file1.txt");

		if (f.is_open()) {
			for (int i = 0; i < student.size(); i++) {
				if (student[i].getName() == "") continue;
				//student[i].printInfo();
				f << student[i].getName() << "," << student[i].getID() << "," << student[i].getDept() << "," << student[i].getBirth() << "," << student[i].getTel() << endl;
			}

			f.close();
		}

		else {
			cout << "Unable to open file while writeInfo()" << endl << endl;
			return;
		}
	}

public:
	void menu() {
		student = initial_get_info(student);

		while (true) {
			cout << "1. Insertion " << endl;
			cout << "2. Search" << endl;
			cout << "3. Sorting Option" << endl;
			cout << "4. Exit" << endl;
			cout << "> ";

			int option; cin >> option;

			if (option == 1) {
				insertion(student);
			}

			else if (option == 2) {
				students_search(student);
			}

			else if (option == 3) {
				sort_menu(student);
			}

			else if (option == 4) {
				writeInfo(student);
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