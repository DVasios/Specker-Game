#ifndef MOVE
#define MOVE


#include <iostream>
using namespace std;

class Move {
public:
  Move(int sh, int sc, int th, int tc);

  int getSource() const;
  int getSourceCoins() const;
  int getTarget() const;
  int getTargetCoins() const;

  friend ostream & operator << (ostream &out, const Move &move);

private:
  int source, source_coins, target, target_coins;
};

#endif