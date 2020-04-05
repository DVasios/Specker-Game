#include <iostream>
#include "move.hpp"

using namespace std;

//Constructor
Move::Move(int sh, int sc, int th, int tc) {
    source = sh;
    source_coins = sc;
    target = th;
    target_coins = tc;
}

//Getters
int Move::getSource() const{ return source; }
int Move::getSourceCoins() const{ return source_coins; }
int Move::getTarget() const{ return target; }
int Move::getTargetCoins() const{ return target_coins; }

//Ostream
ostream & operator << (ostream &out, const Move &move){
    out << "takes " << move.getSourceCoins() << " from heap " << move.getSource();
    
    if( move.getTargetCoins() != 0)
      out << " and puts " << move.getTargetCoins() << " coins to heap " << move.getTarget();
    else
      out << " and puts nothing";
    
    return out;
}