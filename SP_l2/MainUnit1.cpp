//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
	int DataSize = 2;
	
	int* arA;
	int* arB;
	int* arC;
	int* arRes;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	sgData->Cells[0][0] = "a";
	sgData->Cells[1][0] = "b";
	sgData->Cells[2][0] = "c";
	sgData->Cells[3][0] = "Result";

	sgData->Cells[0][1] = "2"; sgData->Cells[1][1] = "3"; sgData->Cells[2][1] = "4";
	sgData->Cells[0][2] = "6"; sgData->Cells[1][2] = "7"; sgData->Cells[2][2] = "8";

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	btnChangeSizeClick(Sender);

	for (int i = 0; i < DataSize; i++)
	  *(arA+i) = StrToInt(sgData->Cells[0][i+1]);

	for (int i = 0; i < DataSize; i++)
	  *(arB+i) = StrToInt(sgData->Cells[1][i+1]);

	for (int i = 0; i < DataSize; i++)
	  *(arC+i) = StrToInt(sgData->Cells[2][i+1]);

	asm
	{
		mov ecx,DataSize;	 //counter = DataSize

		xor	esi,esi          //обнуление esi  (i)
		xor	eax,eax			 //обнуление eax  (a)

 loop1:
		mov edx,arA
		mov eax,edx[esi*4]  //eax = arA[i]

		mov edx,arB
		mov ebx,edx[esi*4]  //ebx = arB[i]

		imul eax,ebx        //eax = eax*ebx

		mov edx,arC
		mov ebx,edx[esi*4]  //ebx = arC[i]

		sar ebx,1           //ebx = ebx/2

		sub eax,ebx         //eax = eax - ebx

		mov edx,arRes
		mov edx[esi*4],eax  //arRes[i] = eax

		inc	esi             //inc(i)

		loop loop1          //dec(counter);  if(counter != 0) goto loop1;
	}


	for (int i = 0; i < DataSize; i++)
		sgData->Cells[3][i+1] = IntToStr(*(arRes+i));

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnChangeSizeClick(TObject *Sender)
{
	DataSize = StrToInt(eSize->Text);
	sgData->RowCount = DataSize +1;
	arA = new int[DataSize*4];
	arB = new int[DataSize*4];
	arC = new int[DataSize*4];
	arRes = new int[DataSize*4];
}
//---------------------------------------------------------------------------

