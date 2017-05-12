#pragma once
#include <array>
#include <unordered_map>
#include "pos.hpp"

enum struct Action
{
  NONE,
  // revert commands
  // SET_DUMMY
};

struct Command
{
  Command(Action action, int id, int value)
    : action(action), id(id), value(value) {}
  Command(Action action, int id)
    : action(action), id(id) {}
  Command() {}
  Action action;
  int id;
  int value; // Actionに応じてspeed, orientationなど格納される値が変わる

  friend std::ostream& operator<< (std::ostream &out, const Command &c)
  {
    // out << "hoge";
    return out;
  }
};

class Game {
  public:
    int turn;
    Game();
    ~Game();
    void write_initial_output();
    void read_initial_input();
    void read_input();
    void write_output();

    void determine_command();
    void clear();
    void simulate(); // simulate a turn
    void revert(); // revert commands
};
