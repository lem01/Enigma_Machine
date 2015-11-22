#include "helper.h"
using namespace std;

bool is_numeric(const string &string) {
  for (int i=0; i < int(string.length()); i++) {
    if (!isdigit(string[i]))
      return 0;
  }
  return 1;
}

bool is_valid(const string &string) {
  int number = string_to_int(string);
  if (number > 25)
    return 0;
  else
    return 1;
}

int string_to_int(const string &string) {
  int number;
  stringstream convert(string);
  convert >> number;
  return number;
}

bool is_repeated(const int &number, const int &n, const int mapping[26]) {
  for (int i=0; i<n; i++) {
    if (mapping[i] == number)
      return 1;
  }
  return 0;
}
