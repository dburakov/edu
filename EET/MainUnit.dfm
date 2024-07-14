object MainForm: TMainForm
  Left = 274
  Top = 200
  Cursor = crArrow
  BorderStyle = bsDialog
  Caption = 'EET'
  ClientHeight = 650
  ClientWidth = 762
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 254
    Top = 24
    Width = 54
    Height = 13
    Caption = 'S - entropy'
  end
  object Label2: TLabel
    Left = 424
    Top = 25
    Width = 59
    Height = 13
    Caption = 'H - enthalpy'
  end
  object Label3: TLabel
    Left = 593
    Top = 24
    Width = 96
    Height = 13
    Caption = 'C - thermal capacity'
  end
  object Label4: TLabel
    Left = 15
    Top = 23
    Width = 33
    Height = 13
    Caption = 'Source'
  end
  object Label5: TLabel
    Left = 143
    Top = 25
    Width = 76
    Height = 13
    Caption = 'T - temperature'
  end
  object NInSource: TLabel
    Left = 17
    Top = 356
    Width = 50
    Height = 13
    Caption = 'NInSource'
  end
  object btnStart: TButton
    Left = 15
    Top = 582
    Width = 119
    Height = 54
    Caption = 'Start'
    Default = True
    TabOrder = 0
    OnClick = btnStartClick
  end
  object InputMemo: TMemo
    Left = 15
    Top = 42
    Width = 90
    Height = 300
    Lines.Strings = (
      '0,00'
      '0,00'
      '2723,78'
      '2723,78'
      '2987,38'
      '2987,38'
      '3451,80'
      '3451,80'
      '4648,42'
      '4648,42'
      '4811,60'
      '4811,60'
      '5313,68'
      '5313,68'
      '5594,01'
      '5594,01'
      '5677,69'
      '5677,69'
      '6380,60'
      '6380,60'
      '6686,03'
      '6686,03'
      '6903,60'
      '6903,60'
      '6962,18'
      '6962,18'
      '7179,74'
      '7179,74'
      '7351,29'
      '7351,29'
      '7434,97'
      '7434,97'
      '7485,18'
      '7485,18'
      '7485,18'
      '7485,18'
      '7941,23'
      '7941,23'
      '8267,58'
      '8267,58'
      '8317,79'
      '8317,79'
      '8393,10'
      '8393,10'
      '8439,13'
      '8439,13'
      '8501,89'
      '8501,89'
      '8535,36'
      '8535,36'
      '8539,54'
      '8539,54'
      '8769,66'
      '8769,66'
      '8790,58'
      '8790,58'
      '8803,14'
      '8803,14'
      '8807,32'
      '8807,32'
      '8974,68'
      '8974,68'
      '9179,70'
      '9179,70'
      '9221,54'
      '9221,54'
      '9313,58'
      '9313,58'
      '9317,77'
      '9317,77'
      '9639,94'
      '9639,94'
      '9669,22'
      '9669,22'
      '9890,98'
      '9890,98'
      '9970,47'
      '9970,47'
      '9978,84'
      '9978,84'
      '9991,39'
      '9991,39'
      '10075,07'
      '10075,07'
      '10100,18'
      '10100,18'
      '10146,20'
      '10146,20'
      '10234,06'
      '10234,06'
      '10254,98'
      '10254,98'
      '10305,19'
      '10305,19'
      '10313,56'
      '10313,56'
      '10355,40'
      '10355,40'
      '10635,73'
      '10635,73'
      '10669,20'
      '10669,20'
      '10719,41'
      '10719,41'
      '10723,59'
      '10723,59'
      '10744,51'
      '10744,51'
      '10790,54'
      '10790,54'
      '10794,72'
      '10794,72'
      '10819,82'
      '10819,82'
      '10878,40'
      '10878,40'
      '10924,42'
      '10924,42'
      '10991,37'
      '10991,37'
      '10999,74'
      '10999,74'
      '11091,78'
      '11091,78'
      '11104,34'
      '11104,34'
      '11112,70'
      '11112,70'
      '11154,54'
      '11154,54'
      '11188,02'
      '11188,02'
      '11267,51'
      '11267,51'
      '11338,64'
      '11338,64'
      '11355,38'
      '11355,38'
      '11384,66'
      '11384,66'
      '11443,24'
      '11443,24'
      '11468,34'
      '11468,34'
      '11472,53'
      '11472,53'
      '11568,76'
      '11568,76'
      '11577,13'
      '11577,13'
      '11593,86'
      '11593,86'
      '11598,05'
      '11598,05'
      '11610,60'
      '11610,60'
      '11618,97'
      '11618,97'
      '11618,97'
      '11618,97'
      '11652,44'
      '11652,44'
      '11664,99'
      '11664,99'
      '11664,99'
      '11664,99'
      '11715,20'
      '11715,20'
      '11736,12'
      '11736,12'
      '11765,41'
      '11765,41'
      '11790,51'
      '11790,51'
      '11811,43'
      '11811,43'
      '11844,90'
      '11844,90'
      '11949,50'
      '11949,50'
      '11953,69'
      '11953,69'
      '12091,76'
      '12091,76'
      '12104,31'
      '12104,31'
      '12108,50'
      '12108,50'
      '12129,42'
      '12129,42'
      '12154,52'
      '12154,52'
      '12154,52'
      '12154,52'
      '12217,28'
      '12217,28'
      '12238,20'
      '12238,20'
      '12254,94'
      '12254,94'
      '12254,94'
      '12254,94'
      '12271,67'
      '12271,67'
      '12280,04'
      '12280,04'
      '12284,22'
      '12284,22'
      '12288,41'
      '12288,41'
      '12313,51'
      '12313,51'
      '12321,88'
      '12321,88'
      '12367,90'
      '12367,90'
      '12384,64'
      '12384,64'
      '12430,66'
      '12430,66'
      '12468,32'
      '12468,32'
      '12518,53'
      '12518,53'
      '12547,82'
      '12547,82'
      '12547,82'
      '12547,82')
    ScrollBars = ssVertical
    TabOrder = 1
    OnChange = InputMemoChange
  end
  object SMemo: TMemo
    Left = 254
    Top = 42
    Width = 150
    Height = 300
    ReadOnly = True
    TabOrder = 2
  end
  object HMemo: TMemo
    Left = 424
    Top = 44
    Width = 150
    Height = 298
    ReadOnly = True
    TabOrder = 3
  end
  object CMemo: TMemo
    Left = 593
    Top = 43
    Width = 150
    Height = 299
    ReadOnly = True
    TabOrder = 4
  end
  object TiMemo: TMemo
    Left = 143
    Top = 42
    Width = 74
    Height = 299
    Enabled = False
    TabOrder = 5
  end
  object btnExit: TButton
    Left = 624
    Top = 582
    Width = 119
    Height = 54
    Caption = 'Exit'
    TabOrder = 6
    OnClick = btnExitClick
  end
  object sgX: TStringGrid
    Left = 18
    Top = 384
    Width = 725
    Height = 173
    ColCount = 220
    DefaultColWidth = 30
    DefaultRowHeight = 15
    RowCount = 21
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing]
    TabOrder = 7
    RowHeights = (
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15
      15)
  end
  object XPManifest1: TXPManifest
    Left = 104
    Top = 8
  end
end
