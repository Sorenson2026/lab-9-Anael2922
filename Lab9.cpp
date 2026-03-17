//This program reads students names from a file with one name per line.
//Anael Redrovan
// 3/17/2026

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Greeting
	cout << " Hellow, this program reads the names of studens from a file" << endl; 

	string fileName; 
	cout << "Enter file name: " << endl; 
	cin >> fileName; 

	ifstream file;

	file.open(fileName);

	//check if file exists

	if (!file)
	{
		cout << "This file does not exist" << endl; 
		return 0; 
	}
	
	string name; 
	string firstName, lastName; 
	int count = 0; 

	//Read names from file
	while (getline(file, name)) {
		if (name == "") {
			continue; //skip empty line
		}
		if (count == 0) {
			firstName = name;
			lastName = name;
		}
		else {
			if (name < firstName) {
				firstName = name;
			}
			if (name > lastName) {
				lastName = name; 
			}
		}
		count++; 
	}
	file.close(); 

	//Output results
	if (count == 0) {
		cout << "No names found in the file." << endl; 
	}
	else {
		cout << "First name alphabetically: " << firstName << endl; 
		cout << "Last name alphobetically: " << lastName << endl; 
		cout << "Total number of names: " << count << endl; 
	}

	return 0; 
}
