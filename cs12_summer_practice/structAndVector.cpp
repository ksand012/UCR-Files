#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct CountryTvWatch {
    string countryName;
    int tvMinutes;
};

int main() {
    // Source: www.statista.com, 2010
    const int NUM_COUNTRIES = 4;

    vector<CountryTvWatch> countryList(NUM_COUNTRIES);
    string countryToFind;
    bool countryFound = false;
    int i = 0;

    countryList.at(0).countryName = "Brazil";
    countryList.at(0).tvMinutes = 222;
    countryList.at(1).countryName = "India";
    countryList.at(1).tvMinutes = 119;
    countryList.at(2).countryName = "U.K.";
    countryList.at(2).tvMinutes = 242;
    countryList.at(3).countryName = "U.S.A.";
    countryList.at(3).tvMinutes = 283;

    cout << "Enter country name: ";
    cin >> countryToFind;

    for (i = 0; i < NUM_COUNTRIES; ++i) { // Find country's index
        if (countryList.at(i).countryName == countryToFind) { 
            countryFound = true;
            cout << "People in " << countryToFind << endl;
            cout << "watch " << countryList.at(i).tvMinutes; 
            cout << " minutes of TV daily." << endl;
        }
    }
    if (!countryFound) {
        cout << "Country not found, try again." << endl;
    }

    return 0;
}