//*********************************************************************************//
//Name: Justin Tran
//
//Class: CSCI 1106
//
//Program: The program convert list of phone numbers to letters that are assigned
// to digit(s) through text file processing. Then making a new text file for all
//the letter converted to numbers.
//********************************************************************************//

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

int main() {
	ifstream infile;
	ofstream outfile;

	int digit;
	char letters;

	//checking if file is open correctly
	infile.open("oldPhone1.txt");
	if (!infile) {
		cout << "File cannot be open..." << endl;
		exit(1106);
	}
	//checking if file is open correctly
	outfile.open("newPhone.txt");
	if (!outfile) {
		cout << "File cannot be open..." << endl;
		exit(1106);
	}

	infile >> letters;

	while (infile) {
		for (int i = 0; i < 7; i++) {

			if (letters > 'Z')
				letters = static_cast<char>(letters - 32); //converting all lowercase that is read in the textfile to uppercase


			if (letters > 'W') //making a shift of the value to digit 9 instead of 10
				letters = 'W';

			if (letters > 'P')
				letters--; //making a shift of value greater than P by 1 digit
			digit = static_cast<int>((letters - 'A') / 3 + 2); //mathmatical comparison equation to assign letters to their proper digit
			outfile << digit;
			infile >> letters;


		}
		outfile << endl;
	}


	infile.close();
	outfile.close();

	system("pause");
}