/*--------------------------------------------------------------------------+
|  HEADER FILE                                                              |
|  File Name:    plugboard.h                                                |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         23 November 2015                                           |
+--------------------------------------------------------------------------*/

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
  int encrypt(const int &letter);
};

#endif
