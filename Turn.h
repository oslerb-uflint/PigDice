//
// Created by osler on 10/12/2026.
//

#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include "DIE.h"


class Turn {
    private:
        int m_turnCount;
        int m_scoreThisTurn;
        bool m_turnOver;
        char m_choice;
        Die m_die;
    public:
        Turn();
        void takeTurn(int GameScore);
        int getScoreThisTurn();
        void resetTurnOver();
        int getTurnCount();
    private:
        void roll();
        void hold();
        void getChoice();

};


#endif //PIGDICE_TURN_H
