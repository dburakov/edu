object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1064#1077#1083#1083#1072
  ClientHeight = 491
  ClientWidth = 474
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel4: TPanel
    Left = 0
    Top = 0
    Width = 474
    Height = 491
    Align = alClient
    BevelInner = bvRaised
    BevelKind = bkSoft
    BevelOuter = bvLowered
    TabOrder = 0
    ExplicitLeft = 12
    ExplicitTop = 8
    ExplicitWidth = 510
    ExplicitHeight = 408
    object Panel1: TPanel
      Left = 14
      Top = 16
      Width = 439
      Height = 249
      BevelInner = bvLowered
      TabOrder = 0
      object Panel2: TPanel
        Left = 219
        Top = 7
        Width = 210
        Height = 208
        BevelInner = bvLowered
        TabOrder = 0
        object Label3: TLabel
          Left = 15
          Top = 8
          Width = 163
          Height = 16
          Caption = #1054#1090#1089#1086#1088#1090#1080#1088#1086#1074#1072#1085#1085#1099#1081' '#1092#1072#1081#1083':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object OutMemo: TMemo
          Left = 15
          Top = 30
          Width = 182
          Height = 169
          ReadOnly = True
          ScrollBars = ssVertical
          TabOrder = 0
        end
      end
      object Panel3: TPanel
        Left = 8
        Top = 7
        Width = 210
        Height = 208
        BevelInner = bvLowered
        TabOrder = 1
        object Label2: TLabel
          Left = 14
          Top = 7
          Width = 109
          Height = 16
          Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1092#1072#1081#1083':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object InMemo: TMemo
          Left = 14
          Top = 29
          Width = 182
          Height = 169
          Lines.Strings = (
            '')
          ReadOnly = True
          ScrollBars = ssVertical
          TabOrder = 0
        end
      end
    end
    object Panel5: TPanel
      Left = 14
      Top = 284
      Width = 248
      Height = 125
      BevelInner = bvLowered
      TabOrder = 1
      object lIteration: TLabel
        Left = 183
        Top = 34
        Width = 21
        Height = 16
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 8
        Top = 34
        Width = 158
        Height = 16
        Caption = #1050#1086#1083#1080#1095#1077#1090#1089#1074#1086' '#1087#1077#1088#1077#1089#1090#1072#1085#1086#1074#1086#1082':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 8
        Top = 11
        Width = 132
        Height = 16
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1088#1086#1093#1086#1076#1086#1074':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object lSteps: TLabel
        Left = 183
        Top = 12
        Width = 8
        Height = 16
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 8
        Top = 56
        Width = 140
        Height = 16
        Caption = #1042#1088#1077#1084#1103' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1080', '#1084#1082#1089':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object lSortTime: TLabel
        Left = 183
        Top = 56
        Width = 8
        Height = 16
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object StartButton: TButton
      Left = 344
      Top = 433
      Width = 109
      Height = 25
      Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
      TabOrder = 2
      OnClick = StartButtonClick
    end
    object Panel6: TPanel
      Left = 264
      Top = 284
      Width = 189
      Height = 125
      BevelInner = bvLowered
      TabOrder = 3
      object Label5: TLabel
        Left = 24
        Top = 10
        Width = 49
        Height = 16
        Caption = #1050#1083#1102#1095#1080':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object seqMemo: TMemo
        Left = 24
        Top = 32
        Width = 149
        Height = 77
        Lines.Strings = (
          '1'
          '2'
          '4')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
