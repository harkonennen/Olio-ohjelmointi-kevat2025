#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int game(int);

int main()
{
    int scaleNumber;
    cout << "give number" << endl;
    cin >> scaleNumber;
    int tries = game(scaleNumber);
    cout << "number of tries:" << tries << endl;
    return 0;
}

int game(int maxnum){
    srand(time(0));
    int randomNum = rand()%maxnum+1;
    int userNum;
    int guessAmount =0;

    while(randomNum != userNum){
        cout << "guess a number between 1 -" << maxnum << endl;
        cin >> userNum;
        guessAmount++;

        if (randomNum == userNum){
            cout << "equal to random number" << endl;
            cout << "you win" << endl;
        } else if (randomNum > userNum){
            cout << "smaller than random number, try again" << endl;
        } else {
            cout << "bigger than randon number, try again" << endl;
        }
    }
    return guessAmount;
}
