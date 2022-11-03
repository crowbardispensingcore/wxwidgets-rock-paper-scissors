#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

using std::string;
using std::to_string;

class GameInfoPanel : public wxPanel {
public:
    GameInfoPanel(wxFrame* parent) : wxPanel(parent, wxID_ANY) {
        init();
    }

private:
    wxStaticText* winner;
    wxStaticText* playerWinCountText;
    wxStaticText* aiWinCountText;
    wxStaticText* tieCountText;

    int playerWinCount = 0;
    int aiWinCount = 0;
    int tieCount = 0;

    void init();

    void updateWinner(const string winner);
    void updatePlayerWinCountText(const int playerWinCount);
    void updateAiWinCountText(const int aiWinCount);
    void updateTieCountText(const int tieCount);
};