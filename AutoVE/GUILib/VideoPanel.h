/**
 * @file VideoPanel.h
 * @author srira
 *
 *
 */

#ifndef AUTOVE_AUTOVELIB_VIDEOPANEL_H
#define AUTOVE_AUTOVELIB_VIDEOPANEL_H

#include <wx/mediactrl.h>

class VideoPanel: public wxPanel
{
	private:
		wxMediaCtrl* mMediaCtrl;
		wxButton* mPlayButton;
		wxButton* mStopButton;

	public:
		VideoPanel(wxWindow* parent);

		void LoadVideo(const wxString& path);

		void OnPlay(wxCommandEvent& event)
		{
			mMediaCtrl->Play();
		}

		void OnStop(wxCommandEvent& event)
		{
			mMediaCtrl->Stop();
		}
};


#endif //AUTOVE_AUTOVELIB_VIDEOPANEL_H
