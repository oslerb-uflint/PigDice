#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

#include <random>
using namespace std;

class Die {
    int m_dieValue;
    int m_numSides;
    uniform_int_distribution<int> m_distribution;
    mt19937 m_gen;

public:
    Die();

    void setNumSides(int numSides);

    int getNumSides();

    void rollDie();

    int getValue();
};




#endif //PIGDICE_DIE_H
