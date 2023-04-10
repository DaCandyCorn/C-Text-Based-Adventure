#include "futuristic.h"
#include "historical.h"
#include "victorian.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

//Nash Hale and Jax Jameson on the code while Carson Medsker, Park James, Aiden Harris, Jesse Stallings are on scripts

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
  Futuristic future;
  Historical history;
  string line;
  string characterName;
  string travelInput;
  vic.v = 0;
  while (getline(background_file, line)) { // background reading
    background.push_back(line);
  }
  while (getline(victorian_file, line)) {
    victorian.push_back(line);
  }
  cout << "Welcome to Text Based Adventure! Type your character's name now... "
          "\n";
  cin >> characterName;
  cout << background[0] + characterName + background[1] + "\n" + background[2]
       << endl;
  cout << "Victorian, 1900s, Futuristic \n Choose your next location " +
              characterName + "\n";
  cin >> travelInput;

   cout << "You pick " + travelInput +
              " and suddenly everything goes black. \n While you go through the wormholes into other dimensions and places, you only fall out of your regular descent. After choosing your destination, you are granted with that location. Only you wake up in that place..." << endl;

  //begin user selections in designated storylines
  if (travelInput == "Victorian") {
   
    // cout << victorian[0]<< endl;
    vic.moveTo(1);
    if (vic.v< victorian.size()){
    cout<< characterName + victorian[vic.v];
    } else {
      cout<< "error"<< endl;
    }
  } else if (travelInput == "Futuristic") {
     //future.enter();
  } else if (travelInput == "1900s") {
    // history.enter();
  } else {
    cout<< "that is not a viable input"<< endl;
  };
  background_file.close();
  victorian_file.close();
  futuristic_file.close();
  historical_file.close();
  return 0;
}
