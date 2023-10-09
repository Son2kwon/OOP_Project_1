#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"student.h"
#include"sort.h"

using namespace std;

void insertion(vector<Student>& student);
void fileInsert(Student newStudent);

void insertion(vector<Student>& student) {
    string stuName;
    string stuID;
    string stuBirth;
    string stuDept;
    string stuTel;

    bool idExists = false;
    bool isBlank = false;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 개행 문자 정확히 제거

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

    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 개행 문자 정확히 제거

    cout << "Birth Year : ";
    cin >> stuBirth;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 개행 문자 정확히 제거

    cout << "Department : ";
    getline(cin, stuDept);

    cout << "Tel : ";
    getline(cin, stuTel);
    cout << endl;

    if (!idExists && !isBlank) {
        Student newStudent(stuName, stuID, stuDept, stuBirth, stuTel);
        student.push_back(newStudent);
        name_sort(student);
        fileInsert(newStudent);
    }
}

void fileInsert(Student newStudent) {
    ofstream f("students.txt", ios::app);
    if (f.is_open()) {
        f << newStudent.getName() << ',' << newStudent.getID() << ',' << newStudent.getDept() << ',' << newStudent.getBirth() << ',' << newStudent.getTel() << '\n';
        f.close();
    }
    else {
        cerr << "Unable to open file";
    }
}