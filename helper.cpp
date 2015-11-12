#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isnumeric(const string &string) {
  for (int i=0; i < int(string.length()); i++) {
    if (!isdigit(string[i]))
      return 0;
  }
  return 1;
}

bool 
