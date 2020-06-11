//Gregory's Functions

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
//prototype functions
void getTitle();
void getWords(char words[][LEN_OF_WORDS], char title[]);
void placeWordFDown(char puzzle[][COLS], char words[]);
void placeWordBDown(char puzzle[][COLS],char words[]);

//functions
void getTitle(){
		char title[TITLE_LEN];
		printf("\t\t*****************Please enter a title for the puzzle***************");
		printf("Title...:");
		scanf("%[^\n]",title);FLUSH;
		CLS;
	}
//====================================================================================//
void getWords(char words[][LEN_OF_WORDS], char title[]){
	char chosenWord[AMT_OF_WORDS];
		for(int = 0,i < AMT_OF_WORDS;i++){
			do{
				place = 'N';
				printf("Enter word %d of %d: ",i+1,LEN_OF_WORDS);
				scanf("%s", &chosenWord);
				if(strlen(chosenWord)>LEN_OF_WORDS){
					printf("Too many letters; enter no more than %d letters.\n",LEN_OF_WORDS);
					PAUSE;
					place = 'Y';
					strcpy(chosenWord,"");
				}//end if
			}while(place =='Y');
			printf("\n\t\t\t");
			makeUpper(chosenWord);
			strcpy(words[i], chosenWord);
		}//end for loop
		CLS;
} //end getWords
//====================================================================================//
void placeWordFDown(char puzzle[][COLS],char word[]){
	char place = 'N';
	int x = 0;
	int y = 0;
	int i,j,k;
	int len;
	
	do{
		place 'Y';
		x = rand() % ROWS;
		y = rand() % COLS;
		k = 0;
		len = strlen(word) + x;
		if(len > COLS){
			place = 'N';
		} else {
			for (i = x; i < len; i++){
				if(!(puzzle[i][y]) == '.' || puzzle[i][y] == word[k]))
					place = 'N';
				else
					k++;	
			} //end for
		} //end if/else statement
	}while(place == 'N');
	k = 0;
	for(i = x;i<len;i++){
		puzzle[i][y] = word[k];
		k++;
	}//end for loop 
			
}//end placeWordFDown
//====================================================================================//
void placeWordBDown(char puzzle[][COLS],char word[]){
	char place = 'N';
	int x = 0;
	int y = 0;
	int i,j,k;
	int len;
	do{
		place 'Y';
		x = rand() % ROWS;
		y = rand() % COLS;
		k = 0;
		len = strlen(word) + x;
		if(len > COLS){
			place = 'N';
		}else{
			for (i = x; i < len; i++){
				if(!(puzzle[i][y]) == '.' || puzzle[i][y] == word[k]))
					place = 'N';
				else
					k++;	
			} //end for
		} //end if/else statement
	}while(place == 'N');
	k = 0;
	k = strlen(word) - 1;
	for(i = x; i < len; i++){
		puzzle[i][y] = word[k];
		k--;
	}//end for loop 
	
}//end placeWordBDown




