#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include "move.hpp"
#include "state.hpp"

using namespace std;

class Player
{
protected:
    const string name;
public:
    Player(const string &n) : name(n){}
    virtual ~Player() {};

    virtual const string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (ostream &out, const Player &player){
        out << player.getType() << " player " << player.name;
        return out;
    }
};

class GreedyPlayer : public Player {
private:
     const string type = "Greedy";
public:
    GreedyPlayer(const string &n) : Player(n) {}
    ~GreedyPlayer() {};
    
    const string & getType() const {return type;}

    // Implementation of function play
    Move play(const State &s) {
        int p = s.getCoins(0);

        int i,heap = 0;
        for(i=0; i < s.getHeaps() -1 ; i++){
            if( s.getCoins(i+1) > p) {
                p = s.getCoins(i+1);
                heap = i+1;
            }
        }

        Move m(heap, p, 0, 0);
        return m;
    }
};

class SpartanPlayer : public Player {
private:
    const string type = "Spartan";
public:
    SpartanPlayer(const string &n) : Player(n) {}
    ~SpartanPlayer() {};

    const string & getType() const {return type;}

    Move play(const State &s) {
        int p = s.getCoins(0);

        int i, heap = 0;
        for(i=0; i < s.getHeaps()-1; i++){
            if( s.getCoins(i+1) > p){
                p = s.getCoins(i+1);
                heap = i+1;
            }
        }

        Move m(heap, 1, 0, 0);
        return m;
    }
};

class SneakyPlayer : public Player {
private:
    const string type = "Sneaky";
public:
    SneakyPlayer(const string &n) : Player(n) {}
    ~SneakyPlayer() {};

    const string & getType() const {return type;}

    Move play(const State &s) {
        int p = s.getCoins(0);

        int i, heap = 0;
        for(i=0; i < s.getHeaps()-1; i++){
            if( p == 0 || (s.getCoins(i+1) < p && s.getCoins(i+1) != 0)) {
                p = s.getCoins(i+1);
                heap = i+1;
            }
        }

        Move m(heap, p, 0, 0);
        return m;
    }
};

class RighteousPlayer : public Player {
private:
    const string type = "Righteous";
public:
    RighteousPlayer(const string &n) : Player(n) {}
    ~RighteousPlayer() {};
 
    const string & getType() const {return type;}

    Move play(const State &s) {
        int max = s.getCoins(0), min = s.getCoins(0);

        int i, heap_max = 0, heap_min = 0;
        for(i=0; i < s.getHeaps()-1; i++){
            // Chooses the heap with the most coins
            if( s.getCoins(i+1) > max){
                max = s.getCoins(i+1);
                heap_max = i+1;
            }
            // Chooses the heap with the least coins
            if( s.getCoins(i+1) < min ){
                min = s.getCoins(i+1);
                heap_min = i+1;
            }
        }
        int rght_move_max;
        if( max % 2 == 0) rght_move_max = max / 2;
        else if ( max % 2 != 0) rght_move_max = max / 2 + 1;
        else rght_move_max = 1;


        Move m(heap_max, rght_move_max, heap_min, rght_move_max-1);
        return m; 
    }
};

#endif