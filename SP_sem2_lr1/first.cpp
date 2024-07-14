/*
Вариант  3.  Получить размер страницы виртуальной памяти и  другие 
характеристики используя функцию  GetSystemInfo. Проверить  текущее 
состояние памяти  с помощью функции  GlobalMemoryStatus.  С помощью 
функции  VirtualAlloc  зарезервировать 2 региона памяти (по 2 страницы 
каждый). C  помощью функции  FillMemory  заполнить 1-й регион значениями 
0Fh. Скопировать с помощью функции CopyMemory данные из 1-го региона во
2-ой. Обнулить данные в 1-ом регионе памяти с помощью функции 
ZeroMemory. Используя функции  VirtualQuery  продемонстрировать
системную информацию и содержимое используемых регионов памяти.
Освободить всю зарезервированную ранее память с помощью функции
VirtualFree. Объяснить назначение функций VirtualLock, VirtualUnlock.
*/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "first.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

PVOID adr1, adr2;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btShowClick(TObject *Sender)
{
SYSTEM_INFO inf;
GetSystemInfo (&inf);
//Memo1->Clear();
Memo1->Lines->Add(" ");
Memo1->Lines->Add(" ");
Memo1->Lines->Add("> запуск GetSystemInfo()");
Memo1->Lines->Add("Размер страницы памяти: " + IntToStr(inf.dwPageSize) + " байт");
Memo1->Lines->Add("Гранулярность резервирования: " + IntToStr(inf.dwAllocationGranularity) + " байт");
Memo1->Lines->Add("Минимальный адрес памяти: " + IntToHex(int(inf.lpMinimumApplicationAddress), 2) + "h");
Memo1->Lines->Add("Максимальный адрес памяти: " + IntToHex(int(inf.lpMaximumApplicationAddress), 2) + "h");
Memo1->Lines->Add("Число процессоров: " + IntToStr(inf.dwNumberOfProcessors));
Memo1->Lines->Add("Битовая маска: " + IntToStr(inf.dwActiveProcessorMask));
Memo1->Lines->Add("Архитектура процессора: " + IntToStr(inf.wProcessorLevel));
Memo1->Lines->Add("Уровень архитектуры процессора: " + IntToStr(inf.wProcessorRevision));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
MEMORYSTATUS ms = {sizeof(ms)};
GlobalMemoryStatus (&ms);
//Memo1->Clear();
Memo1->Lines->Add(" ");
Memo1->Lines->Add(" ");
Memo1->Lines->Add("> запуск GlobalMemoryStatus()");
Memo1->Lines->Add("Загруженность системы: " + IntToStr(ms.dwMemoryLoad));
Memo1->Lines->Add("Объем ОЗУ: " + IntToStr((__int64)ms.dwTotalPhys) + " байт");
Memo1->Lines->Add("Размер страничного файла: " + IntToStr((__int64)ms.dwTotalPageFile) + " байт");
Memo1->Lines->Add("Свободно в страничком файле: " + IntToStr((__int64)ms.dwAvailPageFile) + " байт");
Memo1->Lines->Add("Размер виртуальной памяти: " + IntToStr(ms.dwTotalVirtual) + " байт");
Memo1->Lines->Add("Свободно виртуальной памяти: " + IntToStr(ms.dwAvailVirtual) + " байт");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
SYSTEM_INFO inf;
GetSystemInfo (&inf);
int PAGE_SIZE = int(inf.dwPageSize);
PMEMORY_BASIC_INFORMATION pmbi = new MEMORY_BASIC_INFORMATION;

//Memo1->Clear();
Memo1->Lines->Add(" ");
Memo1->Lines->Add(" ");
Memo1->Lines->Add("> запуск Lab1");

//резервирование памяти для первого региона
adr1 = VirtualAlloc(NULL, 2*PAGE_SIZE, MEM_RESERVE|MEM_TOP_DOWN|MEM_COMMIT, PAGE_READWRITE);
if (adr1==NULL) {
	Form1->Close();
}
//VirtualAlloc(adr1, 2*PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
Memo1->Lines->Add("Адрес первого региона зарезервированной памяти " + IntToHex(int(adr1), 2) + "h");

//резервирование памяти для второго региона
adr2 = VirtualAlloc(NULL, 2*PAGE_SIZE, MEM_RESERVE|MEM_TOP_DOWN|MEM_COMMIT, PAGE_READWRITE);
if (adr2==NULL) {
	Form1->Close();
}
//VirtualAlloc(adr2, 2*PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
Memo1->Lines->Add("Адрес второго региона зарезервированной памяти " + IntToHex(int(adr2), 2) + "h");

//заполняем первый регион значением 0Fh
FillMemory(adr1, 2*PAGE_SIZE, __int8(15));

//копируем значение из первого региона во второй
CopyMemory(PVOID(int(adr2)+PAGE_SIZE), adr1, PAGE_SIZE);

//обнуляем первый регион
ZeroMemory(adr1, 0);

VirtualQuery(adr1, pmbi, sizeof(*pmbi));
Memo1->Lines->Add("Суммарный размер группы страниц " + IntToStr((__int64(pmbi->RegionSize))) + " байт");
VirtualQuery(adr2, pmbi, sizeof(*pmbi));
Memo1->Lines->Add("Суммарный размер группы страниц " + IntToStr((__int64(pmbi->RegionSize))) + " байт");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (adr1!=NULL) {
	VirtualFree(adr1, NULL, MEM_RELEASE);
}

if (adr2!=NULL) {
	VirtualFree(adr2, NULL, MEM_RELEASE);
}
Form1->Close();
}
//---------------------------------------------------------------------------

