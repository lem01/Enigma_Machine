/*--------------------------------------------------------------------------+
|  IMPLEMENTATION FILE                                                      |
|  File Name:    enigma.cpp                                                 |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         11 November 2015                                            |
+--------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "enigma.h"
#include "helper.h"

using namespace std;

Plugboard::Plugboard() {
  for (int i=0; i<26; i++) {
    this->mapping[i]=i;
  }
}

int Plugboard::configure(const char *filename) {
  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    return 11;

  string string;
  int number_a = 0;
  int number_b = 0;

  while (in_stream >> string) {
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number_a = atoi(string.c_str());
    //    cout << string.c_str() << endl; // << number_a << endl;

    /* If this->mapping[i] !== i, then we have previously configured a plug cable
       from i to some other number, and now we are about to configure another
       plug cable from i to yet another number */
    if (this->mapping[number_a] != number_a)
      return 5;

    if (!(in_stream >> string)) // Odd no. of numbers in the configuration file
      return 6;

    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number_b = atoi(string.c_str());
    if (this->mapping[number_b] != number_b)
      return 5;
  
    // Setting a plug cable from a number to itself
    if (number_a == number_b)
      return 5;

    // All checks passed
    this->mapping[number_a] = number_b;
    this->mapping[number_b] = number_a;
  }
  return 0;
}

int Plugboard::encrypt(int letter) {
  return this->mapping[letter];
}

//////////////////////////////////////////////////////////////////////////////

Reflector::Reflector() {
  for (int i=0; i<26; i++) {
    this->mapping[i]=i;
  }
}

int Reflector::configure(const char *filename) {
  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    return 11;

  string string;
  int number_a = 0;
  int number_b = 0;

  for (int i=0; i<13; i++) {
    if (!(in_stream >> string))
      return 10;
 
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number_a = atoi(string.c_str());
    if (this->mapping[number_a] != number_a)
      return 9;

    if (!(in_stream >> string))
      return 10;

    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number_b = atoi(string.c_str());
    if (this->mapping[number_b] != number_b)
      return 9;
  
    if (number_a == number_b)
      return 5;

    // All checks passed
    this->mapping[number_a] = number_b;
    this->mapping[number_b] = number_a;
  }

  // The configuration file has more characters than required
  if (in_stream >> string)
    return 10;

  return 0;
}

int Reflector::encrypt(int letter) {
  return this->mapping[letter];
}

//////////////////////////////////////////////////////////////////////////////

Rotor::Rotor() {
  for (int i=0; i<26; i++) {
    this->mapping[i]=i;
  }
}

int Rotor::configure(const char *filename) {
  //configure mapping
}

int Rotor::set_position(const char *filename) {
