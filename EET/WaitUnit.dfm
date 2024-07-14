object WaitForm: TWaitForm
  Left = 0
  Top = 0
  AlphaBlendValue = 240
  BorderStyle = bsNone
  BorderWidth = 3
  Caption = 'WaitForm'
  ClientHeight = 97
  ClientWidth = 324
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 129
    Height = 13
    Caption = 'Calculating. Please, wait...'
  end
  object ProgressBar1: TProgressBar
    Left = 24
    Top = 52
    Width = 281
    Height = 25
    BorderWidth = 1
    TabOrder = 0
  end
end
