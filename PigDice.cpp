#include <iostream>
#include <ctime>
using namespace std;
    // Build your solution starting from this code.

struct GameState {
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

int roll() {
    int num;
    num = (rand()%6)+1;
    return num;
}

void play_game(GameState game) {
    while (game.game_score < 20) {
        game.score_this_turn = 0; game.turn_count++;
        cout<<endl<<"TURN "<<game.turn_count<<" - Game Score: "<<game.game_score<<endl;
        cout<<"roll or hold? (r/h): ";
        cin>> game.choice;
        while (game.choice != 'h') {
            int dieroll = roll();
            if (dieroll == 1) {
                cout<< "Die: 1"<<endl;
                cout<<"Turn over. No score."<<endl;
                game.score_this_turn=0;
                break;
            }
            else {
                game.score_this_turn+=dieroll;
                cout<<"Die: "<<dieroll<<"- Running score this turn: "<<game.score_this_turn<<endl;
            }
            game.choice = 'a';
            while (game.choice != 'h' && game.choice != 'r') {
                cout<<"roll or hold? (r/h): ";
                cin>> game.choice;
            }
        }
        cout<<"Score Banked This Turn: "<<game.score_this_turn<<endl;
        game.game_score+=game.score_this_turn;

        if (game.game_score >= 20) {
            cout<<endl<<"You finished with a final score of "<<game.game_score<<" in "<<game.turn_count<<" turns!"<<endl;
            cout<<"Thanks for playing PIG Dice!"<<endl;
            break;
        }

    }
}


int main() {
    srand(time(NULL));
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}


