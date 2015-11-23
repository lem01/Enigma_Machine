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
  no_of_rotor = 0;
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
	    no_of_rotor = argc - 4;
	    /*
	    for (int i=0; i < (argc - 4); i++)
	      rotor[i] = NULL; // Initialise each pointer before configuring each rotor
	    */
	    for (int i=0; ((i < (argc - 4)) && (good == 0)); i++) {
	      rotor[i] = new Rotor(argv[i+3]);
	      good = rotor[i]->good;
	      /*
	      if (good != 0) {
		for (int j=0; j<=i; j++)
		  delete rotor[j];
		delete [] *rotor;
	      }
	      */
	    }

	    if (good == 0)
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
	  if (good == 0)
	    cout << "Enigma has been successfully configured!\n\n";
	}
      }
    }
  }
}
/*
Enigma::~Enigma() {
  delete [] *rotor;
}
*/
int Enigma::encrypt(int &letter) {
  int encoded_letter = 0;

  encoded_letter = plugboard->encrypt(letter);
  cout << endl << encoded_letter << endl;
  if (no_of_rotor > 0) {
    rotor[no_of_rotor -1]->rotate();
    for (int i = no_of_rotor - 1; i >= 0; i--) {
      encoded_letter = rotor[i]->encrypt_rtl(encoded_letter);
      cout << encoded_letter << endl;
    }
  }
  encoded_letter = reflector->encrypt(encoded_letter);
  cout << encoded_letter << endl;
  if (no_of_rotor > 0) {
    for (int i = 0; i <= no_of_rotor - 1; i++) {
      encoded_letter = rotor[i]->encrypt_ltr(encoded_letter);
      cout << encoded_letter << endl;
      if (i>0) {
	for (int j=0; j < (rotor[i]->number_of_notch); j++) {
	  if (rotor[i]->top_position == rotor[i]->notch[j])
	    rotor[i-1]->rotate();
	}
      }
    }
  }
  encoded_letter = plugboard->encrypt(encoded_letter);
  cout << encoded_letter << endl;
  return encoded_letter;
}
/*
bool Enigma::encrypt(const string &plaintext) {
  stringstream spell (plaintext);
  char letter;
  spell >> ws >> letter;
  if (letter < 65 || plaintext > 90)
    return 0;


}
*/

  // need to check reflector file, eof
