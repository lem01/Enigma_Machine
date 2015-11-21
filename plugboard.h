#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "helper.h"
using namespace std;

class Plugboard {
private:
  int mapping[26];
public:
  int good; // Indicator of whether constructor was successful
  Plugboard(const char *filename);
  int encrypt(int &letter);
};

#endif
