#pragma once

#include <iostream>
#include <string>

template <typename T>
static void dprint (const T& s) {
  std::cerr << s << std::endl;
}
