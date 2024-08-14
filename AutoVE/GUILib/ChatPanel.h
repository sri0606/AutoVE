/**
 * @file ChatPanel.h
 * @author srira
 *
 *
 */

#ifndef AUTOVE_AUTOVELIB_CHATPANEL_H
#define AUTOVE_AUTOVELIB_CHATPANEL_H

class ChatPanel : public wxPanel
{
private:
	wxTextCtrl* mChatHistory;
	wxTextCtrl* mInputField;
	wxButton* mSendButton;

public:
	ChatPanel(wxWindow* parent);
private:
	void OnSend(wxCommandEvent& event);
};


#endif //AUTOVE_AUTOVELIB_CHATPANEL_H
