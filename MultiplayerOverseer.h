//
// Created by osler on 11/12/2026.
//

#ifndef PIGDICE_MULTIPLAYEROVERSEER_H
#define PIGDICE_MULTIPLAYEROVERSEER_H
#include "PDGameV2.h"
#include <vector>


class MultiplayerOverseer {
    vector<PDGameV2> m_games = vector<PDGameV2>();
    bool m_gameOver = false;

    public:
    MultiplayerOverseer();
    ~MultiplayerOverseer();
    private:
    vector<string> getPlayers();
    void setupGames(int numGames);
    void runCompetition();
    void printScoreboard();


};


#endif //PIGDICE_MULTIPLAYEROVERSEER_H
