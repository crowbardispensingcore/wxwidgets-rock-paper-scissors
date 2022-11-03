#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

using std::string;

class PlayerPanel : public wxPanel {
public:
    PlayerPanel(wxFrame* parent) : wxPanel(parent, wxID_ANY) {
        init();
    }

private:
    wxStaticText* moveChoice;

    void init();

    void onRock(wxCommandEvent& event);
    void onPaper(wxCommandEvent& event);
    void onScissors(wxCommandEvent& event);

    void updateChoiceLabel(const string choice);
};