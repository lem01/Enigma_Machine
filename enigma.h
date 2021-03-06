/*--------------------------------------------------------------------------+
|  HEADER FILE                                                              |
|  File Name:    enigma.h                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         23 November 2015                                           |
+--------------------------------------------------------------------------*/

#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"
#include "helper.h"
using namespace std;

class Enigma {
private:
  Plugboard *plugboard;
  Reflector *reflector;
  Rotor **rotor;
  int no_of_rotor;
public:
  int good; //Indicator of whether constructor was successful
  Enigma(int argc, char **argv);
  // ~Enigma();
  int encrypt(const int &letter);
};

#endif
