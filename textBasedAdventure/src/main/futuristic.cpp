#include <iostream>
#include "futuristic.h"
#include <fstream>


void Futuristic::moveTo(int m) {
  // set variable to greater to move forward in script

  
if (v>=0 && v<=3) {
  v+=m;
} else if (v ==4) {
  v+=m;
}else {
  m +=1 ;
  v+=m;
}
  mb = m;
}
void Futuristic::moveBack() { 
  v -= mb; 
  }
void Futuristic::help() {
  mb = 14 - v;
  v = 14;
}

void Futuristic::pickUp() {
  // User interacts or picks up an item that is available
}

// #include <iostream>
// #include "futuristic.h"
// #include <fstream>

// void Futuristic::moveTo(int m) {
//   // set variable to greater to move forward in script
//   v += m;
//   if (v >2) {
//     v+=1;
//   }
//   mb = m;
// }
// void Futuristic::moveBack() {
//   // set variable to less than to backwards in script
//     v -=mb;
// }
// void Futuristic::talk() {
//   // Input a Futuristic theme script to get information and choices from a
//   npc
// }
// void Futuristic::help() {
//   mb = 14 - v;
//   v = 14;
// }
// void Futuristic::use() {
//   // Use an item in the user's inventory
// }
// void Futuristic::pickUp() {
//   // User interacts or picks up an item that is available
// }
