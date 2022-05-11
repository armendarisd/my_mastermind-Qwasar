#include <stdio.h>
#include <unistd.h>

/*These are the variables that are going to use in the program*/
   int attempts;
   int arraySecretCode[4];
   int checkSecretCode = 0;
   int arrayAttempt[4];
   int checkArrayAttempt = 0;
   int gameWon = 0;


/*This function checks if the colors are in the right position in the array*/
int checkPlaces(int* attempt, int* pickedColors){
    int isInThePlace = 0;
    for(int i = 0; i < 4; i++){
        if(attempt[i] == pickedColors[i]){
            isInThePlace++;
        }
    }
    return isInThePlace;
}

/*This function checks if the colors are in the combination but not in the position*/
int checkArray(int* attempt, int* pickedColors){
    int isInTheArray = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(attempt[i] == pickedColors[j]){
                if(i != j){
                    isInTheArray++;
                }
            }
        }
    }
    return isInTheArray;
}

/*This function checks the decisition of the game/ Finish the game, try again, invalid Input*/
void checkGameDecision(int* attempt, int* pickedColors){

    if((checkPlaces(attempt, pickedColors) == 4) ){
        printf("Congratz, You did it");
        gameWon = 1;
    }
    else{
        printf("Well placed pieces: %d\n", checkPlaces(attempt, pickedColors));
        printf("Misplaced pieces: %d\n", checkArray(attempt, pickedColors));
        printf("Try it again\n");
    } 
}


int main( int argc, char *argv[])
{   
 /*PART I*/
 /*This is the welcome of the game*/
   printf("Welcome to Mastermind, Will you find the secret code?\n");
   printf("-----------------------------------------------------\n");
   printf("Type the number of attemps\n");
   scanf("%d", &attempts);
   printf("-----------------------------------------------------\n");
  
  /*PART II*/
  /*This while Loop receives the secret code of the game*/
   while(checkSecretCode != 4){
        printf("Type the secret code\n");
        checkSecretCode = scanf("%d %d %d %d", &arraySecretCode[0], &arraySecretCode[1], &arraySecretCode[2], &arraySecretCode[3]);
        if(checkSecretCode < 4){
               printf("Wrong input, Try again\n");
        }
   }
   
   /*PART III*/
   /*This part of the code receives the attempt code of the round*/
   for(int i = 0; i < attempts; i++){
       printf("Round %d\n", i);
       while(checkArrayAttempt != 4){
           printf("Type your attempt\n");
           checkArrayAttempt = scanf("%d %d %d %d", &arrayAttempt[0], &arrayAttempt[1], &arrayAttempt[2], &arrayAttempt[3]);
           if(checkArrayAttempt < 4){
               printf("Wrong input, Try again\n");
           }
       }
       checkArrayAttempt = 0;

    /*PART IV*/
    /*This part of the code take the decision of the round*/
       checkGameDecision(arrayAttempt, arraySecretCode);
       if(gameWon == 1){
           break;
       }
   }
   if(gameWon == 0){
       printf("Game Over");
   }
   
   return 0;
}