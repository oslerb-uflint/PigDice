//
// Created by osler on 11/5/2026.
//

#ifndef PIGDICE_PDGAMEV2_H
#define PIGDICE_PDGAMEV2_H
#include "PigDiceGame.h"
#include <string>
#include <iostream>

class PDGameV2 : public PigDiceGame {

    string m_name;


public:
    void displayRules();
    PDGameV2(const string &name):PigDiceGame() {
        m_name = name;
    };
    ~PDGameV2() {

        //cout << "PDGameV2 object: " << m_name << " destroyed" << endl;
    };
    string getName();
    void playGame();
    int getTurnCount();

    bool operator<(PDGameV2 &a);
};


#endif //PIGDICE_PDGAMEV2_H
