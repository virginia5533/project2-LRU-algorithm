//Virginia Vaughan
//Main.cpp
//
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


vector<int> readInRef(vector<int> vect);

int main() {

	vector<int> refStrVect;

	cout << "Please enter the reference string separated by spaces: ";
	refStrVect = readInRef(refStrVect);


	cout << "The reference string is: ";
	for (int i = 0; i < refStrVect.size(); i++) {
		cout << refStrVect.at(i); << '\t';

	}



}

vector<int> readInRef(vector<int> vect) {

	do{

		int index;
		cin >> index;

		vect.push_back(location);
	} while (cin.peek() != '\n');

	return vect;
}







