//#include <iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include <algorithm>
//#include "student.h"
//
//using namespace std;
//
//void students_search(vector<Student>);
//string erase_blank(string str);
//string getToken(string s, string col);
//
//
///*int main() {
//
//	students_search();
//
//}*/
//
//
//
//
//void students_search(vector<Student> v) {
//
//	string line;
//	vector<Student> vec;		//Student 구조체를 담는 벡터 자료구조
//
//	string menu_msg = "- Search -\n"
//		"1. Search by name\n"
//		"2. Search by student ID (10 numbers)\n"
//		"3. Search by admission year (4 numbers)\n"
//		"4. Search by department name\n"
//		"5. List All\n\n";
//	cout << menu_msg << ">";
//
//	int select_menu;
//	cin >> select_menu;
//
//
//
//
//	string keyword = "";
//	if (!v.empty()) {
//		switch (select_menu) {
//		case 1:
//			cout << "Name keyword? ";
//			cin >> keyword;
//			for (int i = 0; i < v.size(); i++) {
//				if ((v.at(i)).getName() == keyword)
//					vec.push_back(v.at(i));
//			}
//			break;
//		case 2:
//			cout << "student ID keyword? ";
//			cin >> keyword;
//			for (int i = 0; i < v.size(); i++) {
//				if ((v.at(i)).getID() == keyword)
//					vec.push_back(v.at(i));
//			}
//			break;
//		case 3:
//			cout << "admission year keyword? ";
//			cin >> keyword;
//			for (int i = 0; i < v.size(); i++) {
//				if (v.at(i).getID().substr(0, 4) == keyword)
//					vec.push_back(v.at(i));
//			}
//			break;
//		case 4:
//			cout << "Department name keyword? ";
//			cin >> keyword;
//			for (int i = 0; i < v.size(); i++) {
//				if ((v.at(i)).getDept() == keyword)
//					vec.push_back(v.at(i));
//			}
//			break;
//		default: break;
//
//		}
//
//	}
//	
//
//	
//
//
//
//	//sort(vec.begin(), vec.end());
//
//
//
//	//sort 후 출력
//	printf("%-15s%-10s%-20s%-11s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");
//
//	if (!vec.empty()) {
//		for (int i = 0; i < vec.size(); i++) {
//			vec.at(i).printInfo();
//		}
//	}
//	
//
//
//
//
//
//}
//
//
////공백이 있는 문자열에서 우측 공백 제거하여 반환
//string erase_blank(string str) {
//	int n;
//	n = str.find_last_not_of(' ') + 1;
//	str = str.substr(0, n);
//	return str;
//}
//string getToken(string s,string col)
//{
//	if (col == "Name")
//		return 	erase_blank(s.substr(0, 15));
//	else if (col == "ID")
//		return erase_blank(s.substr(15, 10));
//	else if (col == "Dept")
//		return 	erase_blank(s.substr(25, 20));
//	else if (col == "Year")
//		return erase_blank(s.substr(15, 4));
//	else if (col == "Birth")
//		return erase_blank(s.substr(45, 4));
//	else if (col == "Tel")
//		return erase_blank(s.substr(49, 12));
//
//	
//}
//
