/**
 * @file MainWindow.cpp
 * @author srira
 */
#include "pch.h"
#include "MainWindow.h"

MainWindow::MainWindow(wxFrame* parent)
: wxWindow(parent, wxID_ANY)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	mVideoPanel = new VideoPanel(this);
	mChatPanel = new ChatPanel(this);

	// Set background colors to distinguish panels (for demonstration)
	mVideoPanel->SetBackgroundColour(wxColour(100, 100, 100));
	mChatPanel->SetBackgroundColour(wxColour(220, 220, 220));

	mVideoPanel->SetMinSize(wxSize(400, -1));
	mChatPanel->SetMinSize(wxSize(200, -1));

	parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&MainWindow::OnFileOpen,this,wxID_OPEN);
	sizer->Add(mVideoPanel, 3, wxEXPAND | wxALL, 5);
	sizer->Add(mChatPanel, 2, wxEXPAND | wxALL, 5);

	SetSizer(sizer);
}

void MainWindow::OnFileOpen(wxCommandEvent& event)
{
	wxFileDialog loadFileDialog(this, L"Open video", L"", L"",
								L"Video Files (*.mp4)|*.mp4", wxFD_OPEN);
	if (loadFileDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}

	auto filename = loadFileDialog.GetPath();
	mVideoPanel->LoadVideo(filename);
	Refresh();
}

