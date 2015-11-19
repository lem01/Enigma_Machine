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

/*
class Enigma {
private:
  Plugboard *_plugboard;
  Reflector *_reflector;
  Rotor *_rotor;
  
public:
  Enigma();
  int configure(int ;
};
*/

/* Function to initialise the top position of each rotor */
int set_rotor_position(const int &no_of_rotors, Rotor *rotor, const char *filename);





#endif
