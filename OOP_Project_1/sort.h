#pragma once
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Student {
	string Name;
	string ID;
	string Dept;
	string Birth;
	string Tel;

public:
	Student() {	};
	Student(string name, string id, string dept, string birth, string tel) {
		Name = name;
		ID = id;
		Dept = dept;
		Birth = birth;
		Tel = tel;
	}

	void printInfo() {
		// cout << Name << "\n" << ID << "\n" << Dept << "\n" << Birth << "\n" << Tel << "\n";
		cout << Name << " " << ID << " " << Birth << " " << Dept << " " << Tel << " " << endl;;
	}

	string getName() const {
		return Name;
	}

	string getID() const {
		return ID;
	}

	string getDept() const {
		return Dept;
	}

	string getBirth() const {
		return Birth;
	}

	string getTel() const {
		return Tel;
	}
};

class Management {
	vector<Student> student;

public:
	void sort_menu() {
		cout << "1. Sort by Name" << endl;
		cout << "2. Sort by Student ID " << endl;
		cout << "3. Sort by Admission Year " << endl;
		cout << "4. Sort by Department name " << endl;
		cout << ">> ";

		int select; cin >> select;


		if (select == 1) name_sort();
		else if (select == 2) ID_sort();
		else if (select == 3) Year_sort();
		else if (select == 4) Dept_sort();

		else {
			cout << "Error!" << endl << endl;
			return;
		}
	}

private:
	fstream f; // �׳� ���⼭ �� ���� ��Ʈ���� �׳� �ϳ��� ����...


	void getInfo() { // ���Ͽ��� ������ �о���� �Լ�
		string line; int count = 0;
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
			return;
		}
	}

	void writeInfo() { // ���Ͽ� ������ �Է��ϴ� �Լ�

		f.open("student_INFO.txt");

		if (f.is_open()) {
			for (int i = 0; i < student.size(); i++) {
				student[i].printInfo();
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

		sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
			return a.getName() < b.getName(); // �̸��� ������������ ����
			});

		writeInfo();
	}

	void ID_sort() {
		getInfo();

		sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
			return a.getID() < b.getID(); // ID�� ������������ ����
			});

		writeInfo();
	}

	void Year_sort() {
		getInfo();

		sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
			return (a.getID()).substr(0, 4) < (b.getID()).substr(0,4); // ID�� ù 4���� ���� �������� ����
			});

		writeInfo();
	}

	void Dept_sort() {
		getInfo();

		sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
			return a.getDept() < b.getDept(); // �а� ���� �������� ����
			});

		writeInfo();
	}
};