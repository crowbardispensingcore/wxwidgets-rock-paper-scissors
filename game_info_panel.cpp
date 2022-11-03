#include "game_info_panel.h"

void GameInfoPanel::init() {
    wxSizer* mainPanelSizer = new wxBoxSizer(wxVERTICAL);


    /* Winner panel */
    wxPanel* winnerPanel = new wxPanel(this, wxID_ANY);
    wxSizer* winnerPanelSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* winnerPanelLabel = new wxStaticText(
        winnerPanel,
        wxID_ANY,
        wxT("Winner")
    );
    winnerPanelLabel->SetFont(winnerPanelLabel->GetFont().Larger().Bold());

    winner = new wxStaticText(
        winnerPanel,
        wxID_ANY,
        "Waiting For Input..."
    );

    winnerPanelSizer->Add(winnerPanelLabel, 0, wxALIGN_CENTER, 0);
    winnerPanelSizer->Add(winner, 0, wxALIGN_CENTER, 0);
    winnerPanel->SetSizer(winnerPanelSizer);



    /* Game stats panel */
    wxPanel* gameStatsPanel = new wxPanel(this, wxID_ANY);
    wxSizer* gameStatsPanelSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* gameStatsPanelLabel = new wxStaticText(
        gameStatsPanel,
        wxID_ANY,
        wxT("Game Stats")
    );
    gameStatsPanelLabel->SetFont(gameStatsPanelLabel->GetFont().Larger().Bold());

    /* Player win count panel */
    wxPanel* playerWinCountPanel = new wxPanel(gameStatsPanel, wxID_ANY);
    wxSizer* playerWinCountPanelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* playerWinCountPanelLabel = new wxStaticText(
        playerWinCountPanel,
        wxID_ANY,
        wxT("You win: ")
    );

    playerWinCountText = new wxStaticText(
        playerWinCountPanel,
        wxID_ANY,
        "0"
    );

    playerWinCountPanelSizer->Add(playerWinCountPanelLabel, 0, wxALIGN_LEFT, 0);
    playerWinCountPanelSizer->Add(playerWinCountText, 0, 0, 0);
    playerWinCountPanel->SetSizer(playerWinCountPanelSizer);

    /* AI win count panel */
    wxPanel* aiWinCountPanel = new wxPanel(gameStatsPanel, wxID_ANY);
    wxSizer* aiWinCountPanelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* aiWinCountPanelLabel = new wxStaticText(
        aiWinCountPanel,
        wxID_ANY,
        wxT("AI wins: ")
    );

    aiWinCountText = new wxStaticText(
        aiWinCountPanel,
        wxID_ANY,
        "0"
    );

    aiWinCountPanelSizer->Add(aiWinCountPanelLabel, 0, wxALIGN_LEFT, 0);
    aiWinCountPanelSizer->Add(aiWinCountText, 0, 0, 0);
    aiWinCountPanel->SetSizer(aiWinCountPanelSizer);

    /* Tie count panel */
    wxPanel* tieCountPanel = new wxPanel(gameStatsPanel, wxID_ANY);
    wxSizer* tieCountPanelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* tieCountPanelLabel = new wxStaticText(
        tieCountPanel,
        wxID_ANY,
        wxT("Tie(s): ")
    );

    tieCountText = new wxStaticText(
        tieCountPanel,
        wxID_ANY,
        "0"
    );

    tieCountPanelSizer->Add(tieCountPanelLabel, 0, wxALIGN_LEFT, 0);
    tieCountPanelSizer->Add(tieCountText, 0, 0, 0);
    tieCountPanel->SetSizer(tieCountPanelSizer);

    /* Game stats panel */
    gameStatsPanelSizer->Add(gameStatsPanelLabel, 0, wxALIGN_CENTER, 0);
    gameStatsPanelSizer->Add(playerWinCountPanel, 0, wxALIGN_LEFT, 0);
    gameStatsPanelSizer->Add(aiWinCountPanel, 0, wxALIGN_LEFT, 0);
    gameStatsPanelSizer->Add(tieCountPanel, 0, wxALIGN_LEFT, 0);

    gameStatsPanel->SetSizer(gameStatsPanelSizer);

    /* Game info panel */
    mainPanelSizer->Add(winnerPanel, 0, wxALIGN_CENTER, 0);
    mainPanelSizer->AddSpacer(20);
    mainPanelSizer->Add(gameStatsPanel, 0, wxALIGN_CENTER, 0);

    SetSizer(mainPanelSizer);
}

void GameInfoPanel::updateWinner(const string winner) {

}

void GameInfoPanel::updatePlayerWinCountText(const int playerWinCount) {

}

void GameInfoPanel::updateAiWinCountText(const int aiWinCount) {

}

void GameInfoPanel::updateTieCountText(const int tieCount) {

}
