//
// Created by osler on 10/12/2026.
//

#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include "DIE.h"

class PigDiceGame;

class Turn {
    private:
        int m_turnCount;
        int m_scoreThisTurn;
        bool m_turnOver;
        char m_choice;
        Die m_die;
        PigDiceGame* m_gamePointer;
    public:
        Turn();
        void takeTurn();
        int getScoreThisTurn();
        void resetTurnOver();
        int getTurnCount();
        void setGamePointer(PigDiceGame* gamePointer);
    private:
        void roll();
        void hold();
        void getChoice();
        int getCurrentGameScore();

};


#endif //PIGDICE_TURN_H
