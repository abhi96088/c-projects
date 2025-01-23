// Number guessing game

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	int random, guess;
	int no_of_guess = 0;
	
	srand(time(NULL));
	random = rand() % 100 + 1;
	
	printf("\n********************************************************\n");
	printf("\tWELCOME TO THE NUMBER GUESSING GAME");
	printf("\n********************************************************\n");
	
	do{
		printf("\nGuess a number between 1 to 100 : ");
		scanf("%d", &guess);
		no_of_guess++;
		
		if(guess < random){
			printf("No:( \nGuess a larger number!\n");
		}else if(guess > random){
			printf("No:( \nGuess a smaller number!\n");
		}else{
			printf("\n\nCongrats :) You guessed it right in %d attempts !!", no_of_guess);
			printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
		}
		
	}while(guess != random);
	
	
	printf("\nBye Bye!  Thanks for Playing...");
	printf("\nDeveloped by : Abhi Manyu");
	printf("\n==========================");
	
return 0;
}
