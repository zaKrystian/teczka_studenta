//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(Edit1->Text==""){
		ShowMessage("Nie wpisano nazwy produktu");
	}
	else{
		ListBox1->Items->Add(Edit1->Text);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(ListBox1->ItemIndex==-1){
		ShowMessage("Nie wybrano przedmiotu!");
	}
	else{
		int arrayIndex = ListBox1->ItemIndex;
		ListBox2->Items->Add(ListBox1->Items->Strings[arrayIndex]);
		ListBox1->DeleteSelected();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(ListBox2->ItemIndex==-1){
		ShowMessage("Nie wybrano przedmiotu!");
	}
	else{
		int arrayIndex = ListBox2->ItemIndex;
		ListBox1->Items->Add(ListBox2->Items->Strings[arrayIndex]);
		ListBox2->DeleteSelected();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	ListBox1->Clear();
	ListBox2->Clear();
	ShowMessage("Dziêkujemy za zakupy i zapraszamy ponownie!");
	ListBox1->Items->Add("Procesor i5 9600K");
	ListBox1->Items->Add("P³yta g³ówna Gigabyte");
	ListBox1->Items->Add("RAM DDR4 2600MHz");
	ListBox1->Items->Add("Dysk SSD 240GB Plextor");
	ListBox1->Items->Add("Karta graficzna nVidia RTX 2080");
	ListBox1->Items->Add("Zasilacz 600W");
	ListBox1->Items->Add("Obudowa");
	ListBox1->Items->Add("Wewntylator");

}
//---------------------------------------------------------------------------
