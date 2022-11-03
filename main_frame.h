#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "player_panel.h"
#include "ai_panel.h"
#include "game_info_panel.h"
#include "game_manager.h"

class MainFrame : public wxFrame {
public:

    MainFrame(const wxString& title, GameManager* gameManager);

    virtual ~MainFrame();

    void onAbout(wxCommandEvent& event);

    void onExit(wxCommandEvent& event);

    void onStartANewGame(wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();
    
    GameManager* gameManager;

    AiPanel* aiPanel;
    GameInfoPanel* gameInfoPanel;
    
    /* playerPanel need to be declared last, because the initialization order is 
        the declaration order, and playerPanel need gameInfoPanel and aiPanel */
    PlayerPanel* playerPanel;

    void init();
    void initSizer();
    void initMenuBar();
};

enum {
    START_A_NEW_GAME = wxID_ANY,
    ABOUT = wxID_ABOUT,
    EXIT = wxID_EXIT
};