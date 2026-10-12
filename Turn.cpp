//
// Created by osler on 10/12/2026.
//

#include "Turn.h"
#include "Die.h"
#include <iostream>
using namespace std;

Turn::Turn() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = 'a';
    m_die = Die();
}

void Turn::takeTurn(int GameScore) {
    m_scoreThisTurn = 0;
    m_turnCount++;
    cout<<endl<<"TURN "<<m_turnCount<<" - Game Score: "<<GameScore<<endl;
    while (m_turnOver == false) {
        getChoice();
        if (m_choice=='r') {
            roll();
        }
        else if (m_choice=='h') {
            hold();
        }
    }
}

int Turn::getScoreThisTurn() {
    return m_scoreThisTurn;
}

void Turn::resetTurnOver() {
    m_turnOver = false;
}

int Turn::getTurnCount() {
    return m_turnCount;
}

void Turn::roll() {
    m_die.rollDie();
    int dieValue = m_die.getValue();
    if (dieValue > 1) {
        m_scoreThisTurn+=dieValue;
        cout<<"Die: "<<dieValue<<"- Running score this turn: "<<m_scoreThisTurn<<endl;
    }
    else {
        m_scoreThisTurn = 0;
        m_turnOver = true;
        cout<< "Die: 1"<<endl;
        cout<<"Turn over. No score."<<endl;
        cout<<"Score Banked This Turn: 0"<<endl;
    }

}

void Turn::hold() {
    cout<<"Score Banked This Turn: "<<m_scoreThisTurn<<endl;
    m_turnOver = true;
}

void Turn::getChoice() {
    m_choice = 'a';
    while (m_choice!='r' && m_choice!='h') {
        cout<<"roll or hold? (r/h): ";
        cin>> m_choice;
        if (m_choice != 'h' && m_choice != 'r') {
            cout<<"You did not enter a valid choice!, please enter r or h"<<endl;
        }
    }
}













