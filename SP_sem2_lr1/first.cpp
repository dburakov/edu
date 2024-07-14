/*
�������  3.  �������� ������ �������� ����������� ������ �  ������ 
�������������� ��������� �������  GetSystemInfo. ���������  ������� 
��������� ������  � ������� �������  GlobalMemoryStatus.  � ������� 
�������  VirtualAlloc  ��������������� 2 ������� ������ (�� 2 �������� 
������). C  ������� �������  FillMemory  ��������� 1-� ������ ���������� 
0Fh. ����������� � ������� ������� CopyMemory ������ �� 1-�� ������� ��
2-��. �������� ������ � 1-�� ������� ������ � ������� ������� 
ZeroMemory. ��������� �������  VirtualQuery  ������������������
��������� ���������� � ���������� ������������ �������� ������.
���������� ��� ����������������� ����� ������ � ������� �������
VirtualFree. ��������� ���������� ������� VirtualLock, VirtualUnlock.
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
Memo1->Lines->Add("> ������ GetSystemInfo()");
Memo1->Lines->Add("������ �������� ������: " + IntToStr(inf.dwPageSize) + " ����");
Memo1->Lines->Add("������������� ��������������: " + IntToStr(inf.dwAllocationGranularity) + " ����");
Memo1->Lines->Add("����������� ����� ������: " + IntToHex(int(inf.lpMinimumApplicationAddress), 2) + "h");
Memo1->Lines->Add("������������ ����� ������: " + IntToHex(int(inf.lpMaximumApplicationAddress), 2) + "h");
Memo1->Lines->Add("����� �����������: " + IntToStr(inf.dwNumberOfProcessors));
Memo1->Lines->Add("������� �����: " + IntToStr(inf.dwActiveProcessorMask));
Memo1->Lines->Add("����������� ����������: " + IntToStr(inf.wProcessorLevel));
Memo1->Lines->Add("������� ����������� ����������: " + IntToStr(inf.wProcessorRevision));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
MEMORYSTATUS ms = {sizeof(ms)};
GlobalMemoryStatus (&ms);
//Memo1->Clear();
Memo1->Lines->Add(" ");
Memo1->Lines->Add(" ");
Memo1->Lines->Add("> ������ GlobalMemoryStatus()");
Memo1->Lines->Add("������������� �������: " + IntToStr(ms.dwMemoryLoad));
Memo1->Lines->Add("����� ���: " + IntToStr((__int64)ms.dwTotalPhys) + " ����");
Memo1->Lines->Add("������ ����������� �����: " + IntToStr((__int64)ms.dwTotalPageFile) + " ����");
Memo1->Lines->Add("�������� � ���������� �����: " + IntToStr((__int64)ms.dwAvailPageFile) + " ����");
Memo1->Lines->Add("������ ����������� ������: " + IntToStr(ms.dwTotalVirtual) + " ����");
Memo1->Lines->Add("�������� ����������� ������: " + IntToStr(ms.dwAvailVirtual) + " ����");
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
Memo1->Lines->Add("> ������ Lab1");

//�������������� ������ ��� ������� �������
adr1 = VirtualAlloc(NULL, 2*PAGE_SIZE, MEM_RESERVE|MEM_TOP_DOWN|MEM_COMMIT, PAGE_READWRITE);
if (adr1==NULL) {
	Form1->Close();
}
//VirtualAlloc(adr1, 2*PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
Memo1->Lines->Add("����� ������� ������� ����������������� ������ " + IntToHex(int(adr1), 2) + "h");

//�������������� ������ ��� ������� �������
adr2 = VirtualAlloc(NULL, 2*PAGE_SIZE, MEM_RESERVE|MEM_TOP_DOWN|MEM_COMMIT, PAGE_READWRITE);
if (adr2==NULL) {
	Form1->Close();
}
//VirtualAlloc(adr2, 2*PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
Memo1->Lines->Add("����� ������� ������� ����������������� ������ " + IntToHex(int(adr2), 2) + "h");

//��������� ������ ������ ��������� 0Fh
FillMemory(adr1, 2*PAGE_SIZE, __int8(15));

//�������� �������� �� ������� ������� �� ������
CopyMemory(PVOID(int(adr2)+PAGE_SIZE), adr1, PAGE_SIZE);

//�������� ������ ������
ZeroMemory(adr1, 0);

VirtualQuery(adr1, pmbi, sizeof(*pmbi));
Memo1->Lines->Add("��������� ������ ������ ������� " + IntToStr((__int64(pmbi->RegionSize))) + " ����");
VirtualQuery(adr2, pmbi, sizeof(*pmbi));
Memo1->Lines->Add("��������� ������ ������ ������� " + IntToStr((__int64(pmbi->RegionSize))) + " ����");
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

