/**
 * @file VideoPanel.cpp
 * @author srira
 */
#include "pch.h"
#include "VideoPanel.h"
#include <Actions.h>

VideoPanel::VideoPanel(wxWindow* parent): wxPanel(parent, wxID_ANY)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	mUpdateTimer = new wxTimer(this);
	Bind(wxEVT_TIMER, &VideoPanel::OnUpdateTimer, this);

	mMediaCtrl = new wxMediaCtrl(this, wxID_ANY);
	sizer->Add(mMediaCtrl, 3, wxEXPAND | wxALL, 5);

	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	mPlayButton = new wxButton(this, wxID_ANY, "Play");
	mStopButton = new wxButton(this, wxID_ANY, "Stop");
	buttonSizer->Add(mPlayButton, 0, wxALL, 5);
	buttonSizer->Add(mStopButton, 0, wxALL, 5);

	sizer->Add(buttonSizer, 1, wxALIGN_CENTER);

	mTimeline = new VideoTimeline(this, wxID_ANY);
	sizer->Add(mTimeline, 3, wxEXPAND | wxALL, 5);

	SetSizer(sizer);

	// Bind events
	mPlayButton->Bind(wxEVT_BUTTON, &VideoPanel::OnPlay, this);
	mStopButton->Bind(wxEVT_BUTTON, &VideoPanel::OnStop, this);
	mMediaCtrl->Bind(wxEVT_MEDIA_LOADED, &VideoPanel::OnMediaLoaded, this);
	mMediaCtrl->Bind(wxEVT_MEDIA_STATECHANGED, &VideoPanel::OnMediaStateChanged, this);
}

void VideoPanel::LoadVideo(const wxString& path)
{
	if (!(mMediaCtrl->Load(path)))
	{
		wxLogMessage("Video failed to load!");
	}
}

void VideoPanel::OnMediaLoaded(wxMediaEvent& event)
{
	wxLongLong duration = mMediaCtrl->Length();
	mTimeline->SetDuration(duration.ToDouble() / 1000.0);  // Convert milliseconds to seconds
}

void VideoPanel::OnPlay(wxCommandEvent& event)
{
	if (mMediaCtrl->Play())
	{
		mUpdateTimer->Start(100);  // Update every 100ms
	}
}

void VideoPanel::OnStop(wxCommandEvent& event)
{
	mMediaCtrl->Stop();
	mUpdateTimer->Stop();
	mTimeline->SetCurrentTime(0);
}

void VideoPanel::OnUpdateTimer(wxTimerEvent& event)
{
	if (mMediaCtrl->GetState() == wxMEDIASTATE_PLAYING)
	{
		wxLongLong position = mMediaCtrl->Tell();
		double currentTime = position.ToDouble() / 1000.0;  // Convert milliseconds to seconds
		mTimeline->SetCurrentTime(currentTime);

		// Force a redraw of the timeline
		mTimeline->Refresh();

		// Debug output
		wxLogDebug("Current Time: %.2f", currentTime);
	}
}

void VideoPanel::OnMediaStateChanged(wxMediaEvent& event)
{
	if (mMediaCtrl->GetState() == wxMEDIASTATE_STOPPED)
	{
		mUpdateTimer->Stop();
		mTimeline->SetCurrentTime(0);
		mTimeline->Refresh();
	}
}