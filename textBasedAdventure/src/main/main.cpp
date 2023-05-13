#include "futuristic.h"
#include "historical.h"
#include "victorian.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// Nash Hale and Jax Jameson on the code while Carson Medsker, Park James, Aiden
// Harris, Jesse Stallings are on scripts

using namespace std;
ifstream background_file("background.txt");
vector<string> background;
ifstream victorian_file("victorian.txt");
vector<string> victorian;
ifstream futuristic_file("futuristic.txt");
vector<string> futuristic;
ifstream historical_file("historical.txt");
vector<string> historical;

int main() {
  Victorian vic;
  Futuristic future{};
  Historical history;
  string line;
  string characterName;
  string travelInput;
  string input; // which method we are using
  string inputTwo;
  int inp; // int that is changed using vic.v
  bool gameEnd;
  bool key, dagger, holoscanner, explosives; // puzzle elements
  vic.v = 0;
  while (getline(background_file, line)) { // background reading
    background.push_back(line);
  }
  while (getline(victorian_file, line)) {
    victorian.push_back(line);
  }
  while (getline(futuristic_file, line)) {
    futuristic.push_back(line);
  }
  
  gameEnd = false;
  cout << "Welcome to Text Based Adventure! Type your character's name now... "
          "\n";
  cin >> characterName;
  cout << background[0] + characterName + background[1] + "\n" + background[2]
       << endl;
  cout << "Victorian, 1900s, Futuristic \n Choose your next location " +
              characterName + "\n";
  cin >> travelInput;

  cout
      << "You pick " + travelInput +
             " and suddenly everything goes black. \n While you go through the "
             "wormholes into other dimensions and places, you only fall out of "
             "your regular descent. After choosing your destination, you are "
             "granted with that location. Only you wake up in that place..."
      << endl;

  // begin user selections in designated storylines
  if ((travelInput == "Victorian") || (travelInput == "victorian")) {

    cout << victorian[0] << endl;
    if (vic.v < victorian.size()) {
      vic.moveTo(1);
      cout << characterName + victorian[vic.v] << endl;
      while (vic.v < 20 && gameEnd == false) {
        getline(cin, input);
        for (int x = 0; x < input.length(); x++) {
          towlower(input[x]);
        }
        if (input.substr(0, 9) == "move back") {
          vic.moveBack();
          cout << victorian[vic.v] << endl;
        } else if (input.substr(0, 10) == "pickup key") {
          cout << "You have picked up the key" << endl;
          key = true;
        } else if (input.substr(0, 13) == "pickup dagger") {
          cout << "You have picked up the dagger" << endl;
          dagger = true;
        } else if (input.substr(0, 4) == "help") {
          vic.help();
          cout << victorian[vic.v] << endl;
        } else if (input.substr(0, 7) == "move to") {
          inputTwo = input.substr(7, 8);
          inp = stoi(inputTwo);
          if (vic.v >= 0 && vic.v < 8) {
            vic.moveTo(inp);
            cout << victorian[vic.v] << endl;
          } else if (vic.v == 8 && key == true) {
            vic.moveTo(inp);
            cout << victorian[vic.v] << endl;
          } else if (vic.v == 8 && key == false) {
            cout << "You can't move here because you don't have the key. You "
                    "must move back now."
                 << endl;
          } else if (vic.v == 10) {
            gameEnd = true;
          } else if ((vic.v == 11 && dagger == true)) {
            vic.moveTo(inp);
            cout << victorian[vic.v] << endl;
            gameEnd = true;
          } else if ((vic.v == 11 && dagger == false) && inp == 2) {
            cout << "You can't kill the king because you don't have the "
                    "dagger. You "
                    "must move back now and assist the king."
                 << endl;
            cout << victorian[vic.v] << endl;
          } else if ((vic.v == 11 && dagger == false) && inp == 1) {
            vic.moveTo(inp);
            gameEnd = true;
          }
        }
      }

    } else {
      cout << "error" << endl;
    }
    getline(cin, travelInput);
  } else if ((travelInput == "Futuristic") || (travelInput == "futuristic")) {

    cout << futuristic[0] << endl;
    if (future.v < futuristic.size()) {
      future.moveTo(1);
      cout << characterName + futuristic[future.v] << endl;
      while (future.v < 20 && gameEnd == false) {
        getline(cin, input);
        for (int x = 0; x < input.length(); x++) {
          towlower(input[x]);
        }
        if (input.substr(0, 9) == "move back") {
          future.moveBack();
          cout << futuristic[future.v] << endl;
        } else if (input.substr(0, 18) == "pickup holoscanner") {
          cout << "You have picked up the key" << endl;
          key = true;
        } else if (input.substr(0, 17) == "pickup explosives") {
          cout << "You have picked up the dagger" << endl;
          dagger = true;
        } else if (input.substr(0, 4) == "help") {
          future.help();
          cout << futuristic[future.v] << endl;
        } else if (input.substr(0, 7) == "move to") {
          inputTwo = input.substr(7, 8);
          inp = stoi(inputTwo);
          // put in specifics as needed
        }
      }

    } else {
      cout << "error" << endl;
    }

    // } else if (vic.v == 8 && key == true) {
    //   vic.moveTo(inp);
    //   cout << futuristic[vic.v] << endl;
    // } else if (vic.v == 8 && key == false) {
    //   cout << "You can't move here because you don't have the key. You "
    //           "must move back now."
    //        << endl;
    // } else if (vic.v == 10) {
    //   gameEnd = true;
    // } else if ((vic.v == 11 && dagger == true)) {
    //   vic.moveTo(inp);
    //   cout << futuristic[vic.v] << endl;
    //   gameEnd = true;
    // } else if ((vic.v == 11 && dagger == false) && inp ==2 ) {
    //   cout << "You can't kill the king because you don't have the "
    //           "dagger. You "
    //           "must move back now and assist the king."
    //        << endl;
    //   cout << futuristic[vic.v]<< endl;
    // } else if ((vic.v == 11 && dagger == false) && inp ==1 ) {
    //   vic.moveTo(inp);
    //   gameEnd = true;
    // }

    // cout << futuristic[0] << endl;
    // if (vic.v < victorian.size()) {
    //   vic.moveTo(1);
    //   cout << characterName + victorian[vic.v] << endl;
    //   while (vic.v < 15) {
    //     getline(cin, input);
    //     for (int x = 0; x < input.length(); x++) {
    //       towlower(input[x]);
    //     }

    //     if (input.substr(0, 7) == "move to") {
    //       inputTwo = input.substr(7, 8);
    //       inp = stoi(inputTwo);
    //       if (inp <= vic.h) {
    //         cout << inp;
    //         vic.moveTo(inp);
    //         cout << victorian[vic.v] << endl;
    //       } else {
    //         cout << "not a viable pathway" << endl;
    //       }
    //     } else if (input.substr(0, 9) == "move back") {
    //       vic.moveBack();
    //       cout << victorian[vic.v] << endl;
    //     } else if (input.substr(0, 3) == "help") {
    //       vic.help();
    //       cout << victorian[vic.v] << endl;
    //     } else if (input.substr(0, 6) == "pickup") {
    //     }
    //   }

    // } else {
    //   cout << "error" << endl;
    // }

  } else if (travelInput == "1900s") {
    // history.enter();
  } else {
    cout << "that is not a viable input" << endl;
  };
  background_file.close();
  victorian_file.close();
  futuristic_file.close();
  historical_file.close();
  return 0;
}
