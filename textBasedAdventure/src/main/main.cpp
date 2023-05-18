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
ifstream asciiArt_file("asciiArt.txt");
vector<string> asciiArt;
ifstream gameOverWin_file("gameOverWin.txt");
vector<string> gameOverWin;
ifstream gameOverFail_file("gameOverFail.txt");
vector<string> gameOverFail;

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
  bool gameEnd = false;
  bool key, dagger, holoscanner, explosives, fKey; // puzzle elements
  vic.v = 0;
  bool gameWin = false;
  bool gameFail = false;
  bool vicWin = false;
  bool futureWin = false;
  bool historyWin = false;
  while (getline(background_file, line)) { // background reading
    background.push_back(line);
  }
  while (getline(victorian_file, line)) {
    victorian.push_back(line);
  }
  while (getline(futuristic_file, line)) {
    futuristic.push_back(line);
  }
  while (getline(asciiArt_file, line)) {
    asciiArt.push_back(line);
  }
  while (getline(historical_file, line)) {
    historical.push_back(line);
  }
  while (getline(gameOverWin_file, line)) {
    gameOverWin.push_back(line);
  }
  while (getline(gameOverFail_file, line)) {
    gameOverFail.push_back(line);
  }
  gameEnd = false;
  dagger = false;
  key = false;

  // begin user selections in designated storylines
  while (gameWin == false && gameFail == false) {
    cout
        << "Welcome to Text Based Adventure! Type your character's name now... "
           "\n";
    cin >> characterName;
    cout << background[0] + characterName + background[1] + "\n" + background[2]
         << endl;
    cout << "Victorian, 1900s, Futuristic \n Choose your next location " +
                characterName + "\n";
    cin >> travelInput;

    cout
        << "You pick " + travelInput +
               " and suddenly everything goes black. \n While you go through "
               "the "
               "wormholes into other dimensions and places, you only fall out "
               "of "
               "your regular descent. After choosing your destination, you are "
               "granted with that location. Only you wake up in that place..."
        << endl;
    if ((travelInput == "Victorian") || (travelInput == "victorian")) {

      cout << victorian[0] << endl;
      if (vic.v < victorian.size()) {
        vic.moveTo(1);
        cout << characterName + victorian[vic.v] << endl;
        while (vic.v < 20 && gameEnd == false && gameWin == false) {
          getline(cin, input);
          for (int x = 0; x < input.length(); x++) {
            towlower(input[x]);
          }
          if (input.substr(0, 9) == "move back") {
            vic.moveBack();
            cout << victorian[vic.v] << endl;
          } else if (input.substr(0, 10) == "pickup key") {
            cout << "You have picked up the key (move to 1/2)" << endl;
            cout << "\033[COLOUR_CODEm" << asciiArt[0] << endl;
            cout << "\033[COLOUR_CODEm" << asciiArt[1] << endl;
            cout << "\033[COLOUR_CODEm" << asciiArt[2] << endl;
            cout << "\033[COLOUR_CODEm" << asciiArt[3] << endl;
            cout << "\033[COLOUR_CODEm" << asciiArt[4] << endl;
            cout << "\033[COLOUR_CODEm" << asciiArt[5] << endl;
            key = true;
          } else if (input.substr(0, 13) == "pickup dagger") {
            cout << "You have picked up the dagger (move back)" << endl;
            dagger = true;
          } else if (input.substr(0, 4) == "help") {
            vic.help();
            cout << victorian[vic.v] << endl;
          } else if (input.substr(0, 7) == "move to") {
            inputTwo = input.substr(7, 8);
            inp = stoi(inputTwo);
            if (vic.v == 8 && key == true) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
            } else if (vic.v == 8 && key == false) {
              cout << "You can't move here because you don't have the key. You "
                      "must move back now."
                   << endl;
            } else if (vic.v == 7 && inp == 1) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
              gameEnd = true;

            } else if (vic.v == 11 && dagger == true && inp == 2) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
              gameEnd = true;
              gameWin = true;
              break;
            } else if (vic.v == 11 && dagger == false && inp == 2) {
              cout << "You can't kill the king because you don't have the "
                      "dagger. You "
                      "must move back now and assist the king."
                   << endl;
              cout << victorian[vic.v] << endl;
            } else if (vic.v == 11 && inp == 1) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
              gameEnd = true;
              gameFail = true;
              break;
            } else {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
            }
          }
        }

      } else {
        cout << "error" << endl;
      }
    } else if ((travelInput == "Futuristic") || (travelInput == "futuristic")) {
      fKey = false;
      holoscanner = false;
      explosives = false;
      future.v = 0;
      cout << futuristic[0] << endl;
      if (future.v < 20) {
        future.moveTo(1);
        cout << characterName << futuristic[1] << endl;
        while (future.v < 20) {
          getline(cin, input);
          for (int x = 0; x < input.length(); x++) {
            towlower(input[x]);
          }
          if (input.substr(0, 9) == "move back") {
            future.moveBack();
            cout << futuristic[future.v] << endl;
          } else if (input.substr(0, 10) == "pickup key") {
            cout << "You have picked up the key to Unit 39" << endl;
            fKey = true;
          } else if (input.substr(0, 18) == "pickup holoscanner") {
            cout << "You have picked up the holoscanner" << endl;
            holoscanner = true;
          } else if (input.substr(0, 17) == "pickup explosives") {
            cout << "You have picked up the bundle or explosives" << endl;
            explosives = true;
          } else if (input.substr(0, 4) == "help") {
            future.help();
            cout << futuristic[future.v] << endl;
          } else if (input.substr(0, 7) == "move to") {
            inputTwo = input.substr(7, 8);
            inp = stoi(inputTwo);
            if (future.v == 4 && fKey == false && inp == 1) {
              cout << "You try to enter unit 39 but you don't have a key to "
                      "open "
                      "it up."
                   << endl;
            } else if (future.v == 4 && fKey == true && inp == 1) {
              future.moveTo(1);
              cout << futuristic[future.v] << endl;
            } else if (future.v == 3 && holoscanner == false && inp == 2) {
              cout << "you can't enter the warrhouse because you don't have a "
                      "holoscanner/keycard"
                   << endl;
            } else if (future.v == 3 && inp == 2) {
              inp += 1;
              future.moveTo(inp);
              cout << futuristic[future.v] << endl;
            } else if (future.v == 11 && explosives == false) {
              cout << "you do not have the explosives, you must move back"
                   << endl;
              cout << futuristic[future.v] << endl;
            } else {
              future.moveTo(inp);
              cout << futuristic[future.v] << endl;
            }
          }
        }

      } else {
        cout << "error" << endl;
      }

    } else if (travelInput == "1900s") {
      fKey = false;
      holoscanner = false;
      explosives = false;
      history.v = 0;
      cout << historical[0] << endl;
      if (history.v < 20) {
        history.moveTo(1);
        cout << characterName << historical[1] << endl;
        while (history.v < 20) {
          getline(cin, input);
          for (int x = 0; x < input.length(); x++) {
            towlower(input[x]);
          }
          if (input.substr(0, 9) == "move back") {
            history.moveBack();
            cout << historical[history.v] << endl;
          } else if (input.substr(0, 10) == "pickup key") {
            cout << "You have picked up the key to Unit 39" << endl;
            fKey = true;
          } else if (input.substr(0, 18) == "pickup holoscanner") {
            cout << "You have picked up the holoscanner" << endl;
            holoscanner = true;
          } else if (input.substr(0, 17) == "pickup explosives") {
            cout << "You have picked up the bundle or explosives" << endl;
            explosives = true;
          } else if (input.substr(0, 4) == "help") {
            history.help();
            cout << historical[history.v] << endl;
          } else if (input.substr(0, 7) == "move to") {
            inputTwo = input.substr(7, 8);
            inp = stoi(inputTwo);
            if (history.v == 4 && fKey == false && inp == 1) {
              cout << "You try to enter unit 39 but you don't have a key to "
                      "open "
                      "it up."
                   << endl;
            } else if (history.v == 4 && fKey == true && inp == 1) {
              history.moveTo(1);
              cout << historical[history.v] << endl;
            } else if (history.v == 3 && holoscanner == false && inp == 2) {
              cout << "you can't enter the warrhouse because you don't have a "
                      "holoscanner/keycard"
                   << endl;
            } else if (history.v == 3 && inp == 2) {
              history.moveTo(3);
              cout << historical[history.v] << endl;
            } else if (history.v == 11 && explosives == false) {
              cout << "you do not have the explosives, you must move back"
                   << endl;
              cout << historical[history.v] << endl;
            } else {
              history.moveTo(inp);
              cout << historical[history.v] << endl;
            }
          }
        }

      } else {
        cout << "error" << endl;
      }
    } else if (vicWin == true && futureWin == true && historyWin == true) {
      gameWin =true;
      // cout << "\033[0;93m" << text_file.rdbuf() << endl;
      break;
    } else {
      cout << "that is not a viable input" << endl;
    };
  }
  if (gameWin == true) {
    cout << "display all text" << endl;
  } else if (gameFail == true) {
    // Display all text with color below (color is currently gold)
    // cout << "\033[0;93m" << text_file.rdbuf() << endl;
    cout << "Display all text" << endl;
  }
  background_file.close();
  victorian_file.close();
  futuristic_file.close();
  historical_file.close();
  asciiArt_file.close();
  gameOverWin_file.close();
  gameOverFail_file.close();

  return 0;
}
