/**
 * @file ChatPanel.cpp
 * @author srira
 */

#include "pch.h"
#include "ChatPanel.h"

ChatPanel::ChatPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	mChatHistory = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
	sizer->Add(mChatHistory, 1, wxEXPAND | wxALL, 5);

	wxBoxSizer* inputSizer = new wxBoxSizer(wxHORIZONTAL);
	mInputField = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
	mSendButton = new wxButton(this, wxID_ANY, "Send");
	inputSizer->Add(mInputField, 1, wxEXPAND | wxALL, 5);
	inputSizer->Add(mSendButton, 0, wxALL, 5);

	sizer->Add(inputSizer, 0, wxEXPAND);

	SetSizer(sizer);

	// Bind events
	mSendButton->Bind(wxEVT_BUTTON, &ChatPanel::OnSend, this);
	mInputField->Bind(wxEVT_TEXT_ENTER, &ChatPanel::OnSend, this);
}

void ChatPanel::OnSend(wxCommandEvent& event)
{
	wxString message = mInputField->GetValue();
	if (!message.IsEmpty())
	{
		mChatHistory->AppendText("You: " + message + "\n");
		mInputField->Clear();
		// Here you would typically send the message to a chat server
		// For now, we'll just echo it back
		mChatHistory->AppendText("Echo: " + message + "\n");
	}
}