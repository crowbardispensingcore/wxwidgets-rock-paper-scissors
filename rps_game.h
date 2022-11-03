#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class RpsGame : public wxApp {
public:
    virtual bool OnInit();
};

DECLARE_APP(RpsGame)
