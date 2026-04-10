//
//  main.cpp
//  files_4
//
//  Created by Grzes Szubryt on 29/10/2024.
//

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
using namespace std;
char przesun(char character){
	string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	if (character == 'Z') {
		return 'A';
	}
	for (int i {}; i < alphabet.length(); i++) {
		if (alphabet[i] == character) {
			character = alphabet[i+1];
			
			return character;

		}
	}
	return NULL;
}
int main(int argc, const char * argv[]) {
	fstream file_in("instrukcje.txt",ios::in);
	string line;
	string output;
	while (getline(file_in,line)) {
		switch (line[0]) {
			case 'D':
				output += line[7];
				break;
			case 'Z':
				output[output.length()-1]  = line[6];
				break;
			case 'U':
				output.pop_back();
				break;
			case 'P':
				for (int i {}; i < line.length(); i++) {
					if (output[i] == line[8]) {
						output[i] = przesun(line[8]);
						break;
					}
				}
				break;
			default:
				break;
		}
		cout << output << endl << endl;

	}
	cout << output << endl;
	cout << output.length() << endl;
	return 0;
}
