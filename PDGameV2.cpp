using namespace std;

#include "PDGameV2.h"
#include <iostream>

void PDGameV2::displayRules() {
    cout<<"Let's Play PIG Dice!"<<endl<<endl;
    cout<<"* See which player will reach 50 points in the fewest turns.\n* Turn ends when you hold or roll a 1"
          "\n* If you roll a 1, you lose all points for the turn.\n* If you hold, you save all points for the turn."<<endl<<endl;
}

string PDGameV2::getName() {
    return m_name;
}
void PDGameV2::playGame() {
    m_turn.takeTurn();
    m_gameScore += m_turn.getScoreThisTurn();
    m_turn.resetTurnOver();
};
int PDGameV2::getTurnCount() {
    return m_turn.getTurnCount();
}
bool PDGameV2::operator<(PDGameV2 &a){
    return this->getGameScore() < a.getGameScore();
};