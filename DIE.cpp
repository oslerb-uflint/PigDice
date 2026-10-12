
#include <random>
#include "DIE.h"


Die::Die() {
    m_dieValue = 0;
    random_device rd;
    m_gen = mt19937(rd());
    m_distribution = uniform_int_distribution<int>(1,6);
}


void Die::rollDie() {
    m_dieValue = m_distribution(m_gen);
}
int Die::getValue() {
    return m_dieValue;
}