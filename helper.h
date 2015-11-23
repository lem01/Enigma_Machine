/*--------------------------------------------------------------------------+
|  HEADER FILE                                                              |
|  File Name:    helper.h                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Date:         23 November 2015                                           |
+--------------------------------------------------------------------------*/

#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include <cstdlib>
using namespace std;

/* Function to confirm that all the characters in the string STRING is numeric */
bool is_numeric(const std::string &string);

/* Function to confirm that all the numeric characters in the string STRING is
   a number between 0 and 25 */
bool is_valid(const std::string &string);

/* Function to convert STRING into an integer */
int string_to_int(const string &string);

/* Function to confirm that NUMBER has already existed in the first N entries
   of the array MAPPING */
bool is_repeated(const int &number, const int &n, const int mapping[26]);

/* Function to compute NUMBER mod 26 */
int mod(const int &number);

#endif
