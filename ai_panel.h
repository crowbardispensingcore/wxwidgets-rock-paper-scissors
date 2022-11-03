#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

using std::string;

class AiPanel : public wxPanel {
public:
    AiPanel(wxFrame* parent) : wxPanel(parent, wxID_ANY) {
        init();
    }

private:
    wxStaticText* aiPredictionText;
    wxStaticText* aiMoveText;

    

    void init();
};