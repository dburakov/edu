//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <XPMan.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *btnStart;
	TMemo *InputMemo;
	TMemo *SMemo;
	TLabel *Label1;
	TMemo *HMemo;
	TLabel *Label2;
	TMemo *CMemo;
	TLabel *Label3;
	TLabel *Label4;
	TMemo *TiMemo;
	TLabel *Label5;
	TButton *btnExit;
	TXPManifest *XPManifest1;
	TLabel *NInSource;
	TStringGrid *sgX;
	void __fastcall btnStartClick(TObject *Sender);
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall InputMemoChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
