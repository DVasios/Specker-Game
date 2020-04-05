#include "move.hpp"
#include "player.hpp"
#include "state.hpp"

#include <iostream>
#include <vector>
using namespace std;

class Game
{
private:
    int *cns;
    int top, hps, plrs;
    vector<Player> pl;
public:
    // Constructor
    Game(int heaps, int players) {
        hps = heaps;
        plrs = players;
        cns = new int[heaps];
        top = 0;
    }

    // Destructor 
    ~Game() {
        delete[] cns;
        p = hps = plrs = 0;
        pl.clear();
    }

    // Addition of a heap
    void addHeap(int coins) throw(logic_error) 
    {    
        if( top > hps) throw logic_error("You cannot add another heap");
        else {
            cns[top] = coins;
            top++;
            
        }
    }

    // Addition of a player
    void addPlayer(Player *player) throw(logic_error) {
        if(pl.size() <= plrs){
            pl.push_back(*player);
        }
        else throw logic_error("You cannot add another player");
    }
    
    void play(ostream &out) throw(logic_error);
};
