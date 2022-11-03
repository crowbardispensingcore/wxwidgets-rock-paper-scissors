#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "game_manager.h"

using std::string;
using std::to_string;

class GameInfoPanel : public wxPanel {
public:
    GameInfoPanel(wxFrame* parent, GameManager* gameManager);

    void incrementPlayerWinCount();
    void incrementAiWinCount();
    void incrementTieCount();
    void updateWinnerText(string winner);
    void updateRemainingRoundCountText(int remainingRoundCount);

    void resetPanel(int remainingRoundCount);

private:
    wxStaticText* winnerText;
    wxStaticText* playerWinCountText;
    wxStaticText* aiWinCountText;
    wxStaticText* tieCountText;
    wxStaticText* remainingRoundCountText;

    GameManager* gameManager;

    int playerWinCount = 0;
    int aiWinCount = 0;
    int tieCount = 0;

    void init();

    void updatePlayerWinCountText(int playerWinCount);
    void updateAiWinCountText(int aiWinCount);
    void updateTieCountText(int tieCount);
};