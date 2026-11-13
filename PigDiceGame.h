//
// Created by osler on 9/30/2026.
//

#ifndef PIGDICE_PIGDICEGAME_H
#define PIGDICE_PIGDICEGAME_H
#include "Turn.h"

class PigDiceGame {
    protected:
        Turn m_turn;
        bool m_gameOver;
        int m_gameScore;
    public:
        PigDiceGame();
        int getGameScore();
    protected:
        void playGame();
    private:
        void displayRules();
        void endGame();

};


#endif //PIGDICE_PIGDICEGAME_H
