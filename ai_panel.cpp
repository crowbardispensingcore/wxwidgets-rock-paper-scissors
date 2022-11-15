#include "ai_panel.h"

AiPanel::AiPanel(wxFrame* parent, GameManager* gameManager) :
    wxPanel(parent, wxID_ANY),
    gameManager(gameManager)
{
    init();
}

void AiPanel::init() {
    wxSizer* aiPanelSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* aiPanelLabel = new wxStaticText(
        this,
        wxID_ANY,
        wxT("AI")
    );
    aiPanelLabel->SetFont(aiPanelLabel->GetFont().Larger().Bold());

    /* AI prediction panel */
    wxPanel* aiPredictionPanel = new wxPanel(this, wxID_ANY);
    wxSizer* aiPredictionPanelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* aiPredictionLabel = new wxStaticText(
        aiPredictionPanel,
        wxID_ANY,
        wxT("AI Predicted Your Move Was: ")
    );

    aiPredictionText = new wxStaticText(
        aiPredictionPanel,
        wxID_ANY,
        "Waiting For Input..."
    );

    aiPredictionPanelSizer->Add(aiPredictionLabel, 0, wxALIGN_LEFT, 0);
    aiPredictionPanelSizer->Add(aiPredictionText, 0, 0, 0);
    aiPredictionPanel->SetSizer(aiPredictionPanelSizer);

    /* AI move panel */
    wxPanel* aiMovePanel = new wxPanel(this, wxID_ANY);
    wxSizer* aiMovePanelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* aiMoveLabel = new wxStaticText(
        aiMovePanel,
        wxID_ANY,
        wxT("Therefore, AI's Move Is: ")
    );

    aiMoveText = new wxStaticText(
        aiMovePanel,
        wxID_ANY,
        "Waiting For Input..."
    );

    aiMovePanelSizer->Add(aiMoveLabel, 0, wxALIGN_LEFT, 0);
    aiMovePanelSizer->Add(aiMoveText, 0, 0, 0);
    aiMovePanel->SetSizer(aiMovePanelSizer);

    /* AI panel */
    aiPanelSizer->Add(aiPanelLabel, 0, wxALIGN_CENTER, 0);
    aiPanelSizer->Add(aiPredictionPanel, 0, wxALIGN_LEFT, 0);
    aiPanelSizer->Add(aiMovePanel, 0, wxALIGN_LEFT, 0);

    SetSizer(aiPanelSizer);
}

void AiPanel::updateAiPredictionText(string prediction) {
    aiPredictionText->SetLabel("You Are Most Likely To Choose " + prediction);
}

void AiPanel::updateAiMoveText(string aiMove) {
    aiMoveText->SetLabel(aiMove);
}

void AiPanel::resetPanel() {
    updateAiPredictionText("Waiting For Input...");
    updateAiMoveText("Waiting For Input...");
}