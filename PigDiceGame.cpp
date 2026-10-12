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
}

void PigDiceGame::displayRules() {
    cout << "Let's Play PIG Dice!"<<endl<<endl;
    cout<<"* See how many turns it takes you to get to 20 points."<<endl;
    cout<<"* Turn ends when you hold or roll a 1."<<endl;
    cout<<"* If you roll a 1, you lose all points for the turn."<<endl;
    cout<<"* If you hold, you bank all points for the turn to the game score."<<endl;
}

void PigDiceGame::playGame() {

}


void PigDiceGame::endGame() {

}
