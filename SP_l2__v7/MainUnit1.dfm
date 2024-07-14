object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1042#1090#1086#1088#1072#1103' '#1083#1072#1073#1072
  ClientHeight = 294
  ClientWidth = 249
  Color = clBtnFace
  Constraints.MaxWidth = 500
  Constraints.MinHeight = 304
  Constraints.MinWidth = 252
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    249
    294)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 20
    Top = 129
    Width = 40
    Height = 13
    Caption = #1044#1072#1085#1085#1099#1077
  end
  object Label3: TLabel
    Left = 20
    Top = 8
    Width = 111
    Height = 13
    Caption = #1056#1072#1079#1084#1077#1088#1085#1086#1089#1090#1100' '#1084#1072#1090#1088#1080#1094#1099
  end
  object Label2: TLabel
    Left = 72
    Top = 32
    Width = 6
    Height = 13
    Caption = 'x'
  end
  object sgData: TStringGrid
    Left = 20
    Top = 148
    Width = 213
    Height = 85
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 4
    DefaultColWidth = 50
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    ColWidths = (
      50
      50
      50
      50)
  end
  object eSize: TEdit
    Left = 22
    Top = 27
    Width = 44
    Height = 21
    TabOrder = 1
    Text = '3'
  end
  object btnChangeSize: TButton
    Left = 155
    Top = 25
    Width = 81
    Height = 25
    Caption = 'Ok'
    TabOrder = 2
    OnClick = btnChangeSizeClick
  end
  object Button1: TButton
    Left = 20
    Top = 256
    Width = 213
    Height = 30
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Start'
    TabOrder = 3
    OnClick = Button1Click
    ExplicitTop = 356
    ExplicitWidth = 381
  end
  object cSize: TEdit
    Left = 84
    Top = 27
    Width = 47
    Height = 21
    TabOrder = 4
    Text = '4'
  end
  object StaticText1: TStaticText
    Left = 20
    Top = 62
    Width = 209
    Height = 61
    AutoSize = False
    Caption = 
      #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1089#1095#1080#1090#1072#1077#1090' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1086#1083#1086#1078#1080#1090#1077#1083#1100#1085#1099#1093' '#1080' '#1086#1090#1088#1080#1094#1072#1090#1077#1083#1100#1085#1099#1093' '#1095#1080#1089#1077#1083 +
      ' '#1074' '#1084#1072#1089#1089#1080#1074#1077'. '#1053#1086#1083#1100' '#1089#1095#1080#1090#1072#1077#1090#1089#1103' '#1087#1086#1083#1086#1078#1080#1090#1077#1083#1100#1085#1099#1084'.'
    TabOrder = 5
  end
end
