/**
 * @file MainFrame.cpp
 * @author srira
 */

#include "pch.h"
#include "MainFrame.h"
#include "MainWindow.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"AutoVE", wxDefaultPosition,  wxSize( 1000,800 ));
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

	// Create a sizer that will lay out child windows vertically
	// one above each other
	auto sizer = new wxBoxSizer( wxVERTICAL );

	auto mainWindow = new MainWindow(this);

	sizer->Add(mainWindow,1,wxEXPAND|wxALL);
	// Set the sizer for this frame
	SetSizer( sizer );

	// Layout (place) the child windows.
	Layout();

	auto menuBar = new wxMenuBar( );

	auto fileMenu = new wxMenu();
	auto helpMenu = new wxMenu();

	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
	fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save video as...");
	fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open video...");

	helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");


	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append(helpMenu, L"&Help");
	SetMenuBar( menuBar );
	CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(L"Welcome to the AutoVE!",
				 L"About AutoVE",
				 wxOK,
				 this);
}