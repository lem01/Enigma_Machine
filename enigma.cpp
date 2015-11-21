/*--------------------------------------------------------------------------+
|  IMPLEMENTATION FILE                                                      |
|  File Name:    enigma.cpp                                                 |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         11 November 2015                                           |
+--------------------------------------------------------------------------*/

#include "enigma.h"
using namespace std;

Enigma::Enigma(int argc, char **argv) {
  good = 0;
  plugboard = NULL;
  reflector = NULL;
  *rotor = NULL;
  // Initialised to default values before being configured with input from command line

  if (argc == 1)
    good = 1;
  else {

    cout << "Loading plugboard configuration... ";
    plugboard = new Plugboard(argv[1]);
    good = plugboard->good;
 
    if (good == 0) {
      cout << "Success!" << endl;
      cout << "Plugboard configured using \"" << argv[1] << "\".\n\n";

      if (argc == 2)
	good = 1;
      else {

	cout << "Loading reflector configuration... ";
	reflector = new Reflector(argv[2]);
	good = reflector->good;

	if (good == 0) {
	  cout << "Success!" << endl;
	  cout << "Reflector configured using \"" << argv[2] << "\".\n\n";

	  if (argc == 4)
	    good = 1;
	  else if (argc > 4) {

	    cout << "Loading rotor configuration... ";
	    rotor = new Rotor*[argc - 4];
	    for (int i=0; i < (argc - 4); i++)
	      rotor[i] = NULL; // Initialise each pointer before configuring each rotor

	    for (int i=0; ((i < (argc - 4)) && (good == 0)); i++) {
	      rotor[i] = new Rotor(argv[i+3]);
	      good = rotor[i]->good;

	      if (good == 0) {
		good = set_rotor_position(*rotor, argc - 4, argv[argc - 1]);

		if (good == 0) {
		  cout << "Success!" << endl;

		  if (argc == 5) {
		    cout << "One rotor configured using \"" << argv[3] << "\".\n";
		    cout << "Its position is configured using \"" << argv[4] << "\".\n\n";
		  }
		  else if (argc == 6) {
		    cout << "2 rotors configured using \"" << argv[3]
			 << "\" and \"" << argv[4] << "\".\n";
		    cout << "Their positions are configured using \"" << argv[5] << "\".\n\n";
		  }
		  else {
		    cout << argc - 4 << " rotors configured using ";
		    for (int i=3; i <= argc - 3; i++) {
		      cout << "\"" << argv[i] << "\", ";
		    }
		    cout << "and \"" << argv[argc - 2] << "\".\n";
		    cout << "Their positions are configured using \"" << argv[argc - 1] << "\".\n\n";
		  }
		}
	      }
	      else
		delete rotor[i];
	    }
	    if (good != 0)
	      delete [] rotor;
	  }
	  if (good == 0)
	    cout << "Enigma has been successfully configured!\n\n";
	}
      }
    }
  }
}

Enigma::~Enigma() {
  delete [] rotor;
}
