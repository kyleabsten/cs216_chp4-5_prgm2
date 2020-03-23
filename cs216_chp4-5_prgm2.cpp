/*
Programmer name:  Kyle Absten
Date: 03/01/2020

This is the second program for the Chapter 4-5 of CS216.

This program will read text from a given .txt file.  The .txt file contains three lines that 
each contain 4 entry fields.  Those fields hold lastName, firstName, startingSalary, and 
increase(the percentage of a raise the employee is due). Using a for loop, the program
will go through the three lines of the .txt file.  For each of the lines, the four fields 
of text are assigned to their respective variables. The raise is then calculated and assigned 
to newSalary. The firstName, lastName and salary are then written to an output file called 
employeeOutput.txt.  The newSalary is added to the totalSalary variable to end the loop.

Once all three lines have looped, the program writes the totalSalary to the console and closes the
input and output files.

*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream inputFile;  // An ifstream variable that links the variable to an input file.
	ofstream outputFile;  // An ofstream variable that links the variable to an output file.
	string firstName,  // A string variable to hold the first name.
		lastName;  // A string variable to hold the last name.
	double startingSalary,  // A double to hold the current salary
		increase,  // A double to hold the percentage of a raise
		newSalary,  // A double to hold the computed value of the new salary after the raise is applied.
		totalSalary = 0;  // A double to hold the sum of all the new salaries.

	inputFile.open("employeeSalary.txt");  // Link the inputFile ifstream to the give .txt file.
	outputFile.open("employeeOutput.txt");  // Link the outputFile ofstream to a .txt file.

	if (inputFile.fail()) {  // Check to make sure reading the initial .txt file worked.
		cout << "Reading of files failed.";
	};

	for (int inputFields = 1; inputFields <= 3; inputFields++) {  // This loop runs through the 3 lines of the .txt file.
			inputFile >> lastName;
			inputFile >> firstName;
			inputFile >> startingSalary;
			inputFile >> increase;

			// Compute the new salary of the given person
			newSalary = (startingSalary * (increase + 100) / 100);

			outputFile << fixed << setprecision(2);
			outputFile << firstName << " " << lastName << " "  // Write the variables to the output file in the right order.
				<< newSalary << endl;

			totalSalary += newSalary;  // Add the new salary of the current person to the totalSalary variable.

			
	};
	cout << fixed << setprecision(2);
	cout << "The new total salary for all three employees is: $" << totalSalary;

	inputFile.close();  //Close the input file.
	outputFile.close();  // Close the output file.

	return 0 ;

}