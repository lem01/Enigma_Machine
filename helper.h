#ifndef HELPER_H
#define HELPER_H


/* Function to confirm that all the characters in the string STRING is numeric */
bool is_numeric(const std::string &string);

/* Function to confirm that all the numeric characters in the string STRING is a number between 0 and 25 */
bool is_valid(const std::string &string);

/* Function to validate the configuration file FILENAME. If it fails any of the error checks, it returns its error code */
int check_config(const char *filename);


#endif
