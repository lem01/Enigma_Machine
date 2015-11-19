#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "helper.h"
using namespace std;

class Reflector {
private:
  int mapping[26];
public:
  Reflector();
  int configure(const char *filename);
  int encrypt(int &letter);
};

#endif
