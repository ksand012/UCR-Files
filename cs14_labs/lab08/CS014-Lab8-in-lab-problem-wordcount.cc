#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> bananaSplitFunct(string tempStr, string lookAtStr)
{
    vector<string> r;
    while(tempStr.size())
    {
        int index = tempStr.find(lookAtStr);
        if(index!=string::npos)
        {
            r.push_back(tempStr.substr(0,index));
            tempStr = tempStr.substr(index+lookAtStr.size());
            if(tempStr.size()==0)
            {
                r.push_back(tempStr);
            }
        }
        else
        {
            r.push_back(tempStr);
            tempStr = "";
        }
    }
    return r;
}

vector<pair<string, unsigned int>> wordCount(string filename) {
    ifstream file(filename);
    string line;
    //string separators = " \t,."; <---------NOT USED
    
    unordered_map<string,int> wordMap; //WORD MAP
    
    if (file.is_open()) 
    {
        while (getline(file, line)) 
        {
            for(int i = 0; i < line.size(); i++)
            {
                line.at(i) = tolower(line.at(i));
                if(line.at(i) == '\t' || line.at(i) == ',' || line.at(i) == '\t' || line.at(i) == ';' || line.at(i) == '.')
                    line.erase(i,1);
            }
            
            vector<string> splitStrings = bananaSplitFunct(line, " "); //SEND TO THE BANANA SPLIT!
            
            bananaSplitFunct(line, " "); //CALL A SECOND TIME TO RESOLVE ISSUES W/ IT NOT SPLITTING PROPERLY
            
            for(string lookAtWord: splitStrings) // START COUNTING
            {
                if(wordMap.find(lookAtWord) == wordMap.end())
                    wordMap.insert(make_pair(lookAtWord,1));
                else
                    wordMap.at(lookAtWord) = wordMap.at(lookAtWord) + 1;
            }
        }
    }
    
/*========================================================================*/

    //OUT OF FOR LOOP... START COUNTING THRU THE PAIR!!!
    //
    //
    //ksand012
    
/*========================================================================*/

    
    vector<pair<string, unsigned int>>finalResult;
    
    unordered_map<string, int>:: iterator itr;
    
    for(itr = wordMap.begin(); itr != wordMap.end(); itr++)
        finalResult.push_back(make_pair(itr->first, itr->second));
    
     return finalResult;
}

int main(){
    auto counts = wordCount("SampleTextFile_10kb.txt");
    for (auto i = counts.begin(); i != counts.end(); i++)
    {
        cout << i->first << "\t" << i->second << endl;
    }
    cout << "End of program" << endl;
	return 0;
}