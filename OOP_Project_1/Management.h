#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include <algorithm>
#include "student_search.h"
#include "student.h"

using namespace std;


class Management {

	vector<Student> v;
	int sorting_option;


public:
	void initial_get_info();
	void Search();
	/*void Sort() {

	}*/




};