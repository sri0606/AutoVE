/**
 * @file MainFrame.h
 * @author srira
 *
 *
 */

#ifndef AUTOVE_AUTOVELIB_MAINFRAME_H
#define AUTOVE_AUTOVELIB_MAINFRAME_H

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:

public:
	void Initialize();

	void OnExit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
};
#endif //AUTOVE_AUTOVELIB_MAINFRAME_H
