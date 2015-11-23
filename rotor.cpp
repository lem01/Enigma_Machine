#include "rotor.h"
using namespace std;

Rotor::Rotor(const char *filename) {
  good = 0;
  for (int i=0; i<26; i++) {
    mapping[0][i]=i;
    mapping[1][i]=i;
  }
  notch = NULL;
  number_of_notch = 0;
  top_position = 0;
  // Initialised to default values before being configured with FILENAME

  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    good = 11;
  else {
    string string;
    int number = 0;

    for (int i=0; (i<26) && (good == 0); i++) {
      if (!(in_stream >> string))
	good = 7;
      else if (!is_numeric(string))
	good = 4;
      else if (!is_valid(string))
	good = 3;
      else {
	number = string_to_int(string);
	if ((i > 0) && is_repeated(number, i, mapping[1]))
	  good = 7;
	else {
	  mapping[1][i] = number;
	}
      }
    }
    if (good == 0) {
      int *temp_notch;
      temp_notch = new int[26];

      for (int i=0; (in_stream >> string) && (good == 0); i++) {
	if (!is_numeric(string))
	  good = 4;
	else if (!is_valid(string))
	  good = 3;
	else {
	  number = string_to_int(string);
	  if ((i > 0) && is_repeated(number, i, temp_notch))
	    good = 7;
	  else {
	  temp_notch[i] = number;
	  number_of_notch++;
	  }
	}
      }

      if (good == 0) {
	in_stream.close();

	notch = new int[number_of_notch];

	for(int i=0; i < number_of_notch; i++) {
	  notch[i] = temp_notch[i];
	}

	delete [] temp_notch;
      }
    }
  }
}

Rotor::~Rotor() {
  delete [] notch;
}

int set_rotor_position(Rotor *rotor, int no_of_rotors, const char *filename) {
  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    return 11;

  string string;

  for (int i=0; i < no_of_rotors; i++) {
    if (!(in_stream >> string))
      return 8;
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    rotor[i].top_position = string_to_int(string);
  }

  return 0;
}

int Rotor::encrypt_rtl(const int &letter) {
  return mapping[1][letter];
}

int Rotor::encrypt_ltr(const int &letter) {
  for (int i=0; i<26; i++) {
    if (mapping[1][i] == letter)
      return mapping[0][i];
  }
  return letter;
}

void Rotor::rotate() {
  top_position = (top_position + 1) % 26;
  int temp_map = mapping[0][0];
  for (int i=0; i<25; i++) {
    mapping[0][i] = (mapping[0][i+1] - 1) % 26;
  }
  mapping[0][25] = (temp_map - 1) % 26;
}
