#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "game_manager.h"
#include "game_info_panel.h"
#include "ai_panel.h"
#include "move.h"


using std::string;

class PlayerPanel : public wxPanel {
public:
    PlayerPanel(wxFrame* parent, GameManager* gameManager, GameInfoPanel* gameInfoPanel, AiPanel* aiPanel);

    void resetPanel();
    

private:
    GameInfoPanel* gameInfoPanel;
    AiPanel* aiPanel;
    GameManager* gameManager;

    wxStaticText* moveChoice;
    

    void init();

    void onRock(wxCommandEvent& event);
    void onPaper(wxCommandEvent& event);
    void onScissors(wxCommandEvent& event);

    void updateChoiceLabel(const string choice);

    void advanceOneRoundOfGame(enum Move move);
    
};