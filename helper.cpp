#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "helper.h"

using namespace std;

bool is_numeric(const string &string) {
  for (int i=0; i < int(string.length()); i++) {
    if (!isdigit(string[i]))
      return 0;
  }
  return 1;
}

bool is_valid(const string &string) {
  int number = atoi(string.c_str());

  if (number > 25)
    return 0;
  else
    return 1;
}
