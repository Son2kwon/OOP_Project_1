#pragma once
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

typedef struct Student {
	string name;
	int64_t ID;
	int Birth;
	string Dept;
	int64_t Tel;
}Student;

class Management {
	vector<Student> student;

public:
	void sort_menu() {
		cout << "1. Sort by Name" << endl;
		cout << "2. Sort by Student ID " << endl;
		cout << "3. Sort by Admission Year " << endl;
		cout << "4. Sort by Department name " << endl;
		cout << "5. List All" << endl;
		cout << ">> ";

		int select; cin >> select;


		if (select == 1) name_sort();
		else if (select == 2) ID_sort();
		else if (select == 3) Year_sort();
		else if (select == 4) Dept_sort();
		else if (select == 5) List_All();

		else {
			cout << "Error!" << endl << endl;
			return;
		}
	}

private:
	fstream f; // 그냥 여기서 쓸 파일 스트림을 그냥 하나로 냅다...
	

	void getInfo() { // 파일에서 정보를 읽어오는 함수
		string line; int count = 0;
		f.open("student_INFO.txt");

		if (f.is_open()) {
			while (getline(f, line)) {
				istringstream ss(line);

				Student s;

				ss >> s.name >> s.ID >> s.Birth >> s.Dept >> s.Tel;

				student.push_back(s);
			}

			f.close();
		}

		else {
			cout << "Unable to open file while getInfo()" << endl << endl;
			return;
		}
	}

	void writeInfo() { // 파일에 정보를 입력하는 함수

		f.open("student_INFO.txt");

		if (f.is_open()) {
			for (int i = 0; i < student.size(); i++) {
				cout << student[i].name << " " << student[i].ID << " " << student[i].Birth << " " << student[i].Dept << " " << student[i].Tel << endl;
			}

			f.close();
		}
		
		else {
			cout << "Unable to open file while writeInfo()" << endl << endl;
			return;
		}	
	}




	void name_sort() {
		getInfo();

		writeInfo();
	}

	void ID_sort() {
		getInfo();

	}

	void Year_sort() {
		getInfo();

	}

	void Dept_sort() {
		getInfo();

	}

	void List_All() {
		getInfo();

	}
};