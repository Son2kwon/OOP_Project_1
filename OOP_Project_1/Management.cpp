//#include <iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include <algorithm>
//#include "student_search.h"
//#include "student.h"
//#include "Management.h"
//
//using namespace std;
//
//
//
//
//
//void Management::initial_get_info() {
//	string line;
//	ifstream file("students.txt");
//
//	if (file.is_open()) {
//		cout << "파일 열림\n";
//		while (!file.eof())
//		{
//			getline(file, line);
//			cout << line << "\n";
//			v.push_back(Student(getToken(line, "Name"),
//				getToken(line, "ID"),
//				getToken(line, "Dept"),
//				getToken(line, "Birth"),
//				getToken(line, "Tel")));
//			cout << v.back().getName();
//
//		}
//		file.close();
//	}
//	else
//		cout << "파일 안열림\n";
//
//}
//void Management::Search() {
//	students_search(v);
//}
///*void Sort() {
//		
//}*/
//
//	
//
//
