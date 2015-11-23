#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "helper.h"
using namespace std;

class Reflector {
private:
  int mapping[26];
public:
  int good; // Indicator of whether constructor was successful
  Reflector(const char *filename);
  int encrypt(const int &letter);
};

#endif
