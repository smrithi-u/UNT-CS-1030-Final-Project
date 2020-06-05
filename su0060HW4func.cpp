//Author: Smrithi Upadhyayula
//Date: 12/3/2019
//Instructor: Dr. Thompson
//Description: Contains functions for Homework 4 program

#include "su0060HW4.h"
using namespace std;

void printInfo () { // prints introductory info

cout << "+------------------------------------------------------------+"<< endl;
cout<<  "|               Computer Science and Engineering             |"<< endl;
cout << "|                CSCE 1030 - Computer Science I              |" << endl;
cout << "| Smrithi Upadhyayula  su0060  smrithiupadhyayula@my.unt.edu |" << endl;
cout << "+------------------------------------------------------------+" << endl;
}

void gameIntro () { //prints intro to the game

cout << "       Welcome to Anthony's Battle!        " << endl;
cout << endl;
cout << "-----------------------------------------------------" << endl;
cout << "Anthony the ant has decided that he wants to take over" << endl;
cout << "all the adjacent ant colonies with his army of ants   " << endl;
cout << "from colony 'A'. To do this, Anthony's army will att-" << endl;
cout << "empt to capture ants from columns 'B' through 'J' with"<< endl;
cout << "at least 1 ant remaining when the column 'J' ant colony" << endl;
cout << "is found. Each column's ant colony is identified with a" << endl;
cout << "0 in one of the rows for that column, while patrols are" << endl;
cout << "represented by integers between 1 and 10 for the number" << endl;
cout << "of ants in that particular patrol. On the way to column" << endl;
cout << "'J' if Anthony's army encounters a patrol, the number in" << endl;
cout << "the patrol is subtracted from Anthony's army total. Once" << endl;
cout << "his army finds the colony, however, any patrols not confr-" << endl;
cout << "onted will be added to his army total. If Anthony makes" << endl;
cout << "really good decisions, then he can take over all of the" << endl;
cout << "adjacent ant colonies; otherwise, his army will be" << endl;
cout << "defeated!" << endl;
cout << "-----------------------------------------------------" << endl;
}

void initializeArray (int** array, int& numAnts) //initializes array and updates number of ants
{
	srand (time (NULL));
	int colonyLoc = (rand () % 10); // where the colony is
	for (int i = 0; i < SIZE; i++) //iterate through columns
	{
		for (int j = 0; j < SIZE; j++) //through rows
		{
			if (j == colonyLoc)
				array [j][i] = 0;
			else 
				array [j][i] = (rand() % 10) + 1;
		}
		colonyLoc = (rand() % 10); //update colony location
	}
	numAnts = 0;
	for (int i = 0; i < SIZE; i++)
	{
	numAnts += array [0][i]; //sum number of ants in column 0
	}
}

void displayArray (int** array, int currentColumn) //displays array
{
	cout << "  A \t B \t C \t D \t E \t F \t G \t H \t I \t J  " << endl; //column headers
	cout <<
"+--------------------------------------------------------------------------------+"
	<< endl;
	for (int i = 0; i < SIZE; i++)
	{
	cout << i << "| ";
		for (int j = 0; j < SIZE; j++)
		{	
			if (array [i][j] < 0)//if location already visited, mark it as "XX"
				cout << "XX" << "\t";
			else if (j < currentColumn)
			{
				cout << array[i][j] << "\t"; //if before current column, display the value
			}
			else 
			{
			cout << "**\t"; //if in/after current column, display "**"
			}
		}
		cout << " |" << endl;
	}
	cout <<
	"+--------------------------------------------------------------------------------+"
	<< endl;
}

bool isFound (int currentRow,int currentColumn,int& numAnts,int** array) //determine whether colony
//has been found at current location. 
{
	if (array [currentRow][currentColumn] == 0) //colony found
{
	return true;
}
	else if (array [currentRow][currentColumn] < 0) //already visited this location
	{
	cout << "Ant patrol at this location has already been removed." << endl;
	return false;
	}
	else 
	{
	numAnts-= array [currentRow][currentColumn]; //didn't find colony. Subtract patrol
	cout << "Anthony's army suffered casualties and has " << numAnts;
	cout << " ants remaining." << endl;
	array [currentRow][currentColumn] = -1; //set to negative value so we know if we've visited
	//before 
	return false;
	}
}

void deleteArray (int** array) //delete the dynamic array at the end of the program
{
	  for (int i = 0; i < SIZE; i++)
	  {
		delete [] array[i];
	}
	delete [] array;

}
