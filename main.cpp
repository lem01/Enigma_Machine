/*--------------------------------------------------------------------------+
|  File Name:    main.cpp                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Description:  Enigma machine to encrypt and decrypt messages             |
|  Date:         4 November 2015                                            |
+--------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "errors.h"
#include "helper.h"

using namespace std;

int main(int argc, char **argv) {

  // Checking input from the command line
  cout << "The number of argc is : " << argc << endl;
  for (int i=0; i<argc; i++)
    cout << "The content of argv[" << i << "] is " << argv[i] << endl;
  cout << endl;

  if (argc == 1) {
    cerr << "Insufficient number of parameters!" << endl;
    cerr << "In order to set up the Enigma machine, a configuration file each for the wiring map of the plugboard and of the reflector is needed at the minimum." << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }

  cout << "Loading plugboard configuration... ";
  //some tests
  cout << "Success!" << endl;
  cout << "Plugboard configured using \"" << argv[1] << "\".\n\n";

  if (argc == 2) {
    cerr << "Insufficient number of parameters!" << endl;
    cerr << "In order to set up the Enigma machine, a configuration file each for the wiring map of the plugboard and of the reflector is needed at the minimum." << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }

  cout << "Loading reflector configuration... ";
  //some tests
  cout << "Success!" << endl;
  cout << "Reflector configured using \"" << argv[2] << "\".\n\n";

  if (argc == 3) {
    cerr << "Insufficient number of parameters!" << endl;
    cerr << "In order to set up the Enigma machine, a configuration file each for the wiring map of the plugboard and of the reflector is needed at the minimum." << endl;
    cerr << "If you wish to configure at least one rotor, please include a configuration file for the wiring map of each rotor and a configuration file for their initial starting positions." << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }

  if (argc > 3) {
    cout << "Loading rotor configuration... ";
    //some tests
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



  cout << "Welcome to the Enigma machine!" << endl
       << "This machine will encrypt your message a letter at a time." << endl;

  char plaintext;

  cout << "Please input a capital letter to encrypt : ";
  cin >> plaintext;
  cout << endl;

  





  return 0;
}
