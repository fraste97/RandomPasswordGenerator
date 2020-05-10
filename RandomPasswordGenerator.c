#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 12 //password's length is defined here

//returns a random printable character except SPACE and DELETE 
char randomChar(){
	int r = rand() % 94 + 33;
	return (char) r;
}

//returns a random password that has to contain both symbols, uppercase letters, lower case letters and numbers 
char* pswGen(char *psw){
	int i, letter, capLetter, number, symbol;
	char randChar;
	
	do{

		letter = 0, capLetter = 0, number = 0, symbol = 0;

		for(i = 0; i<LEN; i++){
			randChar = randomChar();

			if(randChar >= 97 & randChar <= 122) 
				letter++;
			else if (randChar >= 48 & randChar <= 57)
				number++;
			else if (randChar >= 65 & randChar <= 90)
				capLetter++;
			else symbol++;
		
			psw[i] = randChar;
		}
	}while(letter == 0 | capLetter == 0 | number == 0 | symbol == 0);

	return psw;
}

int main(void) {
  srand(time(NULL));
  
  char psw[LEN];
  printf("You random password is: %s\n", pswGen(psw));

  system("pause");
  return 0;
}