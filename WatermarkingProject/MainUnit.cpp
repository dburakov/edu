//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//AnsiString InputFile;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnPreviewClick(TObject *Sender)
{
	LOGFONT TheFont;
	TheImage->Canvas->Brush->Style = bsClear;     					// ����� ���������� ����� �����
	ZeroMemory(&TheFont, sizeof(LOGFONT));   						//������� ������
	TheFont.lfHeight = FontDialog1->Font->Height;     				// ������ ������ (������ ����������� ��������)
	TheFont.lfEscapement = 0; 										// ���� �������� ��������: 45*00" = 450
	TheFont.lfOrientation = 900;              						// ����������  � ������� ����� �������
	TheFont.lfCharSet = DEFAULT_CHARSET;       						// ����� ��������
	strcpy(TheFont.lfFaceName, FontDialog1->Font->Name.c_str());    // �����

	int posX;
	int posY;
	if (RadioButton1->Checked) {
		 posX = eOffset->Text.ToInt() - TheFont.lfHeight;
		 posY = 5;
		 if (cbRotate->Checked) {
			 TheFont.lfEscapement = 270*10 ; 				// ���� �������� ��������: 45*00" = 450
		 }
	}else{
		 posX = eOffset->Text.ToInt();
		 posY = TheImage->Picture->Height + FontDialog1->Font->Height - 5;
		 if (cbRotate->Checked) {
			 TheFont.lfEscapement = 90*10 ; 				// ���� �������� ��������: 45*00" = 450
		 }
	}
	TheImage->Canvas->Font->Handle = CreateFontIndirect(&TheFont); 	// ������� �� ��������� �����
	TheImage->Canvas->TextOutA(posX,posY,WatermarkString->Text);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N2Click(TObject *Sender)
{
	OpenDialog1->InitialDir = ExtractFilePath(Application->ExeName);
	if (!OpenDialog1->Execute()) return;
	TheImage->Picture->LoadFromFile(OpenDialog1->FileName);
	MainForm->Caption = "Watermark Utility: "+OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N7Click(TObject *Sender)
{
	if (!FontDialog1->Execute()) return;
	TheImage->Canvas->Font = FontDialog1->Font;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N3Click(TObject *Sender)
{
	SaveDialog1->InitialDir = ExtractFilePath(Application->ExeName);
	if (!SaveDialog1->Execute()) return;
	TheImage->Picture->SaveToFile(SaveDialog1->FileName+".bmp");
	StatusBar1->Panels->Items[0]->Text = "�������� ���������";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N6Click(TObject *Sender)
{
	ShowMessage("�����������: ");	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnPreviewMouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "��������������� �������� ����������";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnPreviewMouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WatermarkStringMouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WatermarkStringMouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "����������, ������� ����� �������� �� ��������";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RadioButton1MouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RadioButton1MouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "��������� �������� ������� �� ��������";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RadioButton2MouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RadioButton2MouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "��������� �������� ������� �� ��������";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::eOffsetMouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::eOffsetMouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "������ ������� ����� � ��������";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::cbRotateMouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::cbRotateMouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "������������/�������������� ����������� �������";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TheImageMouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TheImageMouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "�������������� ��������";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Panel1MouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Panel1MouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "��� ��������� ������ ���������� ������� F4";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnResetMouseLeave(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnResetMouseEnter(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "�������� ��� �������� ��� ���������";	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnResetClick(TObject *Sender)
{
    TheImage->Picture->LoadFromFile(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	MainForm->N2Click(Sender);
}
//---------------------------------------------------------------------------

