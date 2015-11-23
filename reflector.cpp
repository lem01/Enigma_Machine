#include "reflector.h"
using namespace std;

Reflector::Reflector(const char *filename) {
  good = 0;
  for (int i=0; i<26; i++) {
    mapping[i]=i;
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

    while ((good == 0) && (in_stream >> string)) {
      count++;
      if (count > 13) // Too many input
	good = 10;
      else if (!is_numeric(string))
	good = 4;
      else if (!is_valid(string))
	good = 3;
      else {
	number_a = string_to_int(string);
	/* If mapping[i] != i, then we have previously configured a reflector
	   mapping from i to some other number, and now we are about to configure
	   another reflector mapping from i to yet another number */
	if (mapping[number_a] != number_a)
	  good = 9;
	else if ((count <= 13) && !(in_stream >> string)) // No more input
	  good = 10;
	else if (!is_numeric(string))
	  good = 4;
	else if (!is_valid(string))
	  good = 3;
	else {
	  number_b = string_to_int(string);
	  if (mapping[number_b] != number_b)
	    good = 9;
  	  else if (number_a == number_b)
	    good = 9;
	  else {
	    // All checks passed
	    mapping[number_a] = number_b;
	    mapping[number_b] = number_a;
	  }
	}
      }
    }
    if ((count < 13)) // Not enough input
      good = 10;
  }
  in_stream.close();
}

int Reflector::encrypt(const int &letter) {
  return mapping[letter];
}
