import wx

class ChatPanel(wx.Panel):
    def __init__(self, parent):
        wx.Panel.__init__(self, parent)
        
        self.SetBackgroundColour(wx.Colour(11, 14, 15))
        
        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.chat_history = wx.TextCtrl(self, style=wx.TE_MULTILINE | wx.TE_READONLY)
        self.input_sizer = wx.BoxSizer(wx.HORIZONTAL)

        self.chat_input = wx.TextCtrl(self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.TE_PROCESS_ENTER)
        self.send_button = wx.Button(self, label="Send")

        self.input_sizer.Add(self.chat_input, 4, wx.EXPAND)
        self.input_sizer.Add(self.send_button, 1, wx.EXPAND)
        self.sizer.Add(self.chat_history, 5, wx.EXPAND)
        self.sizer.Add(self.input_sizer, 1, wx.EXPAND)

        self.SetSizer(self.sizer)

        self.send_button.Bind(wx.EVT_BUTTON, self.OnSend)
        self.chat_input.Bind(wx.EVT_TEXT_ENTER, self.OnSend)
        self.Show()

    def OnSend(self, event):
        text = self.chat_input.GetValue()
        self.chat_input.Clear()
        self.chat_history.AppendText(text + "\n")

        event.Skip()