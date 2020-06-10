//Chandler Mccarty's Functions

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
void sortWords(char words[][LEN_OF_WORDS]);
void makeUpper(char lowerWord[]);






//Write Functions

void makeUpper(char lowerWord[]) {
    int i = 0;
    while (lowerWord[i] != '\0') {
        lowerWord[i] = toupper(lowerWord[i]);
        i++;
    }
}//Should make all numbers uppper case



void sortWords(char words[][LEN_OF_WORDS]) {

	char tempWord[LEN_OF_WORDS] = { '\0' };

	for (int i = 0; i < AMT_OF_WORDS; i++) {
		for (int j = i + 1; j < AMT_OF_WORDS; j++) {

			if (strcmp(words[i], words[j]) > 0) {

				strcpy(tempWord, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], tempWord);

			} // end if

		} // end for

	} // end for

} // end sortWords

