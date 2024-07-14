//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
//int ar[8]={1,2,3,4,5,6,7,8};

int a = StrToInt(Edit1->Text);
int b = StrToInt(Edit2->Text);
int c = StrToInt(Edit3->Text);
int res = 0;

asm {
	mov eax,a;
	mov ebx,b;
	imul eax,ebx;

	mov ebx,c;
	sar ebx,1;

	sub eax,ebx;
	mov res,eax;
}
lResult->Caption = IntToStr(res);

}
//---------------------------------------------------------------------------

