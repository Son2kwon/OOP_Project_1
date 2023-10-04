//#pragma once
//#include<iostream>
//#include<fstream>
//#include<algorithm>
//#include<string>
//#include<sstream>
//#include<vector>
//
//using namespace std;
//
//void sort_menu(vector<Student> student) {
//	cout << "1. Sort by Name" << endl;
//	cout << "2. Sort by Student ID " << endl;
//	cout << "3. Sort by Admission Year " << endl;
//	cout << "4. Sort by Department name " << endl;
//	cout << ">> ";
//
//	int select; cin >> select;
//
//
//	if (select == 1) name_sort(student);
//	else if (select == 2) ID_sort(student);
//	else if (select == 3) Year_sort(student);
//	else if (select == 4) Dept_sort(student);
//
//	else {
//		cout << "Error!" << endl << endl;
//		return;
//	}
//}
//fstream f; // �׳� ���⼭ �� ���� ��Ʈ���� �׳� �ϳ��� ����...
//
//
//void getInfo() { // ���Ͽ��� ������ �о���� �Լ�
//	string line; int count = 0;
//	f.open("student_INFO.txt");
//
//	if (f.is_open()) {
//		while (getline(f, line)) {
//			istringstream ss(line);
//
//			string Name;
//			string ID;
//			string Dept;
//			string Birth;
//			string Tel;
//
//			ss >> Name >> ID >> Dept >> Birth >> Tel;
//
//			Student s(Name, ID, Dept, Birth, Tel);
//
//			student.push_back(s);
//		}
//
//		f.close();
//	}
//
//	else {
//		cout << "Unable to open file while getInfo()" << endl << endl;
//		return;
//	}
//}
//
//void writeInfo() { // ���Ͽ� ������ �Է��ϴ� �Լ�
//
//	f.open("student_INFO.txt");
//
//	if (f.is_open()) {
//		for (int i = 0; i < student.size(); i++) {
//			student[i].printInfo();
//		}
//
//		f.close();
//	}
//
//	else {
//		cout << "Unable to open file while writeInfo()" << endl << endl;
//		return;
//	}
//}
//
//void name_sort(vector<Student> student) {
//	getInfo();
//
//	sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
//		return a.getName() < b.getName(); // �̸��� ������������ ����
//		});
//
//	writeInfo();
//}
//
//void ID_sort(vector<Student> student) {
//	getInfo();
//
//	sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
//		return a.getID() < b.getID(); // ID�� ������������ ����
//		});
//
//	writeInfo();
//}
//
//void Year_sort(vector<Student> student) {
//	getInfo();
//
//	sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
//		return (a.getID()).substr(0, 4) < (b.getID()).substr(0, 4); // ID�� ù 4���� ���� �������� ����
//		});
//
//	writeInfo();
//}
//
//void Dept_sort(vector<Student> student) {
//	getInfo();
//
//	sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
//		return a.getDept() < b.getDept(); // �а� ���� �������� ����
//		});
//
//	writeInfo();
//}