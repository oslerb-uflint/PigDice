//
// Created by osler on 9/30/2026.
//

#ifndef PIGDICE_PIGDICEGAME_H
#define PIGDICE_PIGDICEGAME_H
#include "Turn.h"

class PigDiceGame {
    private:
        Turn m_turn;
        int m_gameScore;
        bool m_gameOver;

    public:
        PigDiceGame();
    private:
        void displayRules();
        void playGame();
        void endGame();

};


#endif //PIGDICE_PIGDICEGAME_H
