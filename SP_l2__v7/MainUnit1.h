//---------------------------------------------------------------------------

#ifndef MainUnit1H
#define MainUnit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *sgData;
	TLabel *Label1;
	TLabel *Label3;
	TEdit *eSize;
	TButton *btnChangeSize;
	TButton *Button1;
	TLabel *Label2;
	TEdit *cSize;
	TStaticText *StaticText1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnChangeSizeClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

