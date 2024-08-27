/**
 * @file VideoPanel.h
 * @author srira
 *
 *
 */

#ifndef AUTOVE_AUTOVELIB_VIDEOPANEL_H
#define AUTOVE_AUTOVELIB_VIDEOPANEL_H

#include <wx/mediactrl.h>
#include "VideoTimeline.h"

class VideoPanel: public wxPanel
{
	private:
		wxMediaCtrl* mMediaCtrl;
		wxButton* mPlayButton;
		wxButton* mStopButton;
		VideoTimeline* mTimeline;
		wxTimer* mUpdateTimer;

	public:
		VideoPanel(wxWindow* parent);
		void LoadVideo(const wxString& path);
		void OnMediaLoaded(wxMediaEvent &event);
		void OnMediaStateChanged(wxMediaEvent &event);
		void OnPlay(wxCommandEvent& event);
		void OnStop(wxCommandEvent& event);
	void OnUpdateTimer(wxTimerEvent &event);
};


#endif //AUTOVE_AUTOVELIB_VIDEOPANEL_H
