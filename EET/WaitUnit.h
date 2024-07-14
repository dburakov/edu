//---------------------------------------------------------------------------

#ifndef WaitUnitH
#define WaitUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TWaitForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TProgressBar *ProgressBar1;
private:	// User declarations
public:		// User declarations
	__fastcall TWaitForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWaitForm *WaitForm;
//---------------------------------------------------------------------------
#endif
