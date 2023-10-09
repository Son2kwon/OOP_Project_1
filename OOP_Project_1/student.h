#pragma once
#include<iostream>
#include<iomanip>


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
		cout << setw(16)<<left<<Name <<setw(11)<<left<< ID << setw(21) <<left<< Dept << setw(12)<<left << Birth <<setw(13) <<left<< Tel << endl;
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