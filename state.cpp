#include "state.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

// Constructor
State::State(int h, const int c[]) {
    
    heaps = h;
    coins = new int[h];
    int i;
    for(i = 0; i < h ; i++){
        coins[i] = c[i];
    }
}
// Destructor
State::~State() {
    delete [] coins;
    heaps = 0;
}

// Execution of move
void State::next(const Move &move) throw() {
    
    // Take sc coins from heap sh
    if( move.getSourceCoins() > coins[move.getSource()] || move.getSourceCoins() < 0) {
        throw logic_error("invalid heap");
    }
    else
    {
        coins[move.getSource()] -= move.getSourceCoins(); 
    }

    // Put tc coin to heap th
    if( move.getTargetCoins() > move.getSourceCoins() || move.getTargetCoins() < 0) {
        throw logic_error("invalid heap");
    }
    else
    {
        coins[move.getTarget()] += move.getTargetCoins();
    }
}

// Whether player wins or not
bool State::winning() const {
    bool k = true;
    int i;
    for(i = 0; i < heaps; i++) {
        if( coins[i] != 0) {
            k = false;
            break;
        }
    }
    return k;
}

// Getters
int State::getHeaps() const { return heaps;}

int State::getCoins(int h) const throw(){

    if ( h < 0 || h > heaps) throw logic_error("invalid heap");
    else
      return coins[h];
}

// Print of the state
ostream & operator << (ostream &out, const State &state) {
    int i;
    for(i = 0; i < state.heaps ;i++){
        if( i != 0) out << ", ";
        out << state.coins[i];
    }
    return out;
}