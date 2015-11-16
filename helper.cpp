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
  int number = atoi(string.c_str()) - 48;

  if (number > 25)
    return 0;
  else
    return 1;
}

int check_config(const char *filename) {
  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    return 11;

  string string;
  while (!in_stream.eof()) {
    in_stream >> string;
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
  }

  return 0;
}

