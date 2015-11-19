/*--------------------------------------------------------------------------+
|  IMPLEMENTATION FILE                                                      |
|  File Name:    enigma.cpp                                                 |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         11 November 2015                                           |
+--------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "enigma.h"

using namespace std;

int set_rotor_position(const int &no_of_rotors, Rotor *rotor, const char *filename) {
  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    return 11;

  string string;

  for (int i=0; i < no_of_rotors; i++) {
    if (!(in_stream >> string))
      return 8;
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    rotor[i].top_position = atoi(string.c_str());
  }

  return 0;
}


// set rotor positions
