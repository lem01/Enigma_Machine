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
  int good; // Indicator of whether constructor was successful
  int top_position;
  Rotor(const char *filename);
  ~Rotor();
  friend int set_rotor_position(Rotor *rotor, int no_of_rotors, const char *filename);
  int encrypt_rtl(int &letter); // Right to left
  int encrypt_ltr(int &letter); // Left to right
  void rotate();
};

#endif
