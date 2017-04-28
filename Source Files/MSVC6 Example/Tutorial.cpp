/*
        File: Tutorial.cpp
     Purpose: Demonstration of CMySQL
  Programmer: Tamburlaine Murray
       Email: tmurray@antivoid.za.net
        Date: 2004-Aug-24
*/

#include <conio.h> 

#include "../CMySQL.h" 

int main(int argc, char* argv[])
{
    CMySQL  Instance;  //CMySQL instance

    Instance.Connect("localhost", "root", "", "mysql");    //attempt to connect
    if (Instance.IsConnected())  //see if the connection was successful
    {
        printf("Connect successful.\r\n");

        std::string QueryList[5];
        QueryList[0] = "show databases";  //returns the list of databases
        QueryList[1] = "Invalid query.";  //an invalid query, to cause an error
        QueryList[2] = "select * from user";  //a normal query
        QueryList[3] = "show tables";  //show all the tables in the mysql database
        QueryList[4] = "use mysql";    //query with no result set.

        for (int QueryNum = 0; QueryNum < 5; ++QueryNum)  //go through all the queries
        {
            std::string Query   = QueryList[QueryNum];  //get query
            printf("About to perform query \"%s\"... press a key when ready ...\r\n\n", Query.c_str());
            getch();  //wait for keypress
            printf("Performing query: \"%s\"\r\n", Query.c_str());
            CMySQLResult*   Result  = Instance.Query(Query);  //perform query
            if (Result == NULL)   //test if the query had an error
            {
                //do some error handling, because we know query failed
                printf("Query failed.\r\n");
            }
            else  //success
            {
                //query succeeded.
                printf("Query succeeded\r\n");
                if (Result->GetResult_Exists())   //see if there was a result set
                {
                    printf("There is a result set.\r\n");
                    //we know there was is result set
                    int Fields  = Result->GetResult_Fields();  //get amount of rows
                    int Rows    = Result->GetResult_Rows();  //get amount of fields
                    printf("%d rows and %d fields in result set.\r\n", Rows, Fields);
                    int CurRow;
                    int CurField;
                    for (CurRow = 0; CurRow < Rows; ++CurRow)  //go through rows
                    {
                        for (CurField = 0; CurField < Fields; ++CurField)  //go through fields
                        {
                            //get field name
                            std::string FieldName   = Result->GetResult_FieldName(CurField);
                            //get data item text
                            std::string Text        = Result->GetResult_Text(CurRow, CurField);
                            printf("Row #%d Field #%d (%s): %s\r\n", CurRow + 1, CurField + 1, FieldName.c_str(), Text.c_str());
                        }
                        printf("\r\n");
                    }
                    Instance.FreeResult(Result); //free result
                }
                else
                {
                    //there was no result
                    printf("No result set.\n\r");
                }
            }
            printf("\r\n");
        }
    }
    else
    {
        printf("Failed to connect.\r\n");
    }
    printf("\r\nPress any key to exit.");
    getch();  //wait for keypress
    return 0;
}