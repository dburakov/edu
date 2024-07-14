object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 157
  ClientWidth = 238
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 32
    Width = 9
    Height = 13
    Caption = 'Hi'
  end
  object Label2: TLabel
    Left = 24
    Top = 59
    Width = 40
    Height = 13
    Caption = '2..3 kGz'
  end
  object Label3: TLabel
    Left = 24
    Top = 86
    Width = 19
    Height = 13
    Caption = 'Low'
  end
  object Label4: TLabel
    Left = 8
    Top = 8
    Width = 67
    Height = 14
    Caption = 'Coefficients:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 142
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Write'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 96
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '1'
  end
  object Edit2: TEdit
    Left = 96
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '1'
  end
  object Edit3: TEdit
    Left = 96
    Top = 78
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '2'
  end
end
