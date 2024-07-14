//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *TheImage;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TOpenDialog *OpenDialog1;
	TFontDialog *FontDialog1;
	TMenuItem *N7;
	TSaveDialog *SaveDialog1;
	TPanel *Panel1;
	TBitBtn *btnPreview;
	TEdit *WatermarkString;
	TLabel *Label1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TLabel *Label2;
	TEdit *eOffset;
	TLabel *Label3;
	TLabel *Label4;
	TCheckBox *cbRotate;
	TLabel *Label5;
	TStatusBar *StatusBar1;
	TBitBtn *btnReset;
	void __fastcall btnPreviewClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall btnPreviewMouseEnter(TObject *Sender);
	void __fastcall btnPreviewMouseLeave(TObject *Sender);
	void __fastcall WatermarkStringMouseLeave(TObject *Sender);
	void __fastcall WatermarkStringMouseEnter(TObject *Sender);
	void __fastcall RadioButton1MouseLeave(TObject *Sender);
	void __fastcall RadioButton1MouseEnter(TObject *Sender);
	void __fastcall RadioButton2MouseLeave(TObject *Sender);
	void __fastcall RadioButton2MouseEnter(TObject *Sender);
	void __fastcall eOffsetMouseLeave(TObject *Sender);
	void __fastcall eOffsetMouseEnter(TObject *Sender);
	void __fastcall cbRotateMouseLeave(TObject *Sender);
	void __fastcall cbRotateMouseEnter(TObject *Sender);
	void __fastcall TheImageMouseLeave(TObject *Sender);
	void __fastcall TheImageMouseEnter(TObject *Sender);
	void __fastcall Panel1MouseLeave(TObject *Sender);
	void __fastcall Panel1MouseEnter(TObject *Sender);
	void __fastcall btnResetMouseLeave(TObject *Sender);
	void __fastcall btnResetMouseEnter(TObject *Sender);
	void __fastcall btnResetClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

