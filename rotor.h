#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "helper.h"
using namespace std;

class Rotor {
private:
  int mapping[2][26];
  int *notch_ptr;
  int number_of_notch;
public:
  int top_position;
  Rotor();
  ~Rotor();
  int configure(const char *filename);
  int encrypt(int &letter);
  void rotate();
};

#endif
