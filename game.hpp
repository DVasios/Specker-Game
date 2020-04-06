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
    int top_coins, top_players, game_heaps, game_players, current_array_size;
    Player** pl;
public:
    // Constructor
    Game(int heaps, int players) {
        // Coins
        game_heaps = heaps;
        cns = new int[heaps];
        top_coins = 0;
        top_players = 0;

        // Players
        game_players = players;
        current_array_size = 0;
        pl = new Player*[players];
    }

    // Destructor 
    ~Game() {
        delete[] cns;
        top_coins = game_heaps = game_players = 0;
    }

    // Addition of a heap
    void addHeap(int coins) throw() 
    {    
        if( top_coins > game_heaps) throw logic_error("You cannot add another heap");
        else {
            cns[top_coins] = coins;
            top_coins++;       
        }
    }

    // Addition of a player
    void addPlayer(Player *player) throw() {
        if(current_array_size <= game_players){
            pl[top_players] = player;
            top_players++;
            current_array_size++;

            
        }
        else throw logic_error("You cannot add another player");
    }
    
    // Procedure of the game 
    void play(ostream &out) throw() {
        
        // Declaration of the initial state and move of the game
        State s(game_heaps, cns);
        Move m(0, 0, 0, 0);

        int sum = 0;
        while (!s.winning()) {
            // Current State
            out << "State: " << s << endl;
            
            // Next move of the player
            m = pl[sum]->play(s);
            s.next(m);
            
            out << *pl[sum] << " " << m << endl;
            
            if ( sum < (game_players - 1) && !s.winning()) sum++;
            else if(sum == (game_players-1) && !s.winning()) sum = 0;
       }

       out << "State: " << s << endl;

       out << *pl[sum] << " wins" << endl;
    }
};
