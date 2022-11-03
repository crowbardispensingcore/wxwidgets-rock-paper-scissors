#include "game_manager.h"
#include <iostream>
void GameManager::startGame(char gameType, int roundCount) {

    for (int i = 0; i < roundCount; i++) {    //generate random choice from bot 20 times 
        game_player.setMove();
        if (gameType == 'r') {
            game_bot.set_choice();
        }
        else if (gameType == 'm') {
            game_bot.set_choiceML(game_player.getMove());
        }
        cout << "Round # " << i + 1 << endl;
        Move player_choice = game_player.getMove();
        Move bot_choice = game_bot.get_choice();
        int winner = decideWinner(player_choice, bot_choice);
        cout << "test bot chose: " << game_bot.print_choice() << endl;
        if (winner == 0) {
            cout << "TIE" << endl;
        }
        else if (winner == -1) {
            cout << "Player LOST" << endl;
        }
        else {
            cout << "Player WINS!" << endl;
        }
    }
}
int GameManager::decideWinner(Move player_choice, Move bot_choice) {
    if (player_choice == Move::ROCK) {
        if (bot_choice == Move::ROCK) {
            return 0;
        }
        else if (bot_choice == Move::PAPER) {
            return -1;
        }
        else {
            return 1;
        }
    }
    else if (player_choice == Move::PAPER) {
        if (bot_choice == Move::PAPER) {
            return 0;
        }
        else if (bot_choice == Move::SCISSORS) {
            return -1;
        }
        else {
            return 1;
        }
    }
    else {  //player chose scissors
        if (bot_choice == Move::SCISSORS) {
            return 0;
        }
        else if (bot_choice == Move::ROCK) {
            return -1;
        }
        else {
            return 1;
        }
    }
}