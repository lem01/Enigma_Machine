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
  configure >> number_a;
  configure >> number_b;
  if (number_a = number_b)
    return 5;
  

}

int Plugboard::encrypt(int letter) {
  return mapping[letter];
}





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
