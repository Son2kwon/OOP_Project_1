#include <iostream>
#include "sort.h"
#include "student_search.h"
#include "student.h"
#include "Management.h"

using namespace std;




int main() {
	//Management management;
	//management.sort_menu();
	Management m;
	m.initial_get_info();
	m.Search();
}