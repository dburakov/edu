//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel4;
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label3;
	TMemo *OutMemo;
	TPanel *Panel3;
	TLabel *Label2;
	TMemo *InMemo;
	TPanel *Panel5;
	TLabel *lIteration;
	TLabel *Label1;
	TButton *StartButton;
	TPanel *Panel6;
	TMemo *seqMemo;
	TLabel *Label4;
	TLabel *lSteps;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *lSortTime;
	void __fastcall StartButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

