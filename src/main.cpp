#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum Hand {ROCK, PAPER, SCISSORS};
enum GameMode {SINGLEPLAYER, MULTIPLAYER};

class Player{
    private:
        string name;
        Hand hand;
    
    public:

    // Constructor
    
    Player(){
        setName("COM");
        setHand(undefined);
    }

    Player(string name){
        setName(name);
        setHand((Hand)UNDEFINED);
    }

    // Setter

    void setName(string name){
        this->name = name;
    }

    void setHand(Hand hand){
        this->hand = hand;
    }

    // Getter

    string getName(){
        return name;
    }

    Hand getHand(){
        return hand;
    }

};

class Game{
    private:
        static const int playerCount = 2;
        static Player players[playerCount];
        static Game *instance;
        Game(){}

    public:
        Game *getInstance(){
            if(!instance){
                this->instance = new Game();
            }
            return this->instance;
        }

    bool checkBoundaries(int index){
        return 0 <= index && index < playerCount;
    }

    bool setName(int index, string name){
        if(checkBoundaries(index)){
            players[index].setName(name);
        }
    }

    bool setHand(int index, Hand hand){
        if(checkBoundaries(index)){
            players[index].setHand(hand);
        }
    }

    int checkWinner(){
        Hand h1 = players[0].getHand(), h2 = players[1].getHand();
        if(h1 == ()UNDEFINED || h2 == (Hand)UNDEFINED){

        }
        if(h1 == h2){
            return 2;
        }

        return -1;
    }

};

int main(void){
    return EXIT_SUCCESS;
}