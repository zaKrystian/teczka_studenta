//---------------------------------------------------------------------------

//Autorzy: Krystian Kachniarz, Kamil Chochorowski, Dominik Koszyk
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int checkWinner();

char currentPlayer[2] = {'x','o'};
int currentIndex = 0;

char clicked[9] = {' '};




bool stop = false;


char clickHandler(int keyNumber){

	if(clicked[keyNumber] == 'X' || clicked[keyNumber] == 'O'  || stop){
		return(clicked[keyNumber]);
	}
	else{
		if(currentPlayer[currentIndex] == 'x'){
			currentIndex++;
			if(currentIndex == 2)  currentIndex = 0;
		   clicked[keyNumber] = 'X';
		   Form1->Edit1->Text = "O";

		   return('X');

		}
		else{

		   clicked[keyNumber] = 'O';
		   currentIndex++;
			if(currentIndex == 2)  currentIndex = 0;
		   Form1->Edit1->Text = "X";
		   return('O');
		}

	}




}

int checkWinner(){

	if (stop) {
	   return 0;
	}
   if(clicked[0] == 'X' && clicked[3] == 'X' && clicked[6] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;
   }

   if(clicked[0] == 'O' && clicked[3] == 'O' && clicked[6] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }

   if(clicked[6] == 'X' && clicked[7] == 'X' && clicked[8] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;

   }

   if(clicked[6] == 'O' && clicked[7] == 'O' && clicked[8] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }

   if(clicked[2] == 'X' && clicked[5] == 'X' && clicked[8] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;

   }

   if(clicked[2] == 'O' && clicked[5] == 'O' && clicked[8] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }

   if(clicked[0] == 'X' && clicked[1] == 'X' && clicked[2] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;

   }

   if(clicked[0] == 'O' && clicked[1] == 'O' && clicked[2] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }

   if(clicked[3] == 'X' && clicked[4] == 'X' && clicked[5] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;

   }

   if(clicked[3] == 'O' && clicked[4] == 'O' && clicked[5] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }

   if(clicked[1] == 'X' && clicked[4] == 'X' && clicked[7] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;

   }

   if(clicked[1] == 'O' && clicked[4] == 'O' && clicked[7] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }

   if(clicked[0] == 'X' && clicked[4] == 'X' && clicked[8] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;

   }

   if(clicked[0] == 'O' && clicked[4] == 'O' && clicked[8] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }

   if(clicked[2] == 'X' && clicked[4] == 'X' && clicked[6] == 'X'){
		ShowMessage("Wygrywa X!");
		stop = true;

   }

   if(clicked[2] == 'O' && clicked[4] == 'O' && clicked[6] == 'O'){
		ShowMessage("Wygrywa O!");
		stop = true;

   }


}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form1->Button1->Caption = clickHandler(0);
	checkWinner();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form1->Button2->Caption = clickHandler(1);
	checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Form1->Button3->Caption = clickHandler(2);
	checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
Form1->Button4->Caption = clickHandler(3);
checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form1->Button5->Caption = clickHandler(4);
checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form1->Button6->Caption = clickHandler(5);
checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
Form1->Button7->Caption = clickHandler(6);
checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
Form1->Button8->Caption = clickHandler(7);
checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
Form1->Button9->Caption = clickHandler(8);
checkWinner();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	currentIndex = 0;
	stop = false;
	 for(int i = 0; i<9; i++){
		clicked[i] = ' ';
	 }

	Form1->Button1->Caption =  ' ';
	Form1->Button2->Caption =  ' ';
	Form1->Button3->Caption =  ' ';
	Form1->Button4->Caption =  ' ';
	Form1->Button5->Caption =  ' ';
	Form1->Button6->Caption =  ' ';
	Form1->Button7->Caption =  ' ';
	Form1->Button8->Caption =  ' ';
	Form1->Button9->Caption =  ' ';

	Form1->Edit1->Text = "X";


}
//---------------------------------------------------------------------------
