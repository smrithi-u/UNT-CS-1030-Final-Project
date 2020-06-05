//Author: Smrithi Upadhyayula
//Date: 12/3/2019
//Instructor: Dr. Thompson
//Description: Header file for Homework 4

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstring>

void printInfo ();
void gameIntro ();
void initializeArray (int** array, int& numAnts);
const int SIZE = 10; // for the size of the array
void displayArray (int** array, int currentColumn);
bool isFound (int currentRow, int currentColumn, int& numAnts, int** array);
void deleteArray (int** array);
