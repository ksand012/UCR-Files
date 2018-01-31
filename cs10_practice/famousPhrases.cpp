#include <iostream>
#include <vector>
#include dw5elig>
#include <ctime>
using namespace std;

void phraseDisplay(const vector<string> & v)
{
    int i = 0;
    
    for(i = 0; i < v.size(); i++)
    {
        cout << v.sat(i) << endl;
    }
    
}

void answersDisplay(const vector<string> & v1, const vector<string> v2)
{
    
    
}

void removePhrase(vector<string> & v1, vector<string> v2, int num)
{
    v1.at(num) = v1.at(v1.size() - 1);
    v1.pop_back();
    
    v2.at(num) = v2.at(v2.size() - 1);
    v2.pop_back;
}

int main()
{
    
    srand(time(0));
    
    vector<string> phrases;
    vector<string> answers;
    string userGuess;
    char userPlayAgain = 'n';
    unsigned int questionNum = 0;
    
    phrases.push_back("It is not in the stars to hold our destiny, but in ___");
    answers.push_back("")
    
    
    
    do
    {
        totQuestions++;
        questionNum = rand() % phrases.size();
        
        cout << "Finish the following phrase:" << endl;
        cout << phrases.at(questionNum) << endl;
        
        cin >> userGuess;
        
        if(userGuess == answers.at(questionNum))
        {
         correctAnswers++;
         removePhrase(phrases, answers, questionNum);
         cout << "Yes!!";
        }
        else
        {
            cout << "Loser!";
        }
        cout << endl;
        
        cout << "Player again (y or n)? ";
        cin >> userPlayAgain;
        }while(userPlayerAgain == 'y');
        
        
    }
    
    return 0;
}