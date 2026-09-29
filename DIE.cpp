
#include <random>
#include "DIE.h"


Die::Die() {
    m_dieValue = 0;
    m_numSides = 6;
    random_device rd;
    m_gen = mt19937(rd());
    m_distribution = uniform_int_distribution<int>(1,m_numSides);
}

void Die::setNumSides(int numSides) {
    switch (numSides) {
        case 2:
            m_numSides = 2;
            break;
        case 4:
            m_numSides = 4;
            break;
        case 8:
            m_numSides = 8;
            break;
        case 12:
            m_numSides = 12;
            break;
        default:
            m_numSides = 6;
    }
    m_distribution = uniform_int_distribution<int>(1,m_numSides);
};

int Die::getNumSides() {
    return m_numSides;
}

void Die::rollDie() {
    m_dieValue = m_distribution(m_gen);
}
int Die::getValue() {
    return m_dieValue;
}