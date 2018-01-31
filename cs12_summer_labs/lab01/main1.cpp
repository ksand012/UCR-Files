#include <iostream>
#include <vector>
using namespace std;

void outputRoster(const vector<int> &, const vector<int> &);
void addPlayer(vector<int> &, vector<int> &);
void removePlayer(vector<int> &, vector<int> &);
void updatePlayerRating(const vector<int> &, vector<int> &);
void outputPlayersAboveRating(const vector<int> &, const vector<int> &);


int main()
{
    vector<int> jNum(5);
    vector<int> jRat(5);
    char loopInput = 'a';
    int input = 0;
    unsigned i = 0;
   for(i = 0; i < 5; i++)
   {
       cout << "Enter player " << i+1 << "'s jersey number:" << endl;
       cin >> input;
       jNum.at(i) = input;
       cout << "Enter player " << i+1 << "'s rating:" << endl;
       cin >> input;
       jRat.at(i) = input;
       cout << endl;
   }
   
   outputRoster(jNum, jRat);
   
   while(loopInput != 'q' || loopInput != 'Q')
   {
    cout << endl << "MENU" << endl << "a - Add player" << endl << 
    "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
    cin >> loopInput;
    if(loopInput == 'a' || loopInput == 'A')
    addPlayer(jNum, jRat);
    else if(loopInput == 'd' || loopInput == 'D')
    removePlayer(jNum, jRat);
    else if(loopInput == 'u' || loopInput == 'U')
    updatePlayerRating(jNum, jRat);
    else if(loopInput == 'r' || loopInput == 'R')
    outputPlayersAboveRating(jNum, jRat);
    else if(loopInput == 'o' || loopInput == 'O')
    outputRoster(jNum, jRat);
    else if(loopInput == 'q' || loopInput == 'Q')
    break;
    
   }
   

   return 0;
}

void outputRoster(const vector<int> &jNum, const vector<int> &jRat)
{
    cout << "ROSTER" << endl;
    for(int i = 0; i < jNum.size(); i++)
    {
        cout << "Player " << i+1 << " -- Jersey number: " << jNum.at(i) << ", Rating: " << jRat.at(i) << endl;
    }
    
}

void addPlayer(vector<int> &jNum, vector<int> &jRat)
{
    int temp = 0;
    cout << "Enter another player's jersey number:" << endl;
    cin >> temp;
    jNum.push_back(temp);
    cout << "Enter another player's rating:" << endl;
    cin >> temp;
    jRat.push_back(temp);
    
}
void removePlayer(vector<int> &jNum, vector<int> &jRat)
{
    int temp = 0;
    cout << "Enter a jersey number: " << endl;
    cin >> temp;
    
    int player = 0;
    int place = 0;
    int i = 0;
    int test = 0;
    int test2 = 0;
    for(i = 0; i < jNum.size(); i++)
    {
        if(jNum.at(i) == temp)
        {
        place = i;
        i = jNum.size();
        }
    }
    
    if(place == jNum.size()-1)
    {
        jNum.pop_back();
        jRat.pop_back();
    }
    
    else
    {
     for(i = place; i < jNum.size()-1; i++)
     {
         test = jNum.at(i+1);
         jNum.at(i+1) = jNum.at(i);
         jNum.at(i) = test;
         test2 = jRat.at(i+1);
         jRat.at(i+1) = jRat.at(i);
         jRat.at(i) = test2;
     }
     
     jNum.pop_back();
     jRat.pop_back();
        
        
    }
    
    
}
void updatePlayerRating(const vector<int> & jNum, vector<int> & jRat)
{
    int temp = 0;
    int score = 0;
    cout << "Enter a jersey number: " << endl;
    cin >> temp;
    cout << "Enter a new rating for player: " << endl;
    cin >> score;
    int i = 0;
    int found = 0;
    for(i = 0; i < jNum.size(); i++)
    {
        if(temp == jNum.at(i))
        {
            found = i;
            i = jNum.size();
        }
    }
    
    jRat.at(found) = score;
    
    
    
}
void outputPlayersAboveRating(const vector<int> & jNum, const vector<int> & jRat)
{
    int temp = 0;
    cout << "Enter a rating: " << endl;
    cin >> temp;
    cout << endl;
    
    cout << "ABOVE " << temp << endl;
    int i = 0;
    for(i = 0; i < jNum.size(); i++)
    {
        if(jRat.at(i) > temp)
        {
            cout << "Player " << i + 1 << " -- Jersey number: " << jNum.at(i) << ", Rating: " << jRat.at(i) << endl;
        }
    }
    
}