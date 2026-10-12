#include <iostream>
#include "DIE.h"
using namespace std;



struct PigDiceGame {
    Die dieObject;
    char choice;
    int turn_count = 0;
    int m_gameScore = 0;
    int score_this_turn = 0;
    bool m_gameOver = false;
    bool turn_over = false;
};





void display_rules() {
    cout << "Let's Play PIG Dice!"<<endl<<endl;
    cout<<"* See how many turns it takes you to get to 20 points."<<endl;
    cout<<"* Turn ends when you hold or roll a 1."<<endl;
    cout<<"* If you roll a 1, you lose all points for the turn."<<endl;
    cout<<"* If you hold, you bank all points for the turn to the game score."<<endl;


}

void hold(PigDiceGame &game) {
    cout<<"Score Banked This Turn: "<<game.score_this_turn<<endl;
    game.m_gameScore+=game.score_this_turn;
    game.turn_over = false;

    if (game.m_gameScore >= 20) {
        cout<<endl<<"You finished with a final score of "<<game.m_gameScore<<" in "<<game.turn_count<<" turns!"<<endl;
        cout<<"Thanks for playing PIG Dice!"<<endl;
        game.m_gameOver=true;
    }
}


void get_choice(PigDiceGame &game) {
    game.choice = 'a';
    while (game.choice != 'h' && game.choice != 'r') {
        cout<<"roll or hold? (r/h): ";
        cin>> game.choice;
        if (game.choice != 'h' && game.choice != 'r') {
            cout<<"You did not enter a valid choice!, please enter r or h"<<endl;
        }
    }
}


void roll(PigDiceGame &game) {
    game.dieObject.rollDie();
    int dieroll = game.dieObject.getValue();
    if (dieroll == 1) {
        cout<< "Die: 1"<<endl;
        cout<<"Turn over. No score."<<endl;
        game.score_this_turn=0;
        game.turn_over = true;
    }
    else {
        game.score_this_turn+=dieroll;
        cout<<"Die: "<<dieroll<<"- Running score this turn: "<<game.score_this_turn<<endl;
    }
}

void play_game(PigDiceGame &game) {
    while (not game.m_gameOver) {
        game.score_this_turn = 0; game.turn_count++;
        cout<<endl<<"TURN "<<game.turn_count<<" - Game Score: "<<game.m_gameScore<<endl;
        get_choice(game);
        while (game.choice != 'h'&& game.turn_over == false) {
            roll(game);
            if (game.turn_over == true) {
                break;
            }
            get_choice(game);
        }

        hold(game);

    }
}


int main() {
    PigDiceGame my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}


