#include "Bridges.h"
#include <vector>
#include <iostream>
#include <math.h>
#include "Hanoi.hpp"

using namespace std;
using namespace bridges;

  
void moveStack(Hanoi& nt, int from, int to, int howmany) {
  //TODO
   if (howmany == 1) {
        nt.move(from, to);
    }
    else {
        int other = 6 - (from + to);
        moveStack(nt, from, other, howmany - 1);
        nt.move(from, to);
        moveStack(nt, other, to, howmany -1);
    }
}

// 31 steps for 5 disks, formula is 2^n - 1
//  1 move(1, 2);
//  2 move(1, 3);
//  3 move(2, 3);
//  4 move(1, 2);
//  5 move(3, 1);
//  6 move(3, 2);
//  7 move(1, 2);
//  8 move(1, 3);
//  9 move(2, 3);
//  10 move(2, 1);
//  11 move(3, 1);
//  12 move(2, 3);
//  13 move(1, 2);
//  14 move(1, 3);
//  15 move(2, 3);
//  16 move(1, 2);
//  17 move(3, 1);
//  18 move(3, 2);
//  19 move(1, 2);
//  20 move(3, 1);
//  21 move(2, 3);
//  22 move(2, 1);
//  23 move(3, 1);
//  24 move(3, 2);
//  25 move(1, 2);
//  26 move(1, 3);
//  27 move(2, 3);
//  28 move(1, 2);
//  29 move(3, 1);
//  30 move(3, 2);
//  31 move(1, 2);  

int main() {
  //create Bridges object
  Bridges bridges (126, "eyesgotsunshine", "1229484650880");
  // title, description
  bridges.setTitle("Towers of Hanoi");
  bridges.setDescription("Moving only one disk at a time, how to move the first stack to the second stack without ever having a large disk sittign ontop of a small disk?");
  
  Hanoi nt (5, bridges);
  
  // set visualizer type
  SymbolCollection sc = nt.getVisual();
  bridges.setDataStructure(&sc);
  // visualize the JSON and Collection
  bridges.visualize();
  

  moveStack(nt, 1, 2, 5);
		
  // nt.move(1,2);
  // // set visualizer type
  // bridges.setDataStructure(nt.getVisual());
  // // visualize the JSON and Collection
  // bridges.visualize();

  return 0;
}
