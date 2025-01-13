#include "game.h"


game::game(int n) : maxNumber(n), numOfGuesses(0), playerGuess(0) {
    srand(time(NULL));
    cout<<"GAME CONSTRUCTOR: Game's max limit set to "<<maxNumber<<endl;
    play();
}

game::~game()
{
    cout<<"GAME DESTRUCTOR"<<endl;
}

void game::play()
{
    //Randomize the number to guess

    randomNumber = rand()%maxNumber+1;

    //Game loop
    while(randomNumber != playerGuess){
        cout<<"Guess between 1-"<<maxNumber<<endl;
        cin>>playerGuess;
        numOfGuesses++;

        if(randomNumber == playerGuess){
            cout<<"Correct Guess!"<<endl;

        } else if(randomNumber > playerGuess){
            cout<<"Guess was too small."<<endl;
        } else{
            cout<<"Guess was too big."<<endl;
        }
    }
    printGameResult();
}

void game::printGameResult()
{
    cout<<"You guessed the right number: "<<randomNumber<<
    " with "<<numOfGuesses<<(numOfGuesses == 1 ? " try!" : " tries!")<<endl;
}
