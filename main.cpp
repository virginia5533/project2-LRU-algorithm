//Virginia Vaughan
//Main.cpp
//
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


vector<int> readInRef(vector<int> vect);
void LRU(int f1, int f2, int f3, vector<int> vect);

int main() {

	vector<int> refStrVect;
	int frame1, frame2, frame3;



	cout << "Please enter the reference string separated by spaces: ";
	refStrVect = readInRef(refStrVect);


	cout << "The reference string is: ";
	for (int i = 0; i < refStrVect.size(); i++) {
		cout << refStrVect.at(i) << " ";

	}

	cout << endl;
	cout << "Please enter the frame numbers: ";
	cin >> frame1 >> frame2 >> frame3;

	cout << "The frame numbers are: " << frame1 << " " << frame2 << " " << frame3 << endl;

	LRU(frame1, frame2, frame3, refStrVect);

}

vector<int> readInRef(vector<int> vect) {

	do{

		int index;
		cin >> index;

		vect.push_back(index);
	} while (cin.peek() != '\n');

	return vect;
}

void LRU(int f1, int f2, int f3, vector<int> vect){

	int pageFaults = 0;

	vector<int> frame = { -1, -1, -1};

	cout << "Assignment of frames by LRU algorithm:" << endl;
	cout << "Frames: " << f1 << '\t' << f2 << '\t'<< f3 << endl;
	cout << "------------------------------------------------------" << endl;

	for(int i = 0; i < vect.size(); i++) {

		for(int i = 0; i < frame.size(); i++) {

			if(frame.at(i) == -1) {
				frame.at(i) = vect.at(i);
				cout << '\t' << frame.at(0) << '\t' <<  frame.at(1) << '\t' <<  frame.at(2) << endl;

			}

			else {
				//LRU

			}

		}
			cout << '\t' << frame.at(0) << '\t' <<  frame.at(1) << '\t' <<  frame.at(2) << endl;

		



	}

}






