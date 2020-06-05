//Author: Smrithi Upadhyayula
//Date: 12/3/2019
//Instructor: Dr. Thompson
//Description: Game where Anthony the Ant tries to take over all the ant colonies

#include "su0060HW4.h"
using namespace std;

int main ()
{
	ofstream out_stream;
	ifstream in_stream;
	printInfo (); //prints introductory info
	gameIntro (); //prints intro to game
	int** array;
	char saveGame = 'N';
	char fileName [20] ;
	int currentColumn;
	int numAntsSaved, currentColumnSaved; // collect saved values of numAnts, currentColumn from
	//file
	array = new int* [SIZE];
	for (int i = 0; i < SIZE; i++) //allocate memory for array
	{
		array[i] = new int [SIZE];
	}
	int numAnts, addAnts; // total number of ants in army, number of ants to add to army
	cout << "Would you like to resume a previously saved game? Type Y/N: ";
	cin >> saveGame;
	if ((saveGame == 'Y') || (saveGame == 'y'))
	{
		cout << "What is the name of the file where your previous game is stored?" << endl;
		cin >> fileName;
		in_stream.open(fileName);
		if (in_stream.fail())
		{
			cout << "Failed to open file. Exiting game." << endl;
			return 0;
		}
		else 
		{
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					in_stream >> array [i][j];
				}
			}
			in_stream>> numAntsSaved;
			in_stream >> currentColumnSaved;
			currentColumn = currentColumnSaved;
			numAnts = numAntsSaved;
			cout << "Saved game loaded. Let's begin!" << endl;
		}
	}
	else
	{
	cout << "Okay, let's start fresh!" << endl;
	initializeArray (array, numAnts); // initialize the array
	currentColumn = 0; // the column we are currently on
	}
	cout << "Initializing board... " << endl;

	if ((saveGame == 'y') || (saveGame == 'Y'))
		displayArray (array, currentColumn);
	else
	displayArray (array, currentColumn + 1); 
	cout << endl << "Now let's begin... Anthony's army is " << numAnts << " strong!" << endl;
	int currentRow;
	bool found = false;
	for (int i = 1; i < SIZE; i++) //iterate through columns, starting with B
	{

		if ((saveGame == 'Y') || (saveGame == 'y'))
		{
			i = currentColumn;
		}
		else 
		{
		currentColumn = i;
		}
		do{ // repeat as long as colony isn't found
		do
		{
			cout << "Enter row position in column " << static_cast<char>(i + 65);
			cout << " to strike: ";
			cin >> currentRow; //get row 
			if ((currentRow < 0) || (currentRow > 9))
				cout << "Invalid row. Try again." << endl; // make sure row is in range
		} while ((currentRow < 0) || (currentRow > 9));
		found = isFound (currentRow, currentColumn, numAnts, array);
		if (found) 
		{
			cout << "Anthony's army found ant colony in column " << static_cast<char>(i + 65);
			addAnts = 0;
			for (int j = 0; j < SIZE; j++)
				{
					if (array[j][currentColumn] > 0)
						addAnts += array[j][currentColumn];
				} //add all remaining ants to Anthony's army
			cout << ", captured " << addAnts << " ants." << endl;
			numAnts += addAnts;
			displayArray (array, currentColumn + 1);
		}
		else if (numAnts <= 0)
		{
			cout << "Sorry, but Anthony's army has been defeated before taking over all ant ";
			cout << "colonies. " << endl;
			displayArray (array, currentColumn + (SIZE - currentColumn ));
			deleteArray (array);
			return 0;
		}
		else {
			displayArray (array, currentColumn);
		}
		cout << "Would you like to save your game and continue later? Type 'Y' or 'N'." << endl;
		cin >> saveGame;
		if ((saveGame == 'Y') || (saveGame =='y'))
		{
			cout << "Enter the name of the file you would like to save in." << endl;
			cin >> fileName;
			out_stream.open(fileName);
			if (out_stream.fail())
			{
				cout << "Failed to open file. Exiting program." << endl;
				exit(EXIT_FAILURE);
			}
			else 
			{
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						out_stream << array[i][j] << " ";
					}
					out_stream << endl;
				}
				out_stream << numAnts << endl;
				out_stream << currentColumn << endl;
				cout << "Saved! Thank you for playing." << endl;
				return 0;
			}
		}
		} while (!found);
	}
	cout << "Congratulations! Anthony has taken over all ant colonies with " << numAnts;
	cout << " ants remaining." << endl;
	deleteArray (array);
	return 0;		
}




