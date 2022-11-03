#include "player_panel.h"

void PlayerPanel::init() {
    wxSizer* playerPanelSizer = new wxBoxSizer(wxVERTICAL);

    /* Player control panel */
    wxPanel* playerControlPanel = new wxPanel(this, wxID_ANY);
    wxSizer* playerControlPanelSizer = new wxBoxSizer(wxHORIZONTAL);

    /* Move buttons panel */
    wxPanel* moveButtonsPanel = new wxPanel(playerControlPanel, wxID_ANY);
    wxSizer* moveButtonsPanelSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* choicePrompt = new wxStaticText(
        moveButtonsPanel,
        wxID_ANY,
        wxT("Moves")
    );

    wxButton* rockChoiceButton = new wxButton(
        moveButtonsPanel,
        wxID_ANY,
        "Rock"
    );
    wxButton* paperChoiceButton = new wxButton(
        moveButtonsPanel,
        wxID_ANY,
        "Paper"
    );
    wxButton* scissorsChoiceButton = new wxButton(
        moveButtonsPanel,
        wxID_ANY,
        "Scissors"
    );

    rockChoiceButton->Bind(
        wxEVT_BUTTON,
        &PlayerPanel::onRock,
        this
    );
    paperChoiceButton->Bind(
        wxEVT_BUTTON,
        &PlayerPanel::onPaper,
        this
    );
    scissorsChoiceButton->Bind(
        wxEVT_BUTTON,
        &PlayerPanel::onScissors,
        this
    );

    moveButtonsPanelSizer->Add(choicePrompt, 0, wxALIGN_CENTER, 0);
    moveButtonsPanelSizer->AddSpacer(5);
    moveButtonsPanelSizer->Add(rockChoiceButton, 0, wxALIGN_CENTER, 0);
    moveButtonsPanelSizer->AddSpacer(5);
    moveButtonsPanelSizer->Add(paperChoiceButton, 0, wxALIGN_CENTER, 0);
    moveButtonsPanelSizer->AddSpacer(5);
    moveButtonsPanelSizer->Add(scissorsChoiceButton, 0, wxALIGN_CENTER, 0);

    moveButtonsPanel->SetSizer(moveButtonsPanelSizer);

    /* Move result panel */
    wxPanel* moveChoicePanel = new wxPanel(playerControlPanel, wxID_ANY);
    wxSizer* moveChoicePanelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* moveChoiceLabel = new wxStaticText(
        moveChoicePanel,
        wxID_ANY,
        "Your Move is: "
    );

    moveChoice = new wxStaticText(
        moveChoicePanel,
        wxID_ANY,
        "Waiting For Input..."
    );
    moveChoice->SetFont(moveChoice->GetFont().Larger());

    moveChoicePanelSizer->Add(moveChoiceLabel, 0, wxALIGN_CENTER, 0);
    moveChoicePanelSizer->Add(moveChoice, 0, 0, 0);

    moveChoicePanel->SetSizer(moveChoicePanelSizer);

    /* Player control panel */
    playerControlPanelSizer->Add(moveButtonsPanel, 0, 0, 0);
    playerControlPanelSizer->AddSpacer(20);
    playerControlPanelSizer->Add(moveChoicePanel, 0, 0, 0);

    playerControlPanel->SetSizer(playerControlPanelSizer);

    /* Player panel */
    wxStaticText* playerPanelLabel = new wxStaticText(
        this,
        wxID_ANY,
        wxT("You")
    );
    playerPanelLabel->SetFont(playerPanelLabel->GetFont().Larger().Bold());
    
    playerPanelSizer->Add(playerPanelLabel, 0, wxALIGN_CENTER, 0);
    playerPanelSizer->Add(playerControlPanel, 0, wxALIGN_CENTER, 0);

    SetSizer(playerPanelSizer);
}

void PlayerPanel::onRock(wxCommandEvent& event) {
    updateChoiceLabel("Rock");
}

void PlayerPanel::onPaper(wxCommandEvent& event) {
    updateChoiceLabel("Paper");
}

void PlayerPanel::onScissors(wxCommandEvent& event) {
    updateChoiceLabel("Scissors");
}

void PlayerPanel::updateChoiceLabel(const string choice) {
    moveChoice->SetLabelText(choice);
}