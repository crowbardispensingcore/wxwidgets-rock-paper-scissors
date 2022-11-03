#include "rps_game.h"
#include "main_frame.h"
#include "player.h"
#include "bot.h"

IMPLEMENT_APP(RpsGame)

bool RpsGame::OnInit() {
    if (!wxApp::OnInit()) {
        return false;
    }

    Player* player = new Player();
    Bot* bot = new Bot();
    GameManager* gameManager = new GameManager(player, bot);

    wxFrame *frame = new MainFrame("Rock Paper Scissors", gameManager);
	frame->Show(true);

    return true;
}