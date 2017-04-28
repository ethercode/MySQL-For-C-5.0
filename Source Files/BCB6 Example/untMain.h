//---------------------------------------------------------------------------

#ifndef untMainH
#define untMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfrmMain:public TForm
{
__published:    // IDE-managed Components
    TGroupBox*              grpConnection;
    TLabel*                 lbl1;
    TEdit*                  edtServer;
    TLabel*                 lbl4;
    TEdit*                  edtPassword;
    TLabel*                 lbl2;
    TEdit*                  edtDatabase;
    TLabel*                 lbl3;
    TEdit*                  edtUsername;
    TButton*                btnConnect;
    TGroupBox*              grpQuery;
    TEdit*                  edtQuery;
    TButton*                btnQuery;
    TGroupBox*              grpResult;
    TStringGrid*            grdResult;
    void __fastcall         btnQueryClick(TObject* Sender);
    void __fastcall         btnConnectClick(TObject* Sender);
private:    // User declarations
public:     // User declarations
    __fastcall              TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain*frmMain;
//---------------------------------------------------------------------------
#endif
