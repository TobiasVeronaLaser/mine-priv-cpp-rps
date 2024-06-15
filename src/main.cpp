/** Rock-Paper-Scissors Console-Version Prototype-Version
 * Author: Tobias Laser
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "generic.h"

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
    if(p1 - 1 == (p2 + 1) % 3){
        return 0;
    }
    if((p1 + 1) % 3 == p2 - 1){
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

#ifdef MODULAR
    #ifdef __linux__
        #def CLEAR() printf("\e[1;1H\e[2J")
    #else 
        #def CLEAR()
    #endif

    void menu(){
        do{
            printf("\nMenu\n");
            printf("\nChoose your game mode or exit:\n0: exit\n1: single-player\n2: multiplayer\nYour pick: ");
        }while(1 != scanf("%d", &gameMode) || 0 > gameMode || gameMode > 2);
    }

    int main(void){
        CLEAR();
        printf("Welcome to Rock-Paper-Scissors Console-Version Modular-Version\n");
        bool isPlaying = true;
    }

#endif

#ifdef PROTOTYPE
    int main(void){
        #ifdef __linux__
            printf("\e[1;1H\e[2J");
        #endif
        printf("Welcome to Rock-Paper-Scissors Console-Version Prototype-Version\n");
        bool isPlaying = true;
        do{
            int gameMode = -1;
            do{
                printf("\nMenu\n");
                printf("\nChoose your game mode or exit:\n0: exit\n1: single-player\n2: multiplayer\nYour pick: ");
            }while(1 != scanf("%d", &gameMode) || 0 > gameMode || gameMode > 2);
            #ifdef __linux__
                printf("\e[1;1H\e[2J");
            #endif
            switch(gameMode){
                case 0: 
                    isPlaying = false;
                    printf("Till next time!\n");
                    break;
                case 1: 
                    do{
                        int choice = -1;
                        do{
                            printf("Single-player!\n");
                            printf("\nPlayer choose your hand or exit:\n0: exit\n1: Rock\n2: Paper\n3: Scissors\nYour pick: ");
                        }while(1 != scanf("%d", &choice) || 0 > choice || choice > 3);
                        #ifdef __linux__
                            printf("\e[1;1H\e[2J");
                        #endif
                        if(0 == choice){
                            break;
                        }
                        srand(time(0));
                        Hand p = getHand(choice), com = getHand(3 * (rand() / (double)(RAND_MAX))+ 1);
                        printf("Single-player!\n");
                        printf("\nPlayer: %s\tCOM: %s\n\n", getName(p).c_str(), getName(com).c_str());
                        switch (check(p, com)){
                            case 2: 
                                printf("You Win!");
                                break;
                            case 1:
                                printf("A draw.");
                                break;
                            case 0: 
                                printf("You lose!");
                                break;
                            default:
                                printf("Something unexpected happened!\n");
                                return EXIT_FAILURE;
                        }
                        printf("\n\nPlease enter something to proceed.");
                        char *dump;
                        while(1 != scanf("%s", &dump));
                        #ifdef __linux__
                            printf("\e[1;1H\e[2J");
                        #endif
                    }while(true);
                    break;
                case 2:
                    do{
                        int choice = -1;
                        do{
                            printf("Multiplayer!\n");
                            printf("\nPlayer 1 choose your hand or exit:\n0: exit\n1: Rock\n2: Paper\n3: Scissors\nYour pick: ");
                        }while(1 != scanf("%d", &choice) || 0 > choice || choice > 3);
                        #ifdef __linux__
                            printf("\e[1;1H\e[2J");
                        #endif
                        if(0 == choice){
                            break;
                        }
                        Hand p1 = getHand(choice);
                        #ifdef __linux__
                            printf("\e[1;1H\e[2J");
                        #endif
                        choice = -1;
                        do{
                            printf("Multiplayer!\n");
                            printf("\nPlayer 2 choose your hand or exit:\n0: exit\n1: Rock\n2: Paper\n3: Scissors\nYour pick: ");
                        }while(1 != scanf("%d", &choice) || 0 > choice || choice > 3);
                        #ifdef __linux__
                            printf("\e[1;1H\e[2J");
                        #endif
                        if(0 == choice){
                            break;
                        }
                        Hand p2 = getHand(choice);
                        printf("Multiplayer!\n");
                        printf("\nPlayer 1: %s\tPlayer 2: %s\n\n", getName(p1).c_str(), getName(p2).c_str());
                        switch (check(p1, p2)){
                            case 2: 
                                printf("Player 1 wins!");
                                break;
                            case 1:
                                printf("A draw.");
                                break;
                            case 0: 
                                printf("Player 2 wins!");
                                break;
                            default:
                                printf("Something unexpected happened!\n");
                                return EXIT_FAILURE;
                        }
                        printf("\n\nPlease enter something to proceed.");
                        char *dump;
                        while(1 != scanf("%s", &dump));
                        #ifdef __linux__
                            printf("\e[1;1H\e[2J");
                        #endif
                    }while(true);
                    break;
                default: 
                    isPlaying = false;
                    printf("Something unexpected happened!\n");
                    return EXIT_FAILURE;
            }
        }while(isPlaying);
        return EXIT_SUCCESS;
    }
#endif