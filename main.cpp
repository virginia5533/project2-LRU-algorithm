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


	cout << "Thanks for using this program, dear Memory Manager!" << endl;
	cout << "Completed with exit code: 0" << endl;
	exit(0);

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

	cout << "Assignment of frames by LRU algorithm:" << endl << endl;
	cout << "Frames: " << f1 << '\t' << f2 << '\t'<< f3 << endl;
	cout << "------------------------------------------------------" << endl;

	for(int i = 0; i < vect.size(); i++) {

		int index = i;
		int LRU1 = -1;
		int LRU2 = -1;

		for(int i = 0; i < frame.size(); i++) {

			

			if(frame.at(i) == -1) {
				frame.at(i) = vect.at(i);
				cout << '\t' << frame.at(0) << '\t' <<  frame.at(1) << '\t' <<  frame.at(2) << endl;
				pageFaults++;
				break;

			}

			else if((vect.at(index) != frame.at(0)) && (vect.at(index) != frame.at(1)) && (vect.at(index) != frame.at(2))){
				//LRU
				LRU1 = -1;
				LRU2 = -1;
				
				
				

				for(int j = 0; j < index; j++) {
					if(vect.at(j) == frame.at(0) || vect.at(j) == frame.at(1) || vect.at(j) == frame.at(2)) {
						LRU1 = vect.at(j);
						

					}
				}
				for(int j = 0; j < index; j++) {
					if((vect.at(j) == frame.at(0) || vect.at(j) == frame.at(1) || vect.at(j) == frame.at(2)) && (vect.at(j) != LRU1)){

						LRU2 = vect.at(j);
						
					}

				}

				//cout << LRU1 << " " << LRU2 << endl;

				if((LRU1 != frame.at(0)) && (LRU2 != frame.at(0))) {

					frame.at(0) = vect.at(index);
					cout << '\t' << frame.at(0) << '\t' <<  frame.at(1) << '\t' <<  frame.at(2) << endl;
					pageFaults++;
					break;
				}

				else if((LRU1 != frame.at(1)) && (LRU2 != frame.at(1))) {

                                        frame.at(1) = vect.at(index);
                                        cout << '\t' << frame.at(0) << '\t' <<  frame.at(1) << '\t' <<  frame.at(2) << endl;
                                        pageFaults++;
					break;
                                }

				else if((LRU1 != frame.at(2)) && (LRU2 != frame.at(2))) {

                                        frame.at(2) = vect.at(index);
                                        cout << '\t' << frame.at(0) << '\t' <<  frame.at(1) << '\t' <<  frame.at(2) << endl;
                                        pageFaults++;
					break;
                                }






			}

			else{
                                
                                cout << '\t' << frame.at(0) << '\t' <<  frame.at(1) << '\t' <<  frame.at(2) << endl;
                                break;

                        }

			


		}

		



	}
	cout << "------------------------------------------------------" << endl;

	cout << "Number of Page Faults: " << pageFaults << endl;

}






