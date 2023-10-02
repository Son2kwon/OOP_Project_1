#pragma once
#include<iostream>

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
