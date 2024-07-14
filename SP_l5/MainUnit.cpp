//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include <stdio.h>
#include <time.h>
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
	clock_t start=clock();
	int h;
	float y0[8455];

	for(int n = 0; n < 8455; n++){
		y0[n] = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718) h = 0;
			else h = f0[k];
			y0[n] = y0[n] + h*data[n-k];
		}
	}

	float y1[8455];

	for(int n = 0; n < 8455; n++){
		y1[n] = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718) h = 0;
			else h = f1[k];
			y1[n] = y1[n] + h*data[n-k];
		}
	}

	float y2[8455];

	for(int n = 0; n < 8455; n++){
		y2[n] = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718) h = 0;
			else h = f2[k];
			y2[n] = y2[n] + h*data[n-k];
		}
	}

	int m0 = StrToInt(Edit1->Text);
	int m1 = StrToInt(Edit2->Text);
	int m2 = StrToInt(Edit3->Text);

	float y[8455];
	
	for(int n = 0; n < 8455; n++){
		y[n] = m0*y0[n] + m1*y1[n] + m2*y2[n];
	}

	FILE * pFile;
	pFile = fopen( "result.txt" , "wb" );
	//fwrite(&y, 8455, sizeof(float), pFile);
	for(int n = 0; n < 8455; n++){
		fputs (FloatToStr(y[n]).c_str(),pFile);
		fputs ("\r\n",pFile);
	}
	fclose (pFile);

	clock_t finish=clock();
	double workTime=(double)(finish - start) / CLOCKS_PER_SEC;
	l_ExeTime->Caption = FloatToStr(workTime);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
	clock_t start=clock();
	int h0,h1,h2;

	float y0[8455];
	float y1[8455];
	float y2[8455];
	float y[8455];

	float temp = 0;
	float * adr_y0;
	float * adr_y1;
	float * adr_y2;
	float * adr_y;
	adr_y0 = y0;
	adr_y1 = y1;
	adr_y2 = y2;
	adr_y = y;



	for(int n = 0; n < 8455; n++){
		y0[n] = 0;
		y1[n] = 0;
		y2[n] = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718){
				h0 = 0;
				h1 = 0;
				h2 = 0;
			}else{
				h0 = f0[k];
				h1 = f1[k];
				h2 = f2[k];
			}
			y0[n] = y0[n] + h0*data[n-k];
			y1[n] = y1[n] + h1*data[n-k];
			y2[n] = y2[n] + h2*data[n-k];
		}
	}

	int m0 = StrToInt(Edit1->Text);
	int m1 = StrToInt(Edit2->Text);
	int m2 = StrToInt(Edit3->Text);

	asm
	{
		mov ecx,8455;	 	 //counter = 8455

		xor	esi,esi          //обнуление esi  (i)
		xor	eax,eax			 //обнуление eax  (a)

 loop1:
		mov edx,adr_y0
		mov eax,edx[esi*4]  //eax = y0[i]

		mov ebx,m0  		//ebx = m0

		imul eax,ebx        //eax = y0[i]*m0

		mov edx,temp
		mov edx,eax  		//temp = m0*y0[n]

		mov edx,adr_y1
		mov eax,edx[esi*4]  //eax = y1[i]

		mov ebx,m1  		//ebx = m1

		imul eax,ebx        //eax = y1[i]*m1

		mov ebx,temp        //ebx = temp

		add eax,ebx         //eax = y0[i]*m0 + y1[i]*m1

		mov edx,temp
		mov edx,eax  		//temp = y0[i]*m0 + y1[i]*m1

		mov edx,adr_y2
		mov eax,edx[esi*4]  //eax = y2[i]

		mov ebx,m2  		//ebx = m2

		imul eax,ebx        //eax = y2[i]*m2

		mov ebx,temp        //ebx = temp

		add eax,ebx         //eax = y0[i]*m0 + y1[i]*m1 + y2[i]*m2

		mov edx,adr_y
		mov edx[esi*4],eax  //y[i] = eax

		inc	esi             //inc(i)

		sub ecx,8
		cmp ecx,0
		jg loop1        	//dec(counter);  if(counter != 0) goto loop1;
		emms
	}

	FILE * pFile;
	pFile = fopen( "result.txt" , "wb" );
	//fwrite(&y, 8455, sizeof(float), pFile);
	for(int n = 0; n < 8455; n++){
		fputs (FloatToStr(y[n]).c_str(),pFile);
		fputs ("\r\n",pFile);
	}
	fclose (pFile);

	clock_t finish=clock();
	double workTime=(double)(finish - start) / CLOCKS_PER_SEC;
	l_ExeTime->Caption = FloatToStr(workTime);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button3Click(TObject *Sender)
{
	clock_t start=clock();
	int h0,h1,h2;

	float y0[8455];
	float y1[8455];
	float y2[8455];
	float y[8455];

	float * adr_y0;
	float * adr_y1;
	float * adr_y2;
	float * adr_y;
	adr_y0 = y0;
	adr_y1 = y1;
	adr_y2 = y2;
	adr_y = y;



	for(int n = 0; n < 8455; n++){
		y0[n] = 0;
		y1[n] = 0;
		y2[n] = 0;
		for(int k = 0; k < n; k++){
			if(k > 1718){
				break;
			}else{
				h0 = f0[k];
				h1 = f1[k];
				h2 = f2[k];
			}
			y0[n] = y0[n] + h0*data[n-k];
			y1[n] = y1[n] + h1*data[n-k];
			y2[n] = y2[n] + h2*data[n-k];
		}
	}

	int m0 = StrToInt(Edit1->Text);
	int m1 = StrToInt(Edit2->Text);
	int m2 = StrToInt(Edit3->Text);

	asm
	{
		mov ecx,8192;	 	 //counter = 8455 (mod 8)

		xor	esi,esi          //обнуление esi  (i)
		xor	eax,eax			 //обнуление eax  (a)

 loop1:
		mov edx,adr_y0
		movq mm0, edx[esi*4]  //mm0 = y0[i]

		movd mm3,m0  		  //mm3 = m0

		PMULHW mm0,mm3        //mm0 = y0[i]*m0

		mov edx,adr_y1
		movq mm1,edx[esi*4]  //mm1 = y1[i]

		movd mm3,m1  		//mm3 = m1

		PMULHW mm1,mm3        //mm1 = y1[i]*m1

		PADDW mm0,mm1       //mm0 = y0[i]*m0 + y1[i]*m1


		mov edx,adr_y2
		movq mm2,edx[esi*4]  //mm2 = y2[i]

		movd mm3,m2  		//mm3 = m2

		PMULHW mm2,mm3        //mm2 = y2[i]*m2

		PADDW mm0,mm2       //mm0 = y0[i]*m0 + y1[i]*m1 + y2[i]*m2

		mov edx,adr_y
		movq edx[esi*4],mm0  //y[i] = mm0

		inc	esi             //inc(i)

		sub ecx,8
		cmp ecx,0
		jg loop1        	//dec(counter);  if(counter != 0) goto loop1;
		emms
	}

	FILE * pFile;
	pFile = fopen( "result.txt" , "wb" );
	//fwrite(&y, 8455, sizeof(float), pFile);
	for(int n = 0; n < 8455; n++){
		fputs (FloatToStr(y[n]).c_str(),pFile);
		fputs ("\r\n",pFile);
	}
	fclose (pFile);

	clock_t finish=clock();
	double workTime=(double)(finish - start) / CLOCKS_PER_SEC;
	l_ExeTime->Caption = FloatToStr(workTime);
}
//---------------------------------------------------------------------------

