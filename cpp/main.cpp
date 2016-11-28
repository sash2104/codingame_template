#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "common.hpp"
#include "pos.hpp"
#include "game.hpp"

int main()
{
  Game g;
  g.read_initial_input();
  g.write_initial_output();
  // game loop
  while (1) {
    g.read_input();
    g.write_output();
  }
}
