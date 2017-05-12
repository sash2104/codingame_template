#include <iostream>
#include "common.hpp"
#include "game.hpp"

Game::Game() {
  turn = 1;
}

Game::~Game() {
}

void Game::write_initial_output() {
}

void Game::read_initial_input() {
}

void Game::read_input() {
  turn += 1;
}

void Game::write_output() {
}

void Game::determine_command() {
  simulate();
}

void Game::simulate() {
}

void Game::revert() {
}
