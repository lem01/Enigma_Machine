/*--------------------------------------------------------------------------+
|  File Name:    main.cpp                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Description:  Enigma machine to encrypt and decrypt messages             |
|  Date:         16 November 2015                                           |
+--------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <typeinfo> // js for checking
#include <string>
#include <cstdlib>
#include "enigma.h"
#include "helper.h"
#include "errors.h"

using namespace std;

int main(int argc, char **argv) {

  // Checking input from the command line
  cout << "The number of argc is : " << argc << endl;
  for (int i=0; i<argc; i++)
    cout << "The content of argv[" << i << "] is " << argv[i] << endl;
  cout << endl;

  cout << "The type of argc is " << typeid(argc) << endl;
  cout << "The type of argv is " << typeid(argv) << endl;

  int check;

  if (argc == 1) {
    cerr << "Insufficient number of parameters!" << endl;
    cerr << "In order to set up the Enigma machine, a configuration file each for the wiring map of the plugboard and of the reflector is needed at the minimum." << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }

  /* PLUGBOARD CONFIGURATION */

  cout << "Loading plugboard configuration... ";
  Plugboard plugboard;

  check = plugboard.configure(argv[1]);
  switch (check) {
  case 3:
    cerr << "Failed!" << endl;
    cerr << "Configuration file contains a number not between 0 and 25!" << endl;
    return INVALID_INDEX;
  case 4:
    cerr << "Failed!" << endl;
    cerr << "Configuration file contains a non-numeric character!" << endl;
    return NON_NUMERIC_CHARACTER;
  case 5:
    cerr << "Failed!" << endl;
    cerr << "Impossible plugboard configuration!" << endl;
    cerr << "A contact may not be connected to itself, "
	 << "or to more than one other contacts!" << endl;
    return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
  case 6:
    cerr << "Failed!" << endl;
    cerr << "Incorrect number of plugboard parameters!" << endl;
    cerr << "The configuration file must contain "
	 << "an even number of numbers!" << endl;
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  case 11:
    cerr << "Failed!" << endl;
    cerr << "Error opening configuration file!" << endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  default:
    break;
  }

  cout << "Success!" << endl;
  cout << "Plugboard configured using \"" << argv[1] << "\".\n\n";

  /* END OF PLUGBOARD CONFIGURATION */

  if (argc == 2) {
    cerr << "Insufficient number of parameters!" << endl;
    cerr << "In order to set up the Enigma machine, a configuration file each for the wiring map of the plugboard and of the reflector is needed at the minimum." << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }

  /* REFLECTOR CONFIGURATION */

  cout << "Loading reflector configuration... ";
  Reflector reflector;

  check = reflector.configure(argv[2]);
  if (check > 0) {
    if (check == 3) {
      cerr << "Failed!" << endl;
      cerr << "Configuration file contains a number not between 0 and 25!" << endl;
      return INVALID_INDEX;
    }
    else if (check == 4) {
      cerr << "Failed!" << endl;
      cerr << "Configuration file contains a non-numeric character!" << endl;
      return NON_NUMERIC_CHARACTER;
    }
    else if (check == 9) {
      cerr << "Failed!" << endl;
      cerr << "Impossible reflector configuration!" << endl;
      cerr << "A contact may not be connected to itself, "
	   << "or to more than one other contacts!" << endl;
      return INVALID_REFLECTOR_MAPPING;
    }
    else if (check == 10) {
      cerr << "Failed!" << endl;
      cerr << "Incorrect number of reflector parameters!" << endl;
      cerr << "The configuration file must contain exactly 13 pairs of numbers!" << endl;
      return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }
    else if (check == 11) {
      cerr << "Failed!" << endl;
      cerr << "Error opening configuration file!" << endl;
      return ERROR_OPENING_CONFIGURATION_FILE;
    }
  }

  cout << "Success!" << endl;
  cout << "Reflector configured using \"" << argv[2] << "\".\n\n";

  /* END OF REFLECTOR CONFIGURATION */

  if (argc == 4) {
    cerr << "Insufficient number of parameters!" << endl;
    cerr << "In order to set up the Enigma machine, a configuration file each "
	 << "for the wiring map of the plugboard and of the reflector is "
	 << "needed at the minimum." << endl;
    cerr << "If you wish to configure at least one rotor, please include "
	 << "a configuration file for the wiring map of each rotor and "
	 << "a configuration file for their initial starting positions." << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }

  /* ROTOR CONFIGURATION */

  if (argc > 4) {
    cout << "Loading rotor configuration... ";
    Rotor rotor[argc - 4];

    for (int i=0; i < (argc - 4); i++) {
      check = rotor[i].configure(argv[i+2]);
      if (check > 0) {
	if (check == 3) {
	  cerr << "Failed!" << endl;
	  cerr << "Configuration file contains a number not between 0 and 25!" << endl;
	  return INVALID_INDEX;
	}
	else if (check == 4) {
	  cerr << "Failed!" << endl;
	  cerr << "Configuration file contains a non-numeric character!" << endl;
	  return NON_NUMERIC_CHARACTER;
	}
	else if (check == 7) {
	  cerr << "Failed!" << endl;
	  cerr << "Invalid rotor mapping!" << endl;
	  cerr << "No two inputs may be mapped to the same output! "
	       << "For all inputs, each input must be mapped to some output! "
	       << "When listing the turnover notches positions, "
	       << "please list each position only once!" << endl;
	  return INVALID_ROTOR_MAPPING;
	}
	else if (check == 11) {
	  cerr << "Failed!" << endl;
	  cerr << "Error opening configuration file!" << endl;
	  return ERROR_OPENING_CONFIGURATION_FILE;
	}
      }
    }

    // Set rotor positions

    check = set_rotor_position(argc - 4, rotor, argv[argc - 1]);
    switch (check) {
    case 3:
      cerr << "Failed!" << endl;
      cerr << "Configuration file contains a number not between 0 and 25!" << endl;
      return INVALID_INDEX;
    case 4:
      cerr << "Failed!" << endl;
      cerr << "Configuration file contains a non-numeric character!" << endl;
      return NON_NUMERIC_CHARACTER;
    case 8:
      cerr << "Failed!" << endl;
      cerr << "No rotor starting position!" << endl;
      cerr << "Please specify the starting position for each rotor used!" << endl;
      return NO_ROTOR_STARTING_POSITION;
    case 11:
	cerr << "Failed!" << endl;
	cerr << "Error opening configuration file!" << endl;
	return ERROR_OPENING_CONFIGURATION_FILE;
    default:
      break;
    }

    cout << "Success!" << endl;

    if (argc - 4 == 1) {
      cout << "One rotor configured using \"" << argv[3] << "\".\n";
      cout << "Its position is configured using \"" << argv[4] << "\".\n\n";
    }

    else if (argc - 4 == 2) {
      cout << "2 rotors configured using \"" << argv[3]
	   << "\" and \"" << argv[4] << "\".\n";
      cout << "Their positions are configured using \"" << argv[argc - 1] << "\".\n\n";
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

  /* END OF ROTOR CONFIGURATION */

  cout << "Welcome to the Enigma machine!" << endl
       << "This machine will encrypt your message a letter at a time." << endl;

  // NEED TO WORK ON INPUTTING A STRING AT ONCE
  // ------------------------------------------
  char plaintext;

  cout << "Please input a character in uppercase to encrypt : ";
  cin >> plaintext;
  cout << endl;
  if (plaintext < 65 || plaintext > 90) {
    cerr << "Invalid input character!" << endl;
    cerr << "The Enigma machine may only encrypt uppercase letters." << endl;
    return INVALID_INPUT_CHARACTER;
  }

  int plaintext_index = plaintext - 65;

  // COUT JUST FOR MYSELF

  int ciphertext_index;
  ciphertext_index = plugboard.encrypt(plaintext_index);
  cout << ciphertext_index << endl;
  ciphertext_index = reflector.encrypt(ciphertext_index);
  cout << ciphertext_index << endl;
  // if argc > 4, we pass on to the rotors
  ciphertext_index = plugboard.encrypt(ciphertext_index);
  cout << ciphertext_index << endl;

  char ciphertext = char(ciphertext_index) + 65;

  cout << plaintext << " has been successfully encrypted to " 
       << ciphertext << endl;

  return NO_ERROR;
}
