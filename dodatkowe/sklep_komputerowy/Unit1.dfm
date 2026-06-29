object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 388
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ListBox1: TListBox
    Left = 8
    Top = 105
    Width = 241
    Height = 193
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ItemHeight = 20
    Items.Strings = (
      'Procesor i5 9600K'
      'P'#322'yta g'#322#243'wna Gigabyte'
      'RAM DDR4 2600MHz'
      'Dysk SSD 240GB Plextor'
      'Karta graficzna nVidia RTX 2080'
      'Zasilacz 600W'
      'Obudowa'
      'Wewntylator')
    ParentFont = False
    TabOrder = 0
  end
  object ListBox2: TListBox
    Left = 384
    Top = 105
    Width = 236
    Height = 193
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ItemHeight = 21
    ParentFont = False
    TabOrder = 1
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 80
    Width = 140
    Height = 25
    Caption = 'Dost'#281'pne produkty:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object StaticText2: TStaticText
    Left = 384
    Top = 80
    Width = 55
    Height = 25
    Caption = 'Koszyk:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object Button1: TButton
    Left = 272
    Top = 112
    Width = 89
    Height = 34
    Caption = 'Dodaj -->'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 272
    Top = 152
    Width = 89
    Height = 33
    Caption = '<-- Usu'#324
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button2Click
  end
  object StataticText3: TStaticText
    Left = 136
    Top = 20
    Width = 329
    Height = 54
    Caption = 'Sklep komputerowy'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object Button3: TButton
    Left = 432
    Top = 304
    Width = 188
    Height = 33
    Caption = 'Kup wybrane produkty'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 342
    Width = 121
    Height = 23
    TabOrder = 8
  end
  object StaticText3: TStaticText
    Left = 8
    Top = 318
    Width = 118
    Height = 19
    Caption = 'Dodawanie produktu:'
    TabOrder = 9
  end
  object Button4: TButton
    Left = 135
    Top = 341
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 10
    OnClick = Button4Click
  end
end
