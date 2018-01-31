#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;


void printIntro()
{
    cout << "Welcome to the dice game Pig!" << endl << "The objective is to be first to score 100 points." << endl << endl;
    return;
}

int humanTurn(string name, int score)
{
    int s = score;
    char yesno = 'y';
    int sum = -1;
    
    do
    {
        int roll = (rand()%6)+1;
        sum += roll;
        
        if(roll !=1)
        {
            cout << name << endl;
            cout << "You rolled a " << roll << endl;
            s = roll + s;
            
            cout << "Your score: " << s << endl;
            
            if(s < WINNING_SCORE)
            {
                cout << "Do you want to roll again? (y/n): ";
                cin >> yesno;
                cout << endl;
                
            }
            else
            {
            break;
            }
        }
        else if(roll == 1)
        {
            cout << name << endl;
            cout << "You rolled a 1 (PIG!)" << endl;
            cout << "Your turn is over" << endl;
            s -= sum;
            cout << "Your score: " << s << endl;
            yesno = 'n';
            cout << endl;
        }
        }while(yesno == 'y');
    return s;
    
}

int main() {
    srand(4444);

    // setup and initialize variables
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;

    printIntro();

    cout << "Player 1 - Enter your name: ";
    cin >> player1name;
    cout << endl;
    cout << "Player 2 - Enter your name: ";
    cin >> player2name;
    cout << endl;



    //play game
    while (player1score < WINNING_SCORE && player2score < WINNING_SCORE) 
    {

        //player 1's turn or player 2's turn
        if (turn == PLAYER1) {
            player1score = humanTurn(player1name, player1score);
        }
        else {
            player2score = humanTurn(player2name, player2score);
        }

    
    
    if(turn == PLAYER1)
        turn = PLAYER2;
    else if (turn == PLAYER2)
        turn = PLAYER1;
        
    }
    if(player1score >= WINNING_SCORE)
    {
         cout << endl << player1name << " wins!" << endl;
    }
    else if(player2score >= WINNING_SCORE)
    {
         cout << endl<< player2name << " wins!" << endl;
    }

    return 0;
}