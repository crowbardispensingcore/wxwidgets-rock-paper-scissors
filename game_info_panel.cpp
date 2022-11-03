#include "game_info_panel.h"

GameInfoPanel::GameInfoPanel(wxFrame* parent, GameManager* gameManager) :
    wxPanel(parent, wxID_ANY),
    gameManager(gameManager)
{
    init();
}

void GameInfoPanel::incrementPlayerWinCount() {
    playerWinCount++;
    updatePlayerWinCountText(playerWinCount);
}

void GameInfoPanel::incrementAiWinCount() {
    aiWinCount++;
    updateAiWinCountText(aiWinCount);
}

void GameInfoPanel::incrementTieCount() {
    tieCount++;
    updateTieCountText(tieCount);
}

void GameInfoPanel::init() {
    wxSizer* mainPanelSizer = new wxBoxSizer(wxVERTICAL);

    /* Remaining round count panel */
    wxPanel* remainingRoundCountPanel = new wxPanel(this, wxID_ANY);
    wxSizer* remainingRoundCountPanelSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* remainingRoundCountLabel = new wxStaticText(
        remainingRoundCountPanel,
        wxID_ANY,
        wxT("Remaining Round(s)")
    );

    remainingRoundCountText = new wxStaticText(
        remainingRoundCountPanel,
        wxID_ANY,
        "20"
    );

    remainingRoundCountPanelSizer->Add(remainingRoundCountLabel, 0, wxALIGN_CENTER, 0);
    remainingRoundCountPanelSizer->Add(remainingRoundCountText, 0, wxALIGN_CENTER, 0);
    remainingRoundCountPanel->SetSizer(remainingRoundCountPanelSizer);

    /* Winner panel */
    wxPanel* winnerPanel = new wxPanel(this, wxID_ANY);
    wxSizer* winnerPanelSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* winnerPanelLabel = new wxStaticText(
        winnerPanel,
        wxID_ANY,
        wxT("Winner")
    );
    winnerPanelLabel->SetFont(winnerPanelLabel->GetFont().Larger().Bold());

    winnerText = new wxStaticText(
        winnerPanel,
        wxID_ANY,
        "Waiting For Input..."
    );

    winnerPanelSizer->Add(winnerPanelLabel, 0, wxALIGN_CENTER, 0);
    winnerPanelSizer->Add(winnerText, 0, wxALIGN_CENTER, 0);
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
    mainPanelSizer->Add(remainingRoundCountPanel, 0, wxALIGN_CENTER, 0);
    mainPanelSizer->AddSpacer(20);
    mainPanelSizer->Add(winnerPanel, 0, wxALIGN_CENTER, 0);
    mainPanelSizer->AddSpacer(20);
    mainPanelSizer->Add(gameStatsPanel, 0, wxALIGN_CENTER, 0);

    SetSizer(mainPanelSizer);
}

void GameInfoPanel::updateWinnerText(string winner) {
    winnerText->SetLabel(winner);
}

void GameInfoPanel::updateRemainingRoundCountText(int remainingRoundCount) {
    remainingRoundCountText->SetLabel(to_string(remainingRoundCount));
}

void GameInfoPanel::updatePlayerWinCountText(int playerWinCount) {
    playerWinCountText->SetLabel(to_string(playerWinCount));
}

void GameInfoPanel::updateAiWinCountText(int aiWinCount) {
    aiWinCountText->SetLabel(to_string(aiWinCount));
}

void GameInfoPanel::updateTieCountText(int tieCount) {
    tieCountText->SetLabel(to_string(tieCount));
}

void GameInfoPanel::resetPanel(int remainingRoundCount) {
    updatePlayerWinCountText(0);
    updateAiWinCountText(0);
    updateTieCountText(0);
    updateWinnerText("Waiting For Input...");
    updateRemainingRoundCountText(remainingRoundCount);
}