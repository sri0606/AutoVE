import wx
import wx.media

class VideoPanel(wx.Panel):
    def __init__(self, parent:wx.Frame):
        wx.Panel.__init__(self, parent)
        
        self.SetBackgroundColour(wx.Colour(135, 150, 156))
        
        sizer = wx.BoxSizer(wx.VERTICAL)

        self.media_ctrl = wx.media.MediaCtrl(self, wx.ID_ANY)
        sizer.Add(self.media_ctrl, 1, wx.EXPAND | wx.ALL, 5)

        button_sizer = wx.BoxSizer(wx.HORIZONTAL)
        play_button = wx.Button(self, wx.ID_ANY, "Play")
        stop_button = wx.Button(self, wx.ID_ANY, "Stop")
        button_sizer.Add(play_button, 0, wx.ALL, 5)
        button_sizer.Add(stop_button, 0, wx.ALL, 5)

        sizer.Add(button_sizer, 1, wx.ALIGN_CENTER)

        self.SetSizer(sizer)

        play_button.Bind(wx.EVT_BUTTON, self.OnPlay)
        stop_button.Bind(wx.EVT_BUTTON, self.OnStop)
        parent.Bind(wx.EVT_MENU, self.fileOpen,id=wx.ID_OPEN)
        self.Show()

    def fileOpen(self, event):
        dlg = wx.FileDialog(self, "Choose a file", "", "", "*.*", wx.FD_OPEN)
        if dlg.ShowModal() == wx.ID_OK:
            path = dlg.GetPath()
            self.media_ctrl.Load(path)
        dlg.Destroy()

    def OnPlay(self, event):
        
        self.media_ctrl.Play()
    
    def OnStop(self, event):
        self.media_ctrl.Stop()
        self.media_ctrl.Unload()

        event.Skip()