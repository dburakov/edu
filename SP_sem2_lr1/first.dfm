object Form1: TForm1
  Left = 0
  Top = 0
  AlphaBlendValue = 100
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsSingle
  Caption = #1057#1055' '#1074#1072#1088#1080#1072#1085#1090' 3'
  ClientHeight = 347
  ClientWidth = 434
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PrintScale = poNone
  ScreenSnap = True
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 417
    Height = 288
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object btShow: TButton
    Left = 8
    Top = 312
    Width = 113
    Height = 25
    Caption = 'GetSystemInfo'
    TabOrder = 1
    OnClick = btShowClick
  end
  object Button1: TButton
    Left = 127
    Top = 312
    Width = 130
    Height = 25
    Caption = 'GlobalMemoryStatus'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 263
    Top = 312
    Width = 81
    Height = 25
    Caption = 'Lab1'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button2: TButton
    Left = 350
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 4
    OnClick = Button2Click
  end
end
