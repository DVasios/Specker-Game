#ifndef STATE
#define STATE

#include "move.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>

using namespace std;

class State {
public:
  State(int h, const int c[]);
  ~State();

  void next(const Move &move) throw();
  bool winning() const;

  int getHeaps() const;
  int getCoins(int h) const throw();

  friend ostream & operator << (ostream &out, const State &state);

private:
  int heaps;
  int *coins;

};

#endif