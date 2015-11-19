#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "rotor.h"

using namespace std;

Rotor::Rotor() {
  for (int i=0; i<26; i++) {
    this->mapping[i]=i;
  }
  notch_ptr = NULL;
  number_of_notch = 0;
  top_position = 0;
}

int Rotor::configure(const char *filename) {
  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    return 11;

  string string;
  int number = 0;

  for (int i=0; i<26; i++) {
    if (!(in_stream >> string))
      return 7;
 
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number = atoi(string.c_str());

    if ((i > 0) && is_repeated(number, i, this->mapping))
      return 7;
    this->mapping[i] = number;
  }

  int *temp_notch;
  temp_notch = new int[26];

  for (int i=0; in_stream >> string; i++) {
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number = atoi(string.c_str());

    if ((i > 0) && is_repeated(number, i, temp_notch))
      return 7;
    temp_notch[i] = number;
    number_of_notch++;
  }
  in_stream.close();

  this->notch_ptr = new int[number_of_notch];

  for(int i=0; i < number_of_notch; i++) {
    this->notch_ptr[i] = temp_notch[i];
  }

  delete [] temp_notch;
  return 0;
}

int Rotor::encrypt(int &letter) {
  this->rotate();
  return this->mapping[letter];

}

void Rotor::rotate() {
  this->top_position++;
  int temp_map = mapping[0];
  for (int i=0; i<25; i++) {
    if (mapping[i+1] == 0)
      mapping[i] = 25;
    else
      mapping[i] = mapping[i+1] - 1;
  }
  if (temp_map == 0)
    mapping[25] = 25;
  else
    mapping[25] = temp_map - 1;
}
