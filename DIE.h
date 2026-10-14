#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

#include <random>
using namespace std;

class Die {
    int m_dieValue;
    uniform_int_distribution<int> m_distribution;
    mt19937 m_gen;

public:
    Die();

    void rollDie();

    int getValue();
};




#endif //PIGDICE_DIE_H
