/*--------------------------------------------------------------------------+
|  IMPLEMENTATION FILE                                                      |
|  File Name:    plugboard.cpp                                              |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         23 November 2015                                           |
+--------------------------------------------------------------------------*/

#include "plugboard.h"
using namespace std;

Plugboard::Plugboard(const char *filename) {
  good = 0;
  for (int i=0; i<26; i++) {
    this->mapping[i]=i;
  }
  // Initialised to default values before being configured with FILENAME

  ifstream in_stream;
  in_stream.open(filename);
  int count = 0;

  if (!in_stream)
    good = 11;
  else {
    string string;
    int number_a = 0;
    int number_b = 0;

    while ((in_stream >> string) && (good == 0)) {
      count++;
      if (count > 13) // Too many input
	good = 6;
      else if (!is_numeric(string))
	good = 4;
      else if (!is_valid(string))
	good = 3;
      else {
	number_a = string_to_int(string);
	/* If mapping[i] != i, then we have previously configured a plug cable
	   from i to some other number, and now we are about to configure another
	   plug cable from i to yet another number */
	if (mapping[number_a] != number_a)
	  good = 5;
	else if (!(in_stream >> string)) // Odd no. of numbers in the configuration file
	  good = 6;
	else if (!is_numeric(string))
	  good = 4;
	else if (!is_valid(string))
	  good = 3;
	else {
	  number_b = string_to_int(string);
	  if (mapping[number_b] != number_b)
	    good = 5;
	  else if (number_a == number_b) // Setting a plug cable from a number to itself
	    good = 5;
	  else {
	    // All checks passed
	    mapping[number_a] = number_b;
	    mapping[number_b] = number_a;
	  }
	}
      }
    }
  }
  in_stream.close();
}

int Plugboard::encrypt(const int &letter) {
  return mapping[letter];
}
