#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<string> viewArrivals() {
  vector<string> arrivals;
  arrivals = {"from Budapest >> 10:10", "from Berlin >> 12:45","from Ankara >> 11:00", "from Amsterdam >> 00:00", "from London >> 03:00", "from Mallorca >> 11:45", "from Belgrade >> 17:05", "from Torino >> 19:55"};
  return arrivals;
}

map<int, string> viewLuggage() {
  map<int, string> luggage;
  
  luggage = {
    {1, "Black"},
    {2, "Yellow"},
    {3, "Greeen"},
    {4, "Brown"}
  };
  return luggage;
}

vector<string> viewDepartures() {
  vector<string> departures;
  departures = {"to Manchester >> 12:00", "to Regensburg >> 14:56", "to Copenhagen >> 17:43", "to Rome >> 18:30"};
  return departures;
}

map<int, string> viewParkingSpots() {
  map<int, string> parkingSpots;

  parkingSpots = {
    {1, "a spot - free"},
    {2, "b spot - busy"},
    {3, "c spot - reserved"},
    {4, "d spot(Large) - reserved"},
    {5, "e spot(Large) - free"},
    {6, "f spot - busy"},
    {7, "g spot - under maintenance"},
    {8, "h spot - reserved"}
  };

  return parkingSpots;
}

void login() {
  string UserName, Password;
  string UseEnter, PassEnter;
  bool On_Off = true;
  bool Off = true;
  int countt = 0;
  int left = 4;

  cout << "\n**** Login to your account ****\n";
  while (On_Off) {
    fstream user;
    user.open("users.txt", ios::in);
    if (countt < 3 && Off && user.is_open()) {
      cout << "\nPassword is incorrect" << endl;
      left--;
      cout << "You have  " << left << " attempts to login!" << endl;
    }
    system("clear");
    cout << "enter your given username: ";
    getline(cin, UseEnter);
    cout << "Password: ";
    getline(cin, PassEnter);
    countt++;
    string read;
    while (getline(user, read)) {
      stringstream convertor(read);
      convertor >> UserName >> Password;
      if (UseEnter == UserName && PassEnter == Password) {
        Off = false;
      }
    }
    user.close();
    if (!Off) {
      cout << "Welcome";
      system("clear");
      On_Off = false;
    } else if (countt >= 3) {
      cout << "try again later!";
      system("clear");
      On_Off = false;
    }
  }
}

void registry() {
  string newName, checkName, newPass, confirmPass;
  int MiniPass;
  bool if_ON = true;
  bool oo = true;
  cout << "\n**** create a new account ****\n" << endl;

  while (oo) {
    system("clear");
    cout << "enter new username: ";
    getline(cin, newName);
    MiniPass = newName.length();
    fstream yusers;
    yusers.open("users.txt", ios::in);
    if (if_ON && MiniPass >= 1 && yusers.is_open()) {
      string readd;
      while (getline(yusers, readd)) {
        stringstream OnlyUsers(readd);
        OnlyUsers >> checkName;
        if (newName == checkName) {
          system("clear");
          cout << newName << " this username already exists";
          if_ON = false;
        }
      }
      if (!if_ON) {
        if_ON = true;
      } else {
        oo = false;
      }
    }
  }
  while (true) {
    system("clear");
    cout << "enter new password: ";
    getline(cin, newPass);
    cout << "confirm the new password: ";
    getline(cin, confirmPass);
    MiniPass = newPass.length();

    if (MiniPass < 5) {
      system("clear");
      cout << "your password is weak, needs to be atleast 5 digits";
    } else if (confirmPass == newPass) {
      fstream users;
      users.open("users.txt", ios::app);
      if (users.is_open()) {
        users << newName + " " + newPass << endl;
        users.close();
        break;
      }
    }
  }
}
void logo() {
cout << "-----------------------------------------------------------------------------------------------------\n";
cout << "##       #### ########   #######   ######  ########    ###         ########  ####  ######      ###   \n"; 
cout << "##        ##  ##     ## ##     ## ##    ##    ##      ## ##        ##     ##  ##  ##    ##    ## ##  \n"; 
cout << "##        ##  ##     ## ##     ## ##          ##     ##   ##       ##     ##  ##  ##         ##   ## \n"; 
cout << "##        ##  ##     ## ##     ##  ######     ##    ##     ##      ########   ##  ##   #### ##     ## \n";
cout << "##        ##  ##     ## ##     ##       ##    ##    #########      ##   ##    ##  ##    ##  #########  \n"; 
cout << "##        ##  ##     ## ##     ## ##    ##    ##    ##     ##      ##    ##   ##  ##    ##  ##     ## \n";
cout << "######## #### ########   #######   ######     ##    ##     ##      ##     ## ####  ######   ##     ##  \n";
cout << "-----------------------------------------------------------------------------------------------------";
}
int main() {
  logo();
  string LoR;
  cout << "\nlogin or register: ";
  while (true) {
    getline(cin, LoR);
    if (LoR == "login") {
      login();
      while (true) {
        cout << "\nPlease choose an option:\n";
        cout << "1. View arrivals\n";
        cout << "2. View departures\n";
        cout << "3. View parking spots\n";
        cout << "4. View luggage\n";
        cout << "5. Exit program\n";
        string option;
        getline(cin, option);
        switch (stoi(option)) {
          case 1: {
            vector<string> arrivals = viewArrivals();
            cout << "\nArrivals:\n";
            for (string arrival : arrivals) {
              cout << arrival << endl;
            }
            break;
          }
          case 2: {
            vector<string> departures = viewDepartures();
            cout << "\nDepartures:\n";
            for (string departure : departures) {
              cout << departure << endl;
            }
            break;
          }
          case 3: {
            map<int, string> parkingSpots = viewParkingSpots();
            cout << "\nParking spots:\n";
            for (auto const& [spot, status] : parkingSpots) {
              cout << "Spot " << spot << ": " << status << endl;
            }
            break;
          }
          case 4: {
            map<int, string> luggage = viewLuggage();
            cout << "\nLuggage details:\n";
            for (auto const& [numeric, color] : luggage) {
              cout << "number " << numeric << " >> " << color << endl;
            }
            break;
          }
          case 5: {
            cout << "\nExiting program...\n";
            return 0;
          }
          default: {
            cout << "\nInvalid option, please try again.\n";
          }
        }
      }
    } else if (LoR == "register") {
      registry();
      break;
    } else {
      cout << "enter login or register: ";
    }
  }
  return 0;
}
