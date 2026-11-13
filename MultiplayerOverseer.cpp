
using namespace std;
#include "MultiplayerOverseer.h"
#include "PDGameV2.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

MultiplayerOverseer::MultiplayerOverseer() {
    int choice =0;
    while (true) {
        choice = 0;
        cout << "How many people are playing? ";
        try {
            cin>>choice;
            if (cin.fail()) {
                throw invalid_argument("");
            };
            if (choice>5 || choice<1) {
                throw invalid_argument("");
            }
            break;
        }
        catch (invalid_argument& e) {
            cout << "Invalid argument, please enter an integer between 1 and 5" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        catch (...) {
            cout << "Unexpected error. Please reenter the value" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    };
    setupGames(choice);
    m_games[0].displayRules();
    runCompetition();
};
MultiplayerOverseer::~MultiplayerOverseer() {
    m_games.clear();
};
vector<string> MultiplayerOverseer::getPlayers() {
    vector<string> players;
    for (PDGameV2 player : m_games) {
        players.push_back(player.getName());
    }
    return players;
};
void MultiplayerOverseer::setupGames(int numGames) {
    int aplaycount = 1;
    string name;
    cin.ignore(1000, '\n');
    for (int i=0; i<numGames; i++) {
        name.clear();
        cout<<"Enter player "<<i+1<<"'s name: ";
        getline(cin,name);
        if (name.empty()) {
            name = "Anonymous Player " + to_string(aplaycount);
            aplaycount++;
        }
        m_games.emplace_back(name);
    }

};
void MultiplayerOverseer::runCompetition() {
    while (!m_gameOver) {
        for (PDGameV2 &player : m_games) {
            cout<<player.getName()<<" (Score:"<<player.getGameScore()<<") - TURN "<<to_string(player.getTurnCount()+1)<<endl;
            player.playGame();
            if (player.getGameScore() >= 50) {
                m_gameOver = true;
            };
            printScoreboard();
        }
    }
    sort(m_games.begin(), m_games.end());
    int a = m_games.size()-1;
    string winners;
    while (!(m_games[a]<m_games.back())) {
        winners.append(m_games[a].getName());
        winners+=", ";
        a--;
    }
        cout<<"Congratulations! "<<winners<<"you win with a score of "<<m_games.back().getGameScore()<<endl;
};
void MultiplayerOverseer::printScoreboard() {
    string scoreboard;
    for (PDGameV2 &player : m_games) {
        scoreboard.append(player.getName() + " (Score:" + to_string(player.getGameScore()) + ") |");
    }
    cout << scoreboard << endl;
};

