#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Seat {
   string firstName;
   string lastName;
   int amountPaid;
};

/*** Functions for Seat ***/
void SeatMakeEmpty(Seat& seat) {
   seat.firstName   = "empty";
   seat.lastName    = "empty";
   seat.amountPaid  = 0;
   return;
}

bool SeatIsEmpty(Seat seat) {
   return(seat.firstName == "empty");
}

void SeatPrint(Seat seat) {
   cout << seat.firstName << " ";
   cout << seat.lastName << ", ";
   cout << "Paid: " << seat.amountPaid << endl;
   return;
}
/*** End functions for Seat ***/

/*** Functions for vector of Seat ***/
void SeatsMakeEmpty(vector<Seat>& seats) {
   unsigned int i = 0;
   for (i = 0; i < seats.size(); ++i) {
      SeatMakeEmpty(seats.at(i));
   }
   return;
}

void SeatsPrint(vector<Seat> seats) {
   unsigned int i = 0;
   for (i = 0; i < seats.size(); ++i) {
      cout << i << ": ";
      SeatPrint(seats.at(i));
   }
   return;
}
/*** End functions for vector of Seat ***/

int main() {
   char userKey = '-';
   int  seatNum = 0;
   vector<Seat> allSeats(5);
   Seat currSeat;
   
   SeatsMakeEmpty(allSeats);
   
   while (userKey != 'q') {
      
      cout << endl << "Enter command (p/r/q): ";
      cin >> userKey;
      
      if (userKey == 'p') { // Print seats
         SeatsPrint(allSeats);
      }
      else if (userKey == 'r') { // Reserve seat
         cout << "Enter seat num: ";
         cin  >> seatNum;
         
         if (!SeatIsEmpty(allSeats.at(seatNum))) {
            cout << "Seat not empty." << endl;
         }
         else {
            cout << "Enter first name: ";
            cin >> currSeat.firstName;
            cout << "Enter last name: ";
            cin >> currSeat.lastName;
            cout << "Enter amount paid: ";
            cin >> currSeat.amountPaid;
            
            allSeats.at(seatNum) = currSeat;
            cout << "Completed." << endl;
         }
      }
      // FIXME: Add option to delete reservations
      else if (userKey == 'q') {
         cout << "Quitting." << endl;
      }
      else {
         cout << "Invalid command." << endl;
      }
   }
   
   return 0;
}