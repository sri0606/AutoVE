/**
 * @file VideoPanel.cpp
 * @author srira
 */
#include "pch.h"
#include "VideoPanel.h"

VideoPanel::VideoPanel(wxWindow* parent): wxPanel(parent, wxID_ANY)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	mMediaCtrl = new wxMediaCtrl(this, wxID_ANY);
	sizer->Add(mMediaCtrl, 1, wxEXPAND | wxALL, 5);

	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	mPlayButton = new wxButton(this, wxID_ANY, "Play");
	mStopButton = new wxButton(this, wxID_ANY, "Stop");
	buttonSizer->Add(mPlayButton, 0, wxALL, 5);
	buttonSizer->Add(mStopButton, 0, wxALL, 5);

	sizer->Add(buttonSizer, 1, wxALIGN_CENTER);

	SetSizer(sizer);

	// Bind events
	mPlayButton->Bind(wxEVT_BUTTON, &VideoPanel::OnPlay, this);
	mStopButton->Bind(wxEVT_BUTTON, &VideoPanel::OnStop, this);
}

void VideoPanel::LoadVideo(const wxString& path)
{
	if (!(mMediaCtrl->Load(path)))
	{
		wxLogMessage("Video failed to load!");
	}
}