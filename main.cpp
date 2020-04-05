#include "state.hpp"
#include "move.hpp"
#include "player.hpp"
#include <string>

#include <iostream>
using namespace std;


int main() {

    int k[4] = { 9, 14, 3, 8 };

    State s(4, k);
    // cout << s << endl;
    
    // Move m1(2,4,0,3);
    // s.next(m1);

    // cout << m1 << endl;
    // cout << s << endl;

    // Move m2(3,5,0,0);
    // s.next(m2);
    // cout << m2 << endl;
    // cout << s << endl;

    // const string nm1 = "Giannis";
    // Greedy g1(nm1);

    // s.next(g1.play(s));

    // cout << "Move of Greedy player Giannis: " << s << endl;

    // const string nm2 = "Vaggelis";
    // Spartan g2(nm2);

    // s.next(g2.play(s));
    // s.next(g2.play(s));
    // s.next(g2.play(s));
    // s.next(g2.play(s));
    // s.next(g2.play(s));
    // s.next(g2.play(s));
    // s.next(g2.play(s));

    // cout << "Move of Spartan player Vaggelis: " << s << endl;

    // const string nm3 = "Dimitris";
    // Sneaky g3(nm3);

    // s.next(g3.play(s));
    // s.next(g3.play(s));
    // s.next(g3.play(s));

    // cout << "Move of Sneaky player Dimitris: " << s << endl;

    // cout << endl << endl;
    // int x = 9;
    // x = x / 2;
    // cout << x << endl;
    
    Righteous r("Foivos");
    
    Move m(0,0,0,0);

    while(!s.winning()) {
        
        m = r.play(s);
        cout << m << endl;
        
        s.next(m);
        cout << s << endl;

    }

    


}