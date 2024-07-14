//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include <stdio.h>
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
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	int h;
	float* y0[8455];
	float* multres;
	for(int n = 0; n < 8455; n++){
		*(y0+n) = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718) h = 0;
			else h = f0[k];
			*multres = h*data[n-k];
			asm
			{
				mov eax,y0+n;
				mov ebx,multres
				add eax,ebx
				mov edx,y0+n
				mov edx,eax
			}                          
		}
	}
	float* y1[8455];
	for(int n = 0; n < 8455; n++){
		*(y1+n) = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718) h = 0;
			else h = f1[k];
			*(y1+n) = *(y1+n) + h*data[n-k];
		}
	}
	float* y2[8455];
	for(int n = 0; n < 8455; n++){
		*(y2+n) = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718) h = 0;
			else h = f2[k];
			*(y2+n) = *(y2+n) + h*data[n-k];
		}
	}

	int m0 = StrToInt(Edit1->Text);
	int m1 = StrToInt(Edit2->Text);
	int m2 = StrToInt(Edit3->Text);

	
	float y[8455];  /*
	for(int n = 0; n < 8455; n++){
		y[n] = m0*y0[n] + m1*y1[n] + m2*y2[n];
	} */
	float temp = 0;
	//ShowMessage(IntToStr(sizeof(float)));
	asm
	{
		mov ecx,2;	 	 //counter = 8455

		xor	esi,esi          //обнуление esi  (i)
		xor	eax,eax			 //обнуление eax  (a)

 loop1:
		mov edx,y0
		mov eax,edx[esi*4]  //eax = y0[i]

		mov ebx,m0  		//ebx = m0

		imul eax,ebx        //eax = y0[i]*m0

		mov edx,temp
		mov edx,eax  		//temp = m0*y0[n]

		mov edx,y1
		mov eax,edx[esi*4]  //eax = y1[i]

		mov ebx,m0  		//ebx = m1

		imul eax,ebx        //eax = y1[i]*m1

		mov ebx,temp        //ebx = temp

		add eax,ebx         //eax = y0[i]*m0 + y1[i]*m1

		mov edx,temp
		mov edx,eax  		//temp = y0[i]*m0 + y1[i]*m1

		mov edx,y2
		mov eax,edx[esi*4]  //eax = y2[i]

		mov ebx,m2  		//ebx = m2

		imul eax,ebx        //eax = y2[i]*m2

		mov ebx,temp        //ebx = temp

		add eax,ebx         //eax = y0[i]*m0 + y1[i]*m1 + y2[i]*m2

		mov edx,y
		mov edx[esi*4],eax  //y[i] = eax

		inc	esi             //inc(i)

		loop loop1          //dec(counter);  if(counter != 0) goto loop1;
	}


	FILE * pFile;
	pFile = fopen( "result.txt" , "wb" );
	//fwrite(&y, 8455, sizeof(float), pFile);
	for(int n = 0; n < 8455; n++){
		fputs (FloatToStr(y[n]).c_str(),pFile);
		fputs ("\r\n",pFile);
	}
	fclose (pFile);

}
//---------------------------------------------------------------------------
