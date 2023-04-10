#include "victorian.h"
#include <fstream>
#include <iostream>

void Victorian::enter() {
  // Input a victorian theme script to get information and choices from
}

void Victorian::moveTo(int m) {
  // set variable to greater to move forward in script
  v += m;
  m = mb;
}
void Victorian::moveBack() {
  v -=mb;
}
void Victorian::talk() {
  // Input a victorian theme script to get information and choices from a npc
}
void Victorian::use() {
  // Use an item in the user's inventory
}
void Victorian::pickUp() {
  // User interacts or picks up an item that is available
}
