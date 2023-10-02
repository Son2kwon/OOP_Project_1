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
	Student();
	Student(string name, string id, string dept, string birth, string tel);

	void printInfo();

	string getName();

	string getID() ;

	string getDept() ;

	string getBirth() ;

	string getTel() ;
};