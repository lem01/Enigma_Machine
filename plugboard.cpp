#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "plugboard.h"

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

    /* If this->mapping[i] != i, then we have previously configured a plug cable
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
  in_stream.close();
  
  return 0;
}

int Plugboard::encrypt(int &letter) {
  return this->mapping[letter];
}
