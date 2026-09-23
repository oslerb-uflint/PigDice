#include <iostream>
#include <random>
using namespace std;


class Die {
    int m_dieValue;
    int m_numSides;
    uniform_int_distribution<int> m_distribution;
    mt19937 m_gen;
public:
    Die() {
        m_dieValue = 0;
        m_numSides = 6;
        random_device rd;
        m_gen = mt19937(rd());
        m_distribution = uniform_int_distribution<int>(1,m_numSides);
    }

    void setNumSides(int numSides) {
        switch (numSides) {
            case 2:
                m_numSides = 2;
                break;
            case 4:
                m_numSides = 4;
                break;
            case 8:
                m_numSides = 8;
                break;
            case 12:
                m_numSides = 12;
                break;
            default:
                m_numSides = 6;
        }
        m_distribution = uniform_int_distribution<int>(1,m_numSides);
    };

    int getNumSides() {
        return m_numSides;
    }

    void rollDie() {
        m_dieValue = m_distribution(m_gen);
    }
    int getValue() {
        return m_dieValue;
    }
};



struct GameState {
    Die dieObject;
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void display_rules() {
    cout << "Let's Play PIG Dice!"<<endl<<endl;
    cout<<"* See how many turns it takes you to get to 20 points."<<endl;
    cout<<"* Turn ends when you hold or roll a 1."<<endl;
    cout<<"* If you roll a 1, you lose all points for the turn."<<endl;
    cout<<"* If you hold, you bank all points for the turn to the game score."<<endl;


}

void hold(GameState &game) {
    cout<<"Score Banked This Turn: "<<game.score_this_turn<<endl;
    game.game_score+=game.score_this_turn;
    game.turn_over = false;

    if (game.game_score >= 20) {
        cout<<endl<<"You finished with a final score of "<<game.game_score<<" in "<<game.turn_count<<" turns!"<<endl;
        cout<<"Thanks for playing PIG Dice!"<<endl;
        game.game_over=true;
    }
}


void get_choice(GameState &game) {
    game.choice = 'a';
    while (game.choice != 'h' && game.choice != 'r') {
        cout<<"roll or hold? (r/h): ";
        cin>> game.choice;
        if (game.choice != 'h' && game.choice != 'r') {
            game.dieObject.setNumSides(8);
            cout<<"You did not enter a valid choice!, please enter r or h"<<endl;
        }
    }
}


void roll(GameState &game) {
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

void play_game(GameState &game) {
    while (not game.game_over) {
        game.score_this_turn = 0; game.turn_count++;
        cout<<endl<<"TURN "<<game.turn_count<<" - Game Score: "<<game.game_score<<endl;
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
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}


