#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include <algorithm>
#include<format>

using namespace std;

void students_search();
string erase_blank(string str);


struct Student {
	string name;
	string ID;
	string dept;
	string birth_year;
	string tel;
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


	string keyword = "";
	int start_pos = 0;
	int n = 0;
	switch (select_menu) {
	case 1:
		cout << "Name keyword? ";
		cin >> keyword;
		start_pos = 0; n = 15;
		break;
	case 2:
		cout << "student ID keyword? ";
		cin >> keyword;
		start_pos = 15; n = 10;
		break;
	case 3:
		cout << "admission year keyword? ";
		cin >> keyword;
		start_pos = 15; n = 4;
		break;
	case 4:
		cout << "Department name keyword? ";
		cin >> keyword;
		start_pos = 25; n = 20;
		break;
	default: break;

	}





	ifstream file("students.txt");


	//파일에서 학생 정보를 읽어와서 Student 구조체에 저장, 벡터에 푸시
	if (file.is_open())
	{
		cout << "파일 열림\n";

			
		if (select_menu == 5) {		//5.List All 선택시
			while (!file.eof())
			{
				getline(file, line);
				Student s;
				s = { erase_blank(line.substr(0,15)),
					erase_blank(line.substr(15,10)),
					erase_blank(line.substr(25,20)),
					erase_blank(line.substr(45,4)),
					erase_blank(line.substr(49,12)) };
				v.push_back(s);
				cout << s.name << "\n";


			}

		}
		else {
			while (!file.eof())
			{
				getline(file, line);
				cout << line << '\n';
				string str = erase_blank(line.substr(start_pos, n));
				Student s;
				if (str.compare(keyword) == 0) {	//입력한 키워드와 같은지 체크

					cout << str << "\n";
					s = { erase_blank(line.substr(0,15)),
						erase_blank(line.substr(15,10)),
						erase_blank(line.substr(25,20)),
						erase_blank(line.substr(45,4)),
						erase_blank(line.substr(49,12)) };
					v.push_back(s);
					cout << s.name << "\n";

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
	Student st;
	for (int i = 0; i < v.size(); i++) {
		st = v.at(i);
		//printf("%15s%10s%20s%11s%12s\n", st.name, st.ID, st.dept, st.birth_year, st.tel);
		cout << st.name << "\n" << st.ID << "\n" << st.dept << "\n" << st.birth_year << "\n" << st.tel << "\n";
	}





}


//공백이 있는 문자열에서 우측 공백 제거하여 반환
string erase_blank(string str) {
	int n;
	n = str.find_last_not_of(' ') + 1;
	str = str.substr(0, n);
	return str;
}