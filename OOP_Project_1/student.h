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
	Student(){};
	Student(string name, string id, string dept, string birth, string tel) {
		this->Name = name;
		this->ID = id;
		this->Dept = dept;
		this->Birth = birth;
		this->Tel = tel;
	};

	void printInfo() {
		// cout << Name << "\n" << ID << "\n" << Dept << "\n" << Birth << "\n" << Tel << "\n";
		cout << Name << " " << ID << " " << Birth << " " << Dept << " " << Tel << " " << endl;
	}

	string getName() {
		return Name;
	}

	string getID() {
		return ID;
	}

	string getDept() {
		return Dept;
	}

	string getBirth() {
		return Birth;
	}

	string getTel() {
		return Tel;
	}
};