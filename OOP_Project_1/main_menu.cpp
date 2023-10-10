#include <iostream>
#include<fstream>
#include "Management.h"

using namespace std;


int main(int argc, char *argv[]) {
	Management management;
	ofstream file;

	file.open(argv[1], ios_base::app);
	file.close();

	management.menu();
}