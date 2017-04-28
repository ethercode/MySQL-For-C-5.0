//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untMain.h"
#include "../CMySQL.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain*   frmMain;
CMySQL      Instance;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner):
    TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnQueryClick(TObject* Sender)
{
    if (Instance.IsConnected())
    {
        CMySQLResult*   Result  = Instance.Query(edtQuery->Text);
        if (Result == NULL)
        {
            Application->MessageBox("Query failed!", "Error", MB_OK | MB_ICONERROR);
        }
        else
        {
            edtQuery->Text = "";
            if (Result->GetResult_Exists())
            {
                int Fields  = Result->GetResult_Fields();
                int Rows    = Result->GetResult_Rows();
                grdResult->ColCount = Fields;
                grdResult->RowCount = Rows + 1;
                for (int j = 0; j < Fields; ++j)
                {
                    grdResult->Cells[j][0] = Result->GetResult_FieldName(j);
                    for (int k = 0; k < Rows; ++k)
                    {
                        grdResult->Cells[j][k + 1] = Result->GetResult_Text(k, j);
                    }
                }
                Instance.FreeResult(Result);
            }
            else
            {
                grdResult->ColCount = 1;
                grdResult->RowCount = 1;
                grdResult->Cells[0][0] = "No result set";
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnConnectClick(TObject* Sender)
{
    bool    Connected   = Instance.IsConnected();
    if (!Connected)
    {
        bool    Success = Instance.Connect(edtServer->Text, edtUsername->Text, edtPassword->Text, edtDatabase->Text);
        if (Success)
        {
            btnConnect->Caption = "Disconnect";
        }
    }
    else
    {
        Instance.Disconnect();
        btnConnect->Caption = "Connect";
    }
    Connected = Instance.IsConnected();
    edtQuery->Enabled = Connected;
    btnQuery->Enabled = Connected;
    edtUsername->Enabled = !Connected;
    edtPassword->Enabled = !Connected;
    edtDatabase->Enabled = !Connected;
    edtServer->Enabled = !Connected;
}
//---------------------------------------------------------------------------
