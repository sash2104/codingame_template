#pragma once
#include <array>
#include <unordered_map>
#include "pos.hpp"

class Game {
  public:
    Game();
    ~Game();
    void write_initial_output();
    void read_initial_input();
    void read_input();
    void write_output();
};
