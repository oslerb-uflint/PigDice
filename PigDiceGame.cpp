//
// Created by osler on 9/30/2026.
//

#include "PigDiceGame.h"
#include "Turn.h"
#include <iostream>
using namespace std;

PigDiceGame::PigDiceGame() {
    m_turn = Turn();
    m_gameScore = 0;
    m_gameOver = false;
    playGame();
}

void PigDiceGame::displayRules() {
    cout << "Let's Play PIG Dice!"<<endl<<endl;
    cout<<"* See how many turns it takes you to get to 20 points."<<endl;
    cout<<"* Turn ends when you hold or roll a 1."<<endl;
    cout<<"* If you roll a 1, you lose all points for the turn."<<endl;
    cout<<"* If you hold, you bank all points for the turn to the game score."<<endl;
}

void PigDiceGame::playGame() {
    displayRules();
    while (m_gameOver == false) {
        m_turn.resetTurnOver();
        m_turn.takeTurn(m_gameScore);
        m_gameScore += m_turn.getScoreThisTurn();
        if (m_gameScore >= 20) {
            m_gameOver = true;
        }
    }
    endGame();
}


void PigDiceGame::endGame() {
    cout<<endl<<"You finished with a final score of "<<m_gameScore<<" in "<<m_turn.getTurnCount()<<" turns!"<<endl;
    cout<<"Thanks for playing PIG Dice!"<<endl;
}
