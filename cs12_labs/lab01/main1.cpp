#include <iostream>
#include <vector>
using namespace std;

void outputRoster(const vector<int>& jerseyNum, const vector<int>& ratingNum)
{
    int i = 0;
    cout << "ROSTER" << endl;
   for(i = 0; i < jerseyNum.size(); i++)
   {
        cout << "Player " << i+1 << " -- Jersey number: " << jerseyNum.at(i) <<  ", Rating: " << ratingNum.at(i) << endl;
   }
   cout << endl;
}
void addPlayer(vector<int>& jerseyNum, vector<int>& ratingNum)
{
        int temp1 = 0, temp2 = 0;
        cout << "Enter another player's jersey number:" << endl;
       cin >> temp1;
       cout << "Enter another player's rating:" << endl;
       cin >> temp2;
       cout << endl;
       
       jerseyNum.push_back(temp1);
       ratingNum.push_back(temp2);
    
}
void removePlayer(vector<int>& jerseyNum, vector<int>& ratingNum)
{
    int temp1 = 0;
    cout << "Enter a jersey number: " << endl;
    cin >> temp1;
    
    int pos = 0;
    int i = 0;
    for(i = 0; i < jerseyNum.size(); i++)
    {
        if(jerseyNum.at(i) == temp1)
        {
            jerseyNum.erase(jerseyNum.begin()+i);
            ratingNum.erase(ratingNum.begin()+i);
         break;
            
        }
    }
    
}
void updatePlayerRating(const vector<int>& jerseyNum, vector<int>& ratingNum)
{
    int temp1 = 0;
    int temp2 = 0;
    int i = 0;
    cout << "Enter a jersey number: " << endl;
    cin >> temp1; 
    cout << "Enter a new rating for player: " << endl;
    cin >> temp2;
    
    for(i = 0; i < jerseyNum.size(); i++)
    {
        if(jerseyNum.at(i) == temp1)
        {
        temp1 = i;
        break;
        }
    }
    ratingNum.at(temp1) = temp2;
    
}
void outputPlayersAboveRating(const vector<int>& jerseyNum, const vector<int>& ratingNum)
{
    int rating = 0;
    int j = 0;
    cout << "Enter a rating: " << endl;
    cin >> rating;
    cout << "ABOVE " << rating << endl;
    for(j = 0; j < jerseyNum.size(); j++)
    {
        if(ratingNum.at(j) > rating)
        {
            cout << "Player " << j+1 << " -- Jersey number: " << jerseyNum.at(j) << ", Rating: " << ratingNum.at(j) << endl;
        }
    }
    cout << endl;
    
}

void displayUI(vector<int>& jerseyNum, vector <int>& ratingNum, char& input)
{
    cout << "MENU" << endl << "a - Add player" << endl << "d - Remove player" << endl <<"u - Update player rating" << endl << "r - Output players above a rating" <<
   endl << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
   cin >> input;
   if(input == 'a')
   {
   addPlayer(jerseyNum, ratingNum);
   displayUI(jerseyNum, ratingNum, input);
   }
   else if(input == 'd')
   {
   removePlayer(jerseyNum, ratingNum);
   displayUI(jerseyNum, ratingNum, input);
   }
   else if(input == 'u')
   {
   updatePlayerRating(jerseyNum, ratingNum);
   displayUI(jerseyNum, ratingNum, input);
   }
   else if(input == 'r')
{
   outputPlayersAboveRating(jerseyNum, ratingNum);
   displayUI(jerseyNum, ratingNum, input);
}
   else if(input == 'o')
   {
   outputRoster(jerseyNum, ratingNum);
   displayUI(jerseyNum, ratingNum, input);
   }
   else if(input == 'q')
   return;
   else
   cout << "Invalid menu option. Try again." << endl;
    
}


int main() {

   vector<int> jerseyNum(5);
   vector<int> ratingNum(5);
   int temp1 = 0;
   int temp2 = 0;
   int i = 0;
   char input = 'q';
   for(i = 0; i < jerseyNum.size(); i++)
   {
       cout << "Enter player " << i+1 << "'s jersey number:" << endl;
       cin >> temp1;
       cout << "Enter player " << i+1 << "'s rating:" << endl;
       cin >> temp2;
       cout << endl;
       
       jerseyNum.at(i) = temp1;
       ratingNum.at(i) = temp2;
   }
   outputRoster(jerseyNum, ratingNum);
   
   displayUI(jerseyNum, ratingNum, input);
   
   return 0;
}