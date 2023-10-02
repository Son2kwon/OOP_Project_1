#include <iostream>
#include <string>
#include <vector>

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

	void printInfo() const {
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

	void setName(const string& name) {
		Name = name;
	}

	void setID(const string& id) {
		ID = id;
	}

	void setDept(const string& dept) {
		Dept = dept;
	}

	void setBirth(const string& birth) {
		Birth = birth;
	}

	void setTel(const string& tel) {
		Tel = tel;
	}
};

vector<Student> student;

void insertion() {
	string stuName;
	string stuID;
	string stuBirth;
	string stuDept;
	string stuTel;

	bool idExists = false;
	bool isBlank = false;

	cout << "Name : ";
	getline(cin, stuName);
	if (stuName.empty() || stuName.find_first_not_of(' ') == string::npos) {
		isBlank = true;
		cerr << "Error : Name should not be blank";
		
	}

	cout << "Student ID : ";
	cin >> stuID;
	for (int i = 0; i < student.size(); ++i) {
		if (student[i].getID() == stuID) {
			idExists = true;
			cerr << "Error : Already inserted";
			break;
		}
	}
	cout << "Birth Year : ";
	cin >> stuBirth;
	
	cout << "Department : ";
	cin >> stuDept;
	
	cout << "Tel : ";
	cin >> stuTel;
	
	if (!idExists && !isBlank) {
		Student newStudent(stuName, stuID, stuDept, stuBirth, stuTel);
		student.push_back(newStudent);
	}
}