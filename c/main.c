/*

	Authors: Evan Kasky, Chandler Mccarty, Gregory Aguila
	Project Title: Exam Two: Crossword Puzzle
	Date Created: 5 May 2020
	Due Date: 14 May 2020
	Description: Creates a crossword puzzle based on the words the user enteres into the program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Evan's Functions
#include "evansFunctions.h"

// Chandler's Funcitons
#include "chandlersFunctions.h"

//Gregory's Functions
#include "gregorysFunctions.h"


#define PAUSE system("pause")
#define CLEAR system("cls")
#define FLUSH while(getchar() != '\n');

#define ROWS 20
#define COLS 20
#define AMT_OF_WORDS 16
#define LEN_OF_WORDS 10
#define TITLE_LEN 100


int main() {

	FILE* puzzleFile;
	char title[TITLE_LEN] = "Name Puzzle Search";
	char words[AMT_OF_WORDS][LEN_OF_WORDS] = {"Bob", "Zach", "Paul", "Jack", "Pam", "Harry", "Patrick", "Alex", "Dan", "William", "John", "Ryan", "Tyler", "Robert", "Thomas", "Micheal"};
	char puzzle[ROWS][COLS];
	int direction = 0;

	srand((unsigned)time(NULL));

	//Creates File For Puzzle
	createFile(&puzzleFile);

	//Get title

	//Get words

	// Words to upper
	for (int i = 0; i < AMT_OF_WORDS; i++) {
		makeUpper(words[i]);
	} // end for
	
	//Sort Words
	sortWords(words);

	//Initializes Puzzle with dots
	fillPuzzleDots(puzzle);

	for (int i = 0; i < AMT_OF_WORDS; i++) {

		//genRandNum(&direction);
		direction = 4;

		switch (direction) {

		case 0:
			
			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			//placeWordDiagnalFR(puzzle, words[i]);
			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;

		} // end switch

	} // end for

	//Fills Puzzle with random letters
//	fillPuzzleRandom(puzzle); // comment out to test word placment
	
	//Displays Puzzle on console
	displayPuzzle(title, puzzle, words);

	//Write Puzzle to File
	writePuzzleToFile(&puzzleFile, title, puzzle, words);

	PAUSE;
	return 0;

} // end main

