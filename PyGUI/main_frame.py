import wx
from chat_panel import ChatPanel
from video_panel import VideoPanel

class MainFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, title="AutoVE", size=(800, 600))

        sizer = wx.BoxSizer(wx.HORIZONTAL)
        self.chat_panel = ChatPanel(self)
        self.video_panel = VideoPanel(self) 

        sizer.Add(self.video_panel, 4, wx.EXPAND)
        sizer.Add(self.chat_panel, 2, wx.EXPAND)

        self.SetSizer(sizer)

        menu_bar = wx.MenuBar()
        file_menu = wx.Menu()
        help_menu = wx.Menu()

        file_menu.Append(wx.ID_OPEN, "Open")
        file_menu.Append(wx.ID_SAVE, "Save")
        file_menu.Append(wx.ID_EXIT, "Exit")

        help_menu.Append(wx.ID_HELP, "About")

        self.Bind(wx.EVT_MENU, self.OnExit, id=wx.ID_EXIT)
        self.Bind(wx.EVT_MENU, self.OnAbout, id=wx.ID_HELP)

        menu_bar.Append(file_menu, "File")
        menu_bar.Append(help_menu, "Help")

        self.SetMenuBar(menu_bar)

        self.Show()

    def OnExit(self, event):
        self.Close()
    
    def OnAbout(self, event):
        wx.MessageBox("This is PyGUI", "About", wx.OK | wx.ICON_INFORMATION)