object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Watermark Utility'
  ClientHeight = 498
  ClientWidth = 478
  Color = clBtnFace
  Constraints.MinHeight = 305
  Constraints.MinWidth = 470
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  DesignSize = (
    478
    498)
  PixelsPerInch = 96
  TextHeight = 13
  object TheImage: TImage
    Left = 16
    Top = 200
    Width = 445
    Height = 265
    Align = alCustom
    Anchors = [akLeft, akTop, akRight, akBottom]
    Center = True
    Proportional = True
    OnMouseEnter = TheImageMouseEnter
    OnMouseLeave = TheImageMouseLeave
    ExplicitWidth = 453
    ExplicitHeight = 300
  end
  object Panel1: TPanel
    Left = 16
    Top = 8
    Width = 445
    Height = 179
    Anchors = [akLeft, akTop, akRight]
    BevelKind = bkFlat
    BevelOuter = bvNone
    TabOrder = 0
    OnMouseEnter = Panel1MouseEnter
    OnMouseLeave = Panel1MouseLeave
    ExplicitWidth = 453
    DesignSize = (
      441
      175)
    object Label1: TLabel
      Left = 20
      Top = 29
      Width = 97
      Height = 13
      Caption = #1062#1080#1092#1088#1086#1074#1072#1103' '#1087#1086#1076#1087#1080#1089#1100
    end
    object Label2: TLabel
      Left = 20
      Top = 64
      Width = 57
      Height = 13
      Caption = #1055#1086#1083#1086#1078#1077#1085#1080#1077
    end
    object Label3: TLabel
      Left = 20
      Top = 100
      Width = 69
      Height = 13
      Caption = #1054#1090#1089#1090#1091#1087' '#1089#1083#1077#1074#1072
    end
    object Label4: TLabel
      Left = 184
      Top = 100
      Width = 12
      Height = 13
      Caption = 'px'
    end
    object Label5: TLabel
      Left = 20
      Top = 131
      Width = 70
      Height = 13
      Caption = #1054#1090#1086#1073#1088#1072#1078#1077#1085#1080#1077
    end
    object btnPreview: TBitBtn
      Left = 336
      Top = 24
      Width = 91
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1055#1088#1077#1076#1087#1088#1086#1089#1084#1086#1090#1088
      TabOrder = 0
      OnClick = btnPreviewClick
      OnMouseEnter = btnPreviewMouseEnter
      OnMouseLeave = btnPreviewMouseLeave
      ExplicitLeft = 342
    end
    object WatermarkString: TEdit
      Left = 123
      Top = 26
      Width = 202
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 1
      Text = 'Your Name '#174' All Rights Reserved'
      OnMouseEnter = WatermarkStringMouseEnter
      OnMouseLeave = WatermarkStringMouseLeave
      ExplicitWidth = 205
    end
    object RadioButton1: TRadioButton
      Left = 123
      Top = 53
      Width = 113
      Height = 17
      Caption = #1042#1074#1077#1088#1093#1091
      Checked = True
      TabOrder = 2
      TabStop = True
      OnMouseEnter = RadioButton1MouseEnter
      OnMouseLeave = RadioButton1MouseLeave
    end
    object RadioButton2: TRadioButton
      Left = 123
      Top = 69
      Width = 113
      Height = 17
      Caption = #1042#1085#1080#1079#1091
      TabOrder = 3
      OnMouseEnter = RadioButton2MouseEnter
      OnMouseLeave = RadioButton2MouseLeave
    end
    object eOffset: TEdit
      Left = 123
      Top = 92
      Width = 54
      Height = 21
      TabOrder = 4
      Text = '5'
      OnMouseEnter = eOffsetMouseEnter
      OnMouseLeave = eOffsetMouseLeave
    end
    object cbRotate: TCheckBox
      Left = 123
      Top = 130
      Width = 97
      Height = 17
      Caption = #1042#1077#1088#1090#1080#1082#1072#1083#1100#1085#1086
      TabOrder = 5
      OnMouseEnter = cbRotateMouseEnter
      OnMouseLeave = cbRotateMouseLeave
    end
    object btnReset: TBitBtn
      Left = 336
      Top = 55
      Width = 91
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1057#1073#1088#1086#1089
      TabOrder = 6
      OnClick = btnResetClick
      OnMouseEnter = btnResetMouseEnter
      OnMouseLeave = btnResetMouseLeave
      ExplicitLeft = 338
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 479
    Width = 478
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    ExplicitLeft = 316
    ExplicitTop = 516
    ExplicitWidth = 0
  end
  object MainMenu1: TMainMenu
    Left = 492
    Top = 16
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100'...'
        ShortCut = 16463
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
        ShortCut = 16467
        OnClick = N3Click
      end
    end
    object N4: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N7: TMenuItem
        Caption = #1064#1088#1080#1092#1090'...'
        ShortCut = 115
        OnClick = N7Click
      end
    end
    object N5: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N6: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
        ShortCut = 112
        OnClick = N6Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1050#1072#1088#1090#1080#1085#1082#1080'|*.bmp'
    Left = 520
    Top = 16
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 548
    Top = 16
  end
  object SaveDialog1: TSaveDialog
    Filter = #1050#1072#1088#1090#1080#1085#1082#1080'|*.bmp'
    Left = 576
    Top = 16
  end
end
