#include "rps_game.h"
#include "main_frame.h"

IMPLEMENT_APP(RpsGame)

bool RpsGame::OnInit() {
    if (!wxApp::OnInit()) {
        return false;
    }

    GameManager* gameManager = new GameManager();

    wxFrame *frame = new MainFrame("Rock Paper Scissors", gameManager);
	frame->Show(true);

    return true;
}