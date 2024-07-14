//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <string.h>
#include <time.h>


#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
AnsiString array[100];
int N = 0;
int iteration = 0;
int seq[40];
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void loadSeq(void)
{
	if(StrToInt(MainForm->seqMemo->Lines->Strings[0]) != 1)
	{
		ShowMessage("Первый ключ должен быть единицей!");
    }
	for(int i = 0; i < MainForm->seqMemo->Lines->Count; i++)
	{
		seq[i] = StrToInt(MainForm->seqMemo->Lines->Strings[i]);
	}

}
//---------------------------------------------------------------------------
void shellSort(AnsiString a[], long size)
{
  long inc, i, j;
  int s;

  // загрузка последовательности приращений
  loadSeq();

  s = MainForm->seqMemo->Lines->Count-1;
  MainForm->lSteps->Caption = IntToStr(s+1);
  while (s >= 0)
  {
	// сортировка вставками с инкрементами inc[]
	inc = seq[s--];
	for (i = inc; i < size; i++)
	{
	  AnsiString temp = a[i];
	  for (j = i-inc; (j >= 0) && (a[j] > temp); j -= inc)
	  {
		a[j+inc] = a[j];
		iteration++;
		Sleep(1);   //чтобы была видна разница во времени
	  }
	  a[j+inc] = temp;
	}
  }
}
//---------------------------------------------------------------------------
inline long long gettimeus()
{
    static LARGE_INTEGER ClockPerSecond = { 0 };
    if( ClockPerSecond.QuadPart == 0 ) QueryPerformanceFrequency( &ClockPerSecond );
    LARGE_INTEGER li;
    QueryPerformanceCounter( &li );
	return li.QuadPart * 1000000LL / ClockPerSecond.QuadPart;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartButtonClick(TObject *Sender)
{
	InMemo->Clear();
	OutMemo->Clear();
	iteration = 0;

	FILE  *inputfile;
	inputfile=fopen("\Data\\inputfile.txt","r+");
	if (inputfile == NULL) {
		ShowMessage("ERROR. File not found: Data\inputfile.txt");
	}
	int i = 0;
	char buf[1024];
	array[0] = 0;
	while (fgets(buf,1024,inputfile))
	{
		array[i] = buf;
		InMemo->Lines->Append(array[i]);
		i++;
	}
	fclose(inputfile);
	N = i;

	long long duration = -gettimeus();

	shellSort(array, N);

	duration += gettimeus();

	lSortTime->Caption = FloatToStrF(duration, ffFixed, 8, 2);


	lIteration->Caption = IntToStr(iteration);

	for(int i=0;i<=N-1;i++)
	{
		if(array[i] != array[i+1])
		OutMemo->Lines->Append(array[i]);
	}

	FILE  *outputfile;
	outputfile=fopen("\Data\\outputfile.txt","w");
	for(int i=0;i<=N;i++) fputs((char*)array[i].c_str(),outputfile);
	fclose(outputfile);

}
//---------------------------------------------------------------------------

