#ifndef ROTOR_H
#define ROTOR_H

#include "helper.h"
using namespace std;

class Rotor {
private:
  int mapping[26];
  int *notch_ptr;
  int number_of_notch;
public:
  int top_position;
  Rotor();
  int configure(const char *filename);
  int encrypt(int &letter);
  void rotate();
};

#endif
