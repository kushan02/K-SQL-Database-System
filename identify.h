//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef indentifydef
#define indentifydef

#include <string.h>

using namespace std;

/*
    MODES - () & mode (e) = ERROR

   SELECT (s) - The SELECT statement is used to select data from a database.

   UPDATE(u) - The UPDATE statement is used to update existing records in a
   table.

   DELETE(d) - The DELETE statement is used to delete rows in a table.

   INSERT INTO(i) - The INSERT INTO statement is used to insert new records in a
   table.

   CREATE: (TABLE(t) & DATBASE(b))
   - The CREATE DATABASE statement is used to create a database.
   - The CREATE TABLE statement is used to create a table in a database.

 */

void identify(char sql[][50], char *param) {
        char mode[20];

        // SELECT COMMAND
        if(cmp(sql[0],"select"))
        {
                strcpy(mode, "select");
        }

// CREATE COMMAND
        else if(cmp(sql[0],"create"))
        {
                if (cmp(sql[1], "table")) {
                        strcpy(mode, "createt");
                } else {
                        strcpy(mode, "createdb");
                }
        }

        else if(cmp(sql[0],"insert"))
        {
                strcpy(mode, "insert");
        }
        else if(cmp(sql[0],"update"))
        {
                strcpy(mode, "update");
        }
        else if(cmp(sql[0],"delete"))
        {
                strcpy(mode, "delete");
        }
        else if(cmp(sql[0],"drop"))
        {
                if (cmp(sql[1], "table")) {
                        strcpy(mode, "dropt");
                } else {
                        strcpy(mode, "dropdb");
                }
        }
        else if(cmp(sql[0],"use"))
        {
                strcpy(mode, "use");
        }
        else if(cmp(sql[0],"show"))
        {
                strcpy(mode, "show");
        }
        else if(cmp(sql[0],"exit"))
        {
                strcpy(mode,"exit");
        }

        else
        {
                strcpy(mode, "error");
        }

        strcpy(param,mode);
}

#endif // indentifydef
