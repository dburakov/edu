object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1042#1090#1086#1088#1072#1103' '#1083#1072#1073#1072
  ClientHeight = 277
  ClientWidth = 244
  Color = clBtnFace
  Constraints.MaxWidth = 260
  Constraints.MinHeight = 315
  Constraints.MinWidth = 260
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    244
    277)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 20
    Top = 73
    Width = 40
    Height = 13
    Caption = #1044#1072#1085#1085#1099#1077
  end
  object Label3: TLabel
    Left = 20
    Top = 32
    Width = 111
    Height = 13
    Caption = #1056#1072#1079#1084#1077#1088#1085#1086#1089#1090#1100' '#1084#1072#1090#1088#1080#1094#1099
  end
  object sgData: TStringGrid
    Left = 20
    Top = 92
    Width = 208
    Height = 79
    Anchors = [akLeft, akTop, akBottom]
    ColCount = 4
    DefaultColWidth = 50
    FixedCols = 0
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    ExplicitHeight = 85
    ColWidths = (
      50
      50
      50
      50)
  end
  object btnStart: TBitBtn
    Left = 308
    Top = 325
    Width = 108
    Height = 41
    Caption = #1042#1087#1077#1088#1077#1076'!!!'
    TabOrder = 1
  end
  object eSize: TEdit
    Left = 137
    Top = 29
    Width = 44
    Height = 21
    TabOrder = 2
    Text = '2'
  end
  object btnChangeSize: TButton
    Left = 187
    Top = 27
    Width = 41
    Height = 25
    Caption = 'Ok'
    TabOrder = 3
    OnClick = btnChangeSizeClick
  end
  object Button1: TButton
    Left = 20
    Top = 232
    Width = 208
    Height = 30
    Anchors = [akLeft, akBottom]
    Caption = 'Start'
    TabOrder = 4
    OnClick = Button1Click
  end
end
