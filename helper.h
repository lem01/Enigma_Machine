#ifndef HELPER_H
#define HELPER_H

/* Function to confirm that all the characters in the string STRING is numeric */
bool is_numeric(const std::string &string);

/* Function to confirm that all the numeric characters in the string STRING is
   a number between 0 and 25 */
bool is_valid(const std::string &string);

/* Function to confirm that NUMBER has already existed in the first N entries
   of the array MAPPING */
bool is_repeated(const int &number, const int &n, const int mapping[26]);


// may want function for is_numeric and is_valid

#endif
