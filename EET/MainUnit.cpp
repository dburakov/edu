//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include <cstdio>
#include "WaitUnit.h"
#define CSTD std::
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnStartClick(TObject *Sender)
{

   AnsiString Nvalue =  InputBox("Enter N", "Please, enter N (N<4000)", IntToStr(InputMemo->Lines->Count));
   int N;
   N = StrToInt(Nvalue);

   this->Cursor = crHourGlass;

   WaitForm->Show();
   WaitForm->Refresh();
   WaitForm->ProgressBar1->Position = 10;

   float R = 8.31447;
   float H[4001];

   for(int i = 1; i <= N; i++) H[i] = 0;

   //  Работа с файлом
   /*
   CSTD FILE *sourse;

   if(!(sourse = CSTD fopen("1.txt", "r+")))
   {
	 ShowMessage("Ошибка при открытии файла! ");
	 return;
   }

   char *buf[3001];
   for(int i = 1; i <= N; i++) CSTD fgets( buf[i],1,sourse);     //error here

   CSTD fclose(sourse);
   */

   TiMemo->Clear();
   SMemo->Clear();
   HMemo->Clear();
   CMemo->Clear(); 

   for(int i = 0; i <= N-1; i++) H[i+1] = StrToFloat(InputMemo->Lines[0][i]);

   double T[20];

   T[1] = 50;
   T[2] = 100;
   T[3] = 150;
   T[4] = 200;
   T[5] = 250;
   T[6] = 273.16;
   T[7] = 298.15;
   T[8] = 300;
   T[9] = 400;
   T[10] = 500;
   T[11] = 600;
   T[12] = 700;
   T[13] = 800;
   T[14] = 900;
   T[15] = 1000;
   T[16] = 1100;
   T[17] = 1200;
   T[18] = 1300;
   T[19] = 1400;
   T[20] = 1500;

   for(int t = 1;  t<= 20; t++) TiMemo->Lines->Add(FloatToStr(T[t]));

   float K[4001][20];
   for(int i = 1; i <= 20; i++)
   {
	   for(int t = 1;  t<= 20; t++) K[i][t] = 0;
   }
   float sK[20];

   for(int t = 1;  t<= 20; t++) sK[t] = 0;

   for(int t = 1;  t<= 20; t++) K[1][t] = 0;

   for(int i = 2; i <= N; i++)
   {
	   for(int t = 1;  t<= 20; t++)  K[i][t] = Exp( -( H[i]/(R*T[t]) ) );
   }

   for(int i = 1; i <= N; i++)
   {
	   for(int t = 1;  t<= 20; t++) sK[t] = sK[t] + K[i][t];
   }

   float sX[20];

   for(int t = 1;  t<= 20; t++) sX[t] = sK[t]/(1+sK[t]);

   float X[4001][20];

   for(int t = 1;  t<= 20; t++) X[1][t] = 1 - sX[t];

   for(int i = 2; i <= N; i++)
   {
	   for(int t = 1;  t<= 20; t++) X[i][t] = K[i][t] * (1 - sX[t]);
   }

   WaitForm->ProgressBar1->Position = 30;

   float theS[20]; //Энтропия
   float temp[20];

   for(int t = 1;  t<= 20; t++) temp[t] = 0;

   for(int i = 1; i <= N; i++)
   {
	   for(int t = 1;  t<= 20; t++) temp[t] = temp[t] + X[i][t]*Ln( X[i][t] );
   }

   for(int t = 1;  t<= 20; t++) theS[t] = -R * temp[t];

   for(int t = 1;  t<= 20; t++) SMemo->Lines->Add(FloatToStr(theS[t]));

   float theH[20];//Энтальпия

   for(int t = 1;  t<= 20; t++) theH[t] = 0;

   for(int i = 2; i <= N; i++)
   {
	   for(int t = 1;  t<= 20; t++) theH[t] = theH[t] + X[i][t]*H[i]/T[t];
   }

   for(int t = 1;  t<= 20; t++) HMemo->Lines->Add(FloatToStr(theH[t]));

   WaitForm->ProgressBar1->Position = 50;

   float theC[20];//Теплоемкость

   for(int t = 1;  t<= 20; t++) theC[t] = 0;

   float SumJ[4001][20];

   for(int i = 1; i <= N; i++)
   {
	   for(int t = 1;  t<= 20; t++) SumJ[i][t] = 0;
   }

   for(int i = 1; i <= N-1; i++)
   {
	   for(int j = 1; j <= N-i; j++)
	   {
			for(int t = 1;  t<= 20; t++) SumJ[i][t] = SumJ[i][t] + X[i+j][t] * ( H[i+j] - H[i] ) * ( H[i+j] - H[i] );
	   }
   }

   float SumI[20];

   for(int t = 1;  t<= 20; t++) SumI[t] = 0;

   for(int i = 1; i <= N-1; i++)
   {
	   for(int t = 1;  t<= 20; t++) SumI[t] = SumI[t] + X[i][t]*SumJ[i][t];
   }

   for(int t = 1;  t<= 20; t++) theC[t] = 1/(R*T[t]*T[t]) * SumI[t];

   for(int t = 1;  t<= 20; t++) CMemo->Lines->Add(FloatToStr(theC[t]));

   WaitForm->ProgressBar1->Position = 80;

   //--------------

   sgX->ColCount = N+1;
   sgX->RowCount = 21;

   for(int i = 1; i <= N; i++)  sgX->Cells[i][0] = "X" + IntToStr(i);

   for(int t = 1;  t<= 20; t++) sgX->Cells[0][t] = IntToStr(t);

   for(int i = 1; i <= N; i++)
   {
	   for(int t = 1;  t<= 20; t++)	sgX->Cells[i][t] = FloatToStr(  0.01*(int)(100*(float)(  X[i][t]  +0.005))  );
   }

   WaitForm->ProgressBar1->Position = 100;

   this->Cursor = crArrow;
   WaitForm->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnExitClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::InputMemoChange(TObject *Sender)
{
NInSource->Caption = "Now " + IntToStr(InputMemo->Lines->Count) + " tokens are in source";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
InputMemoChange(Sender);
}
//---------------------------------------------------------------------------

