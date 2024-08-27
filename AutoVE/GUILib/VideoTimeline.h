/**
 * @file VideoTimeline.h
 * @author srira
 *
 *
 */

#ifndef AUTOVE_GUILIB_VIDEOTIMELINE_H
#define AUTOVE_GUILIB_VIDEOTIMELINE_H


class VideoTimeline: public wxPanel
{
private:
	void OnPaint(wxPaintEvent& event);
	double m_duration = 60.0;  // Default duration of 60 seconds
	double m_currentTime = 0.0;
	double m_majorInterval = 10.0;
	double m_minorInterval = 2.0;
	std::vector<wxBitmap> mThumbnails;
	void OnSize(wxSizeEvent& event);
public:
	void SetDuration(double duration);
	void SetCurrentTime(double time);
	VideoTimeline(wxWindow* parent, wxWindowID id);
	void AddThumbnail(const wxImage &thumbnail);
	void DrawBackground(wxGraphicsContext *gc);
	void DrawThumbnails(wxGraphicsContext *gc);
	void DrawTimeMarkers(wxGraphicsContext *gc);
	void DrawCurrentTimeIndicator(wxGraphicsContext *gc);
	void DrawTimeDisplay(wxGraphicsContext *gc);
	void OnMouseDown(wxMouseEvent& event) { /* Implement seeking logic */ }
	void OnMouseMove(wxMouseEvent& event) { /* Implement dragging logic */ }
	void OnMouseUp(wxMouseEvent& event) { /* Implement seeking completion logic */ }

	void CalculateTimeScale();
	wxString FormatTime(double seconds);
};

#endif //AUTOVE_GUILIB_VIDEOTIMELINE_H
