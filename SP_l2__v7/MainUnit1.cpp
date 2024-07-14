//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
	int DataSize = 6;
	int RowSize = 2;
	int ColSize = 3;

	int PositNum = 0;
	int NegotNum = 0;
	
	int* arData;

	int* arRes;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{

	sgData->Cells[0][0] = "-2"; sgData->Cells[1][0] = "-3"; sgData->Cells[2][0] = "-4"; sgData->Cells[3][0] = "-4";
	sgData->Cells[0][1] = "2"; sgData->Cells[1][1] = "3"; sgData->Cells[2][1] = "4"; sgData->Cells[3][1] = "4";
	sgData->Cells[0][2] = "6"; sgData->Cells[1][2] = "7"; sgData->Cells[2][2] = "8"; sgData->Cells[3][2] = "8";

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	btnChangeSizeClick(Sender);
	PositNum = 0;
	NegotNum = 0;

	for (int i = 0; i < RowSize; i++)
		for (int j = 0; j < ColSize; j++)
			*(arData+j+i*ColSize)=StrToInt(sgData->Cells[j][i]);

	asm
	{
		mov ecx,DataSize;	 //counter = DataSize
		xor	esi,esi          //обнуление esi  (i)
		xor	eax,eax			 //обнуление eax  (a)

loop1:
		mov edx,arData
		mov eax,edx[esi*4]  //eax = arData[i]

		mov bx, 0
		cmp ax,bx
		jl less

more:	inc dword ptr PositNum
		jmp cont
less:   inc dword ptr NegotNum
cont:   neg eax             //inverting
		mov edx[esi*4],eax  //arData[i] = eax

		inc	esi             //inc(i)

		loop loop1          //dec(counter);  if(counter != 0) goto loop1;
	}

	ShowMessage(" оличество положительных чисел: "+IntToStr(PositNum));
	ShowMessage(" оличество отрицательных чисел: "+IntToStr(NegotNum));
	
	for (int i = 0; i < RowSize; i++)
		for (int j = 0; j < ColSize; j++)
			sgData->Cells[j][i] =  IntToStr(*(arData+j+i*ColSize));
			

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnChangeSizeClick(TObject *Sender)
{
	RowSize = StrToInt(eSize->Text);
	ColSize = StrToInt(cSize->Text);
	DataSize = RowSize * ColSize;
	sgData->RowCount = RowSize;
	sgData->ColCount = ColSize;
	arData = new int[DataSize];
}
//---------------------------------------------------------------------------


