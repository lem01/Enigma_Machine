#include "reflector.h"
using namespace std;

Reflector::Reflector() {
  for (int i=0; i<26; i++) {
    this->mapping[i]=i;
  }
}

int Reflector::configure(const char *filename) {
  ifstream in_stream;
  in_stream.open(filename);

  if (!in_stream)
    return 11;

  string string;
  int number_a = 0;
  int number_b = 0;

  for (int i=0; i<13; i++) {
    if (!(in_stream >> string)) // No more input
      return 10;
 
    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number_a = atoi(string.c_str());
    /* If this->mapping[i] != i, then we have previously configured a reflector
       mapping from i to some other number, and now we are about to configure
       another reflector mapping from i to yet another number */
    if (this->mapping[number_a] != number_a)
      return 9;

    if (!(in_stream >> string)) // No more input
      return 10;

    if (!is_numeric(string))
      return 4;
    if (!is_valid(string))
      return 3;
    number_b = atoi(string.c_str());
    if (this->mapping[number_b] != number_b)
      return 9;
  
    if (number_a == number_b)
      return 5;

    // All checks passed
    this->mapping[number_a] = number_b;
    this->mapping[number_b] = number_a;
  }

  // The configuration file has more characters than required
  if (in_stream >> string)
    return 10;

  in_stream.close();

  return 0;
}

int Reflector::encrypt(int &letter) {
  return this->mapping[letter];
}
