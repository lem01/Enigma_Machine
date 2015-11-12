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

using namespace std;

class Plugboard {
private:
  int mapping[26];
public:
  Plugboard();
  Plugboard(const char *filename);
  int encrypt(int letter);

};

Plugboard::Plugboard() {
  for (int i=0, i<26, i++) {
    mapping[i]=i;
  }
}

Plugboard::Plugboard(const char *filename) {
  for (int i=0, i<26, i++) {
    mapping[i]=i;
  }

  ifstream configure;
  configure.open(filename);

  if(!configure) {
    cerr << "Error opening configuration file!\n";
    return 11;
  }

  string string_a;
  int number_a;
  string string_b;
  int number_b;

  while (!configure.eof()) {
    configure >> string_a;
    if (!isnumeric(string_a))
      return 4;

    number_a = int(string_a) - 48;

    if (number_a > 25) {
      cerr << "Invalid index!\n";
      return 3;
    }
   






    configure >> number_b;
  if (number_a = number_b)
    return 5;
  
  }
}

int Plugboard::encrypt(int letter) {
  return mapping[letter];
}






/*
  number = int(string_a) - 48;

  if (number_a > 25) {
    cerr << "Invalid index!\n";
    return 3;
  }
}
*/



class Rotor {
private:
  Mapping mapping;
public:
  

};

class Reflector {
private:
  Mapping mapping;
public:
  

};

class Enigma {
private:

public:
  

};
