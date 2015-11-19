#ifndef ENIGMA_H
#define ENIGMA_H

#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"
#include "helper.h"
using namespace std;

/*
class Enigma {
private:
  Plugboard _plugboard;
public:
  Enigma();
};
*/

/* Function to initialise the top position of each rotor */
int set_rotor_position(const int &no_of_rotors, Rotor *rotor, const char *filename);





#endif
