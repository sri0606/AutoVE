/**
 * @file VideoTimeline.cpp
 * @author srira
 */

#include "pch.h"
#include "VideoTimeline.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <vector>


VideoTimeline::VideoTimeline(wxWindow* parent, wxWindowID id = wxID_ANY)
		: wxPanel(parent, id)
	{
		SetBackgroundStyle(wxBG_STYLE_PAINT);
		Bind(wxEVT_PAINT, &VideoTimeline::OnPaint, this);
		Bind(wxEVT_SIZE, &VideoTimeline::OnSize, this);
		Bind(wxEVT_LEFT_DOWN, &VideoTimeline::OnMouseDown, this);
		Bind(wxEVT_MOTION, &VideoTimeline::OnMouseMove, this);
		Bind(wxEVT_LEFT_UP, &VideoTimeline::OnMouseUp, this);

		SetBackgroundColour(*wxBLACK);
	}


void VideoTimeline::OnPaint(wxPaintEvent& event)
{
	wxAutoBufferedPaintDC dc(this);
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);

	if (gc)
	{
		DrawBackground(gc);
		DrawTimeMarkers(gc);
		DrawCurrentTimeIndicator(gc);
//		DrawTimeDisplay(gc);
//		DrawThumbnails(gc);
		delete gc;
	}
}

void VideoTimeline::DrawBackground(wxGraphicsContext* gc)
{
	wxSize size = GetClientSize();
	gc->SetBrush(wxBrush(wxColour(30, 30, 30)));
	gc->DrawRectangle(0, 0, size.GetWidth(), size.GetHeight());
}

void VideoTimeline::DrawTimeMarkers(wxGraphicsContext* gc)
{
	wxSize size = GetClientSize();
	gc->SetPen(wxPen(wxColour(100, 100, 100)));
	gc->SetFont(wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL), wxColour(200, 200, 200));

	double pixelsPerSecond = size.GetWidth() / m_duration;

	for (double t = 0; t <= m_duration; t += m_minorInterval)
	{
		double x = t * pixelsPerSecond;
		bool isMajorMarker = std::fmod(t, m_majorInterval) < 0.001;

		if (isMajorMarker)
		{
			gc->SetPen(wxPen(wxColour(150, 150, 150), 2));
			gc->StrokeLine(x, 0, x, 15);

			wxString timeStr = FormatTime(t);
			double textWidth, textHeight;
			gc->GetTextExtent(timeStr, &textWidth, &textHeight);
			gc->DrawText(timeStr, x - textWidth / 2, 20);
		}
		else
		{
			gc->SetPen(wxPen(wxColour(100, 100, 100)));
			gc->StrokeLine(x, 0, x, 10);
		}
	}
}

void VideoTimeline::DrawCurrentTimeIndicator(wxGraphicsContext* gc)
{
	wxSize size = GetClientSize();
	double x = (m_currentTime / m_duration) * size.GetWidth();
	gc->SetPen(wxPen(*wxRED, 2));  // Changed to red for better visibility
	gc->StrokeLine(x, 0, x, size.GetHeight());
}

void VideoTimeline::DrawTimeDisplay(wxGraphicsContext* gc)
{
	wxSize size = GetClientSize();
	wxString timeStr = FormatTime(m_currentTime) + " / " + FormatTime(m_duration);

	gc->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), *wxWHITE);
	double textWidth, textHeight;
	gc->GetTextExtent(timeStr, &textWidth, &textHeight);
	gc->DrawText(timeStr, size.GetWidth() - textWidth - 10, 10);
}

void VideoTimeline::CalculateTimeScale()
{
	if (m_duration <= 60) // Up to 1 minute
	{
		m_majorInterval = 10;
		m_minorInterval = 2;
	}
	else if (m_duration <= 300) // Up to 5 minutes
	{
		m_majorInterval = 30;
		m_minorInterval = 6;
	}
	else if (m_duration <= 1800) // Up to 30 minutes
	{
		m_majorInterval = 120;
		m_minorInterval = 30;
	}
	else // More than 30 minutes
	{
		m_majorInterval = 600;
		m_minorInterval = 120;
	}
}

wxString VideoTimeline::FormatTime(double seconds)
{
	int hours = static_cast<int>(seconds) / 3600;
	int minutes = (static_cast<int>(seconds) % 3600) / 60;
	int secs = static_cast<int>(seconds) % 60;

	if (hours > 0)
		return wxString::Format("%d:%02d:%02d", hours, minutes, secs);
	else
		return wxString::Format("%02d:%02d", minutes, secs);
}
void VideoTimeline::AddThumbnail(const wxImage& thumbnail)
{
	mThumbnails.push_back(thumbnail.Scale(100, 56));
	Refresh();
}

void VideoTimeline::DrawThumbnails(wxGraphicsContext* gc)
{
	wxSize size = GetClientSize();
	double thumbnailWidth = 100;
	double thumbnailHeight = 56;
	double y = size.GetHeight() - thumbnailHeight;

	for (size_t i = 0; i < mThumbnails.size(); ++i)
	{
		double x = i * thumbnailWidth;
		gc->DrawBitmap(mThumbnails[i], x, y, thumbnailWidth, thumbnailHeight);
	}
}

void VideoTimeline::OnSize(wxSizeEvent& event)
{
	Refresh();
	event.Skip();
}

void VideoTimeline::SetDuration(double duration)
{
	m_duration = duration;
	CalculateTimeScale();
	Refresh();
}

void VideoTimeline::SetCurrentTime(double time) {
	if (m_currentTime != time)
	{
		std::cout<<"Current time:"<<time;
		m_currentTime = time;
		Refresh(false);  // Request a redraw, but don't erase background
	}
}
