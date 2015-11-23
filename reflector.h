/*--------------------------------------------------------------------------+
|  HEADER FILE                                                              |
|  File Name:    reflector.h                                                |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         23 November 2015                                           |
+--------------------------------------------------------------------------*/

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
