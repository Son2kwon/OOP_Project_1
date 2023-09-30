#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include <algorithm>
#include<format>

using namespace std;

void students_search();
string erase_blank(string str);
string getToken(string s, string col);


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
		cout << Name << "\n" << ID << "\n" << Dept << "\n" << Birth << "\n" << Tel << "\n";

	}

};




/*int main() {

	students_search();

}*/




void students_search() {

	string line;
	vector<Student> v;		//Student 구조체를 담는 벡터 자료구조.

	string menu_msg = "- Search -\n"
		"1. Search by name\n"
		"2. Search by student ID (10 numbers)\n"
		"3. Search by admission year (4 numbers)\n"
		"4. Search by department name\n"
		"5. List All\n\n";
	cout << menu_msg << ">";

	int select_menu;
	cin >> select_menu;


	ifstream file("students.txt");

	//파일에서 학생 정보를 읽어와서 Student 구조체에 저장, 벡터에 푸시
	if (file.is_open())
	{
		if (select_menu == 5) {		//5.List All 선택시
			while (!file.eof())
			{
				getline(file, line);
				v.push_back(Student(getToken(line, "Name"), 
					getToken(line, "ID"), 
					getToken(line, "Dept"), 
					getToken(line, "Birth"), 
					getToken(line, "Tel")));
			
			}

		}
		else {
			string col = "";
			string keyword = "";
			switch (select_menu) {
			case 1:
				cout << "Name keyword? ";
				cin >> keyword;
				col = "Name";
				break;
			case 2:
				cout << "student ID keyword? ";
				cin >> keyword;
				col = "ID";
				break;
			case 3:
				cout << "admission year keyword? ";
				cin >> keyword;
				col = "Year";
				break;
			case 4:
				cout << "Department name keyword? ";
				cin >> keyword;
				col = "Dept";
				break;
			default: break;

			}
			

			string token;
			while (!file.eof())
			{
				getline(file, line);
				token = getToken(line, col);
				if (token.compare(keyword) == 0) {	//입력한 키워드와 같은지 체크

					v.push_back(Student(getToken(line, "Name"),
						getToken(line, "ID"),
						getToken(line, "Dept"),
						getToken(line, "Birth"),
						getToken(line, "Tel")));


				}
			}


		}

		file.close();
	}
	else
		cout << "파일 안열림";


	//sort(v.begin(), v.end());



	//sort 후 출력
	printf("%-15s%-10s%-20s%-11s%-12s\n", "Name", "StudentID", "Dept", "Birth Year", "Tel");

	for (int i = 0; i < v.size(); i++) {
		v.at(i).printInfo();
	}





}


//공백이 있는 문자열에서 우측 공백 제거하여 반환
string erase_blank(string str) {
	int n;
	n = str.find_last_not_of(' ') + 1;
	str = str.substr(0, n);
	return str;
}
string getToken(string s,string col)
{
	if (col == "Name")
		return 	erase_blank(s.substr(0, 15));
	else if (col == "ID")
		return erase_blank(s.substr(15, 10));
	else if (col == "Dept")
		return 	erase_blank(s.substr(25, 20));
	else if (col == "Year")
		return erase_blank(s.substr(15, 4));
	else if (col == "Birth")
		return erase_blank(s.substr(45, 4));
	else if (col == "Tel")
		return erase_blank(s.substr(49, 12));

	
}

