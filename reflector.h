#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector {
private:
  int mapping[26];
public:
  Reflector();
  int configure(const char *filename);
  int encrypt(int &letter);
};

#endif
