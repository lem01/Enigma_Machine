#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "helper.h"
using namespace std;

class Plugboard {
private:
  int mapping[26];
public:
  Plugboard();
  int configure(const char *filename);
  int encrypt(int &letter);
};

#endif
