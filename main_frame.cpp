#include "main_frame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(START_A_NEW_GAME, MainFrame::onStartANewGame)
    EVT_MENU(EXIT, MainFrame::onExit)
    EVT_MENU(ABOUT, MainFrame::onAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, GameManager* gameManager) :
    wxFrame(NULL, wxID_ANY, title),
    gameManager(gameManager),
    aiPanel(new AiPanel(this, gameManager)),
    gameInfoPanel(new GameInfoPanel(this, gameManager)),
    playerPanel(new PlayerPanel(this, gameManager, gameInfoPanel, aiPanel))
{
    init();

    wxSize size = GetSize();
    size.SetWidth(size.GetWidth() + 20);
    SetSize(size);
}

MainFrame::~MainFrame() {
    delete playerPanel;
    delete aiPanel;
    delete gameInfoPanel;
    delete gameManager;
}

void MainFrame::init() {
    initMenuBar();
    initSizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
}

void MainFrame::initSizer() {
    wxSizer* mainFrameSizer = new wxBoxSizer(wxHORIZONTAL);

    mainFrameSizer->Add(playerPanel, 0, wxALIGN_TOP, 0);
    mainFrameSizer->AddSpacer(50);
    mainFrameSizer->Add(gameInfoPanel, 0, wxALIGN_CENTER, 0);
    mainFrameSizer->AddSpacer(50);
    mainFrameSizer->Add(aiPanel, 0, wxALIGN_TOP, 0);

    SetSizerAndFit(mainFrameSizer);
}

void MainFrame::initMenuBar() {
    wxMenu* mainFrameFileMenu = new wxMenu;
    mainFrameFileMenu->Append(START_A_NEW_GAME, "Start A New Game", "Start A New Game");
    mainFrameFileMenu->Append(EXIT, "Exit", "Exit the game");

    wxMenu* mainFrameHelpMenu = new wxMenu;
    mainFrameHelpMenu->Append(ABOUT, "About", "About the game");


    wxMenuBar* mainFrameMenuBar = new wxMenuBar();
    mainFrameMenuBar->Append(mainFrameFileMenu, "File");
    mainFrameMenuBar->Append(mainFrameHelpMenu, "About");
    SetMenuBar(mainFrameMenuBar);
}

void MainFrame::onAbout(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(
        wxString::Format(
           "Play Rock Paper Scissors with a computer!",
           wxVERSION_STRING,
           wxGetOsDescription()
        ),
        "About the game",
        wxOK | wxICON_INFORMATION,
        this
    );
}

void MainFrame::onExit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

void MainFrame::onStartANewGame(wxCommandEvent& WXUNUSED(event)) {
    int roundCount = 20;

    gameManager->initGame(roundCount);
    gameInfoPanel->resetPanel(roundCount);
    aiPanel->resetPanel();
    playerPanel->resetPanel();
}
