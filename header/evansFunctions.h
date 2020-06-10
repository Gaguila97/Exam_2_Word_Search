//Evan Kasky's Functions 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define PAUSE system("pause")
#define CLEAR system("cls")
#define FLUSH while(getchar() != '\n');

#define ROWS 20
#define COLS 20
#define AMT_OF_WORDS 16
#define LEN_OF_WORDS 10
#define TITLE_LEN 100

// Prototype Functions

void createFile(FILE* puzzleFile);
void displayPuzzle(char title[], char puzzle[][COLS], char words[][LEN_OF_WORDS]);
void genRandNum(int* direction);
void fillPuzzleDots(char puzzle[][COLS]);
void fillPuzzleRandom(char puzzle[][COLS]);
void placeWordDiagnalFR(char puzzle[][COLS], char word[]);
void writePuzzleToFile(FILE* puzzleFile, char title[], char puzzle[][COLS], char words[][LEN_OF_WORDS]);



//Write Functions


void createFile(FILE* puzzleFile) {

	puzzleFile = fopen("puzzle.txt", "w");
	
	if (puzzleFile == NULL) {

		printf("Could not write to storage location...\n");
		PAUSE;
		exit(-1);

	} // end if

	fclose(puzzleFile);

} // end createFile



void displayPuzzle(char title[], char puzzle[][COLS], char words[][LEN_OF_WORDS]) {

	int k = 0;

	printf("\t%s\n\n\t", title);

	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {

			printf("%c ", puzzle[i][j]);

		} // end for

		printf("\n\t");

	} // end for

	printf("\n");

	printf("\tWord Bank:\n");

	for (int i = 0; i < AMT_OF_WORDS/4; i++) {

		printf("\t");

		for (int j = 0; j < 4; j++) {

			printf("%2i.%10s\t", k+1,words[k]);
			k++;

		} // end for

		printf("\n");

	} // end for

} // end displayPuzzle



void genRandNum(int* direction) {

	*direction = (rand() % 8) + 1;

} // end genRandNum



void fillPuzzleDots(char puzzle[][COLS]) {

	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {

			puzzle[i][j] = '.';

		} // end for

	} // end for

} // end fillPuzzleDots



void fillPuzzleRandom(char puzzle[][COLS]) {

	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {

			if (puzzle[i][j] == '.') {

				puzzle[i][j] = 'A' + (rand() % 26);
			} // end if

		} // end for

	} // end for

} // end fillPuzzleRandom



void placeWordDiagnalFR(char puzzle[][COLS], char word[]) {

	char place = 'N';
	int x = 0;
	int y = 0;
	int k = 0;
	int len = strlen(word);


	do {

		place = 'Y';
		x = rand() % ROWS;
		y = rand() % COLS;

		if (len + x > ROWS || len + y > COLS) {
			place = 'N';
		}

		for (int i = 0; i < len; i++) {

			if (puzzle[x][y] != '.' || puzzle[x][y] == word[i]) {
				place = 'N';
			}

		}

	} while (place == 'N');

	for (int i = 0; i < len; i++) {

		puzzle[x][y] = word[i];
		x++;
		y++;
	} 

} // end placeWordDiagnalFR


void writePuzzleToFile(FILE* puzzleFile, char title[], char puzzle[][COLS], char words[][LEN_OF_WORDS]) {

	int k = 0;

	puzzleFile = fopen("puzzle.txt", "w");

	if (puzzleFile == NULL) {

		printf("Could not write to storage location...\n");
		PAUSE;
		exit(-1);

	} // end if

	fprintf(puzzleFile, "%s\n\n", title);


	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {

			fprintf(puzzleFile, "%c ", puzzle[i][j]);

		} // end for

		fprintf(puzzleFile, "\n");

	} // end for

	fprintf(puzzleFile, "\n");

	fprintf(puzzleFile, "Word Bank:\n");

	for (int i = 0; i < AMT_OF_WORDS / 4; i++) {



		for (int j = 0; j < 4; j++) {

			fprintf(puzzleFile, "%2i.%10s\t", k + 1, words[k]);
			k++;

		} // end for

		fprintf(puzzleFile, "\n");

	} // end for

	fclose(puzzleFile);
	
} // end writePuzzleToFile


