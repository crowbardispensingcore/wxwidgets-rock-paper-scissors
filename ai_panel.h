#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "game_manager.h"

using std::string;

class AiPanel : public wxPanel {
public:
    AiPanel(wxFrame* parent, GameManager* gameManager);
    void updateAiPredictionText(string prediction);
    void updateAiMoveText(string aiMove);

    void resetPanel();

private:
    wxStaticText* aiPredictionText;
    wxStaticText* aiMoveText;

    GameManager* gameManager;

    void init();
};