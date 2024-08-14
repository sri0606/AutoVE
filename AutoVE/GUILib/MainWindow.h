/**
 * @file MainWindow.h
 * @author srira
 *
 *
 */

#ifndef AUTOVE_AUTOVELIB_MAINWINDOW_H
#define AUTOVE_AUTOVELIB_MAINWINDOW_H

#include <wx/splitter.h>
#include "VideoPanel.h"
#include "ChatPanel.h"

class MainWindow : public wxWindow
{
private:

	VideoPanel* mVideoPanel;
	ChatPanel* mChatPanel;
public:
	MainWindow(wxFrame *parent);
	void Initialize(wxFrame* );

	void OnFileOpen(wxCommandEvent& event);
};

#endif //AUTOVE_AUTOVELIB_MAINWINDOW_H
