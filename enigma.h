#ifndef ENIGMA_H
#define ENIGMA_H

class Plugboard {
private:
  int mapping[26];
public:
  Plugboard();
  int configure(const char *filename);
  int encrypt(int letter);
};

class Reflector {
private:
  int mapping[26];
public:
  Reflector();
  int configure(const char *filename);
  int encrypt(int letter);
};

class Rotor {
private:
  int mapping[26];
  int top_position;
  int notch;
public:
  Rotor();
  

};



#endif
