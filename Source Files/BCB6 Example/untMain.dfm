object frmMain: TfrmMain
  Left = 305
  Top = 150
  Width = 655
  Height = 586
  Caption = 'CMySQL Test Application'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    647
    559)
  PixelsPerInch = 96
  TextHeight = 13
  object grpConnection: TGroupBox
    Left = 8
    Top = 8
    Width = 633
    Height = 73
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Connection'
    TabOrder = 0
    DesignSize = (
      633
      73)
    object lbl1: TLabel
      Left = 8
      Top = 16
      Width = 57
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Server:'
    end
    object lbl4: TLabel
      Left = 272
      Top = 48
      Width = 57
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Password:'
    end
    object lbl2: TLabel
      Left = 8
      Top = 48
      Width = 57
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Database:'
    end
    object lbl3: TLabel
      Left = 272
      Top = 16
      Width = 57
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Username:'
    end
    object edtServer: TEdit
      Left = 72
      Top = 13
      Width = 176
      Height = 21
      TabOrder = 0
      Text = '127.0.0.1'
    end
    object edtPassword: TEdit
      Left = 336
      Top = 45
      Width = 162
      Height = 21
      TabOrder = 3
    end
    object edtDatabase: TEdit
      Left = 72
      Top = 45
      Width = 176
      Height = 21
      TabOrder = 2
      Text = 'mydb'
    end
    object edtUsername: TEdit
      Left = 336
      Top = 13
      Width = 162
      Height = 21
      TabOrder = 1
      Text = 'root'
    end
    object btnConnect: TButton
      Left = 548
      Top = 40
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = 'Connect'
      TabOrder = 4
      OnClick = btnConnectClick
    end
  end
  object grpQuery: TGroupBox
    Left = 8
    Top = 88
    Width = 633
    Height = 49
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Query'
    TabOrder = 1
    DesignSize = (
      633
      49)
    object edtQuery: TEdit
      Left = 8
      Top = 20
      Width = 529
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Enabled = False
      TabOrder = 0
    end
    object btnQuery: TButton
      Left = 550
      Top = 16
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Execute'
      Default = True
      Enabled = False
      TabOrder = 1
      OnClick = btnQueryClick
    end
  end
  object grpResult: TGroupBox
    Left = 8
    Top = 144
    Width = 633
    Height = 409
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'Result'
    TabOrder = 2
    DesignSize = (
      633
      409)
    object grdResult: TStringGrid
      Left = 8
      Top = 16
      Width = 617
      Height = 383
      Anchors = [akLeft, akTop, akRight, akBottom]
      FixedCols = 0
      TabOrder = 0
      ColWidths = (
        87
        95
        114
        112
        112)
    end
  end
end
