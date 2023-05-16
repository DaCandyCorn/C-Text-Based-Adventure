#include <iostream>
#include "historical.h"
#include <fstream>


void Historical::moveTo(int m) {
  // set variable to greater to move forward in script

  m+=1;
v+=m;
  mb = m;
}
void Historical::moveBack() { 
  v -= mb; 
  }
void Historical::help() {
  mb = 14 - v;
  v = 14;
}

void Historical::pickUp() {
  // User interacts or picks up an item that is available
}


