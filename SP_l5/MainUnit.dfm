object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 238
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
  object Label5: TLabel
    Left = 24
    Top = 120
    Width = 72
    Height = 13
    Caption = 'Executein Time'
  end
  object l_ExeTime: TLabel
    Left = 116
    Top = 120
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label6: TLabel
    Left = 201
    Top = 120
    Width = 16
    Height = 13
    Caption = 'sec'
  end
  object Button1: TButton
    Left = 102
    Top = 144
    Width = 115
    Height = 25
    Caption = 'Write (C++)'
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
  object Button2: TButton
    Left = 102
    Top = 175
    Width = 115
    Height = 25
    Caption = 'Write (asm)'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 102
    Top = 206
    Width = 115
    Height = 25
    Caption = 'Write (MMX)'
    TabOrder = 5
    OnClick = Button3Click
  end
end
