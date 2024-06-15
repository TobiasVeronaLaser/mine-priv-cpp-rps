/** Rock-Paper-Scissors Console-Version Prototype-Version
 * Author: Tobias Laser
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

enum Hand {UNDEFINED, ROCK, PAPER, SCISSORS};

/**
 * returns ...
 *  ... 2:  p1 win
 *  ... 1:  draw
 *  ... 0:  p1 lose
 *  ... -1: Unexpected input
*/
int check(Hand p1, Hand p2){
    if(p1 == UNDEFINED || p2 == UNDEFINED){
        return -1;
    }
    if(p1 == p2){
        return 1;
    }
    if(p1 + 1 % 3 == p2){
        return 0;
    }
    if(p1 == p2 + 1 % 3){
        return 2;
    }
    return -1;

}

Hand getHand(int value){
    switch(value){
        case 1: 
            return ROCK;
        case 2:
            return PAPER;
        case 3:
            return SCISSORS;
        case 0:
        default: 
            return UNDEFINED;
    }
}

string getName(Hand value){
    switch(value){
        case ROCK:
            return "rock";
        case PAPER:
            return "paper";
        case SCISSORS:
            return "scissors";
        case UNDEFINED:
        default:
            return "undefined";
    }
}

int main(void){
    printf("Welcome to Rock-Paper-Scissors Console-Version Prototype-Version\n");
    bool isPlaying = true;
    do{
        int gameMode = -1;
        do{
            printf("\nChoose your game mode or exit:\n0:\texit\n1:\tsingle-player\n2:\tmultiplayer\nYour pick:\t");

        }while(1 != scanf("%d", &gameMode) || 0 > gameMode || gameMode > 2);
            printf("\n");
            switch(gameMode){
                case 0: 
                    isPlaying = false;
                    printf("Till next time!\n");
                    break;
                case 1: 
                    printf("Single-player!\n");
                    do{
                        int choice = -1;
                        do{
                            printf("Player choose your hand or exit:\n0:\texit\n1:\tRock\n2:\tPaper\n3:\tScissors\n");
                        }while(1 != scanf("%d", &choice) || 0 > choice || choice > 3);
                        if(0 == choice){
                            break;
                        }
                        srand(time(0));
                        double value = rand() / (double)(RAND_MAX + 1);
                        printf("\n%lf\n", value);
                        double endvalue = 3 * value;
                        printf("\n%lf\n", endvalue);
                        Hand p = getHand(choice), com = getHand(endvalue);
                        printf("Player:\t%s\tCOM:\t%s\n", getName(p), getName(com));
                        switch (check(p, com)){
                            case 2: 
                                printf("You Win!\n");
                                break;
                            case 1:
                                printf("A draw.\n");
                                break;
                            case 0: 
                                printf("You lose!\n");
                                break;
                            default:
                                printf("Something unexpected happened!\n");
                                return EXIT_FAILURE;
                        }
                    }while(true);
                    break;
                case 2:
                    printf("Multiplayer!\n");
                    break;
                default: 
                    isPlaying = false;
                    printf("Something unexpected happened!\n");
                    return EXIT_FAILURE;
        }
    }while(isPlaying);
    return EXIT_SUCCESS;
}