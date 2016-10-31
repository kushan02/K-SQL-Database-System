
  #include <iostream>
  #include <string.h>
  #include <process.h>
  #include <stdio.h>

  #include "error.h"

using namespace std;
bool parse(char[]);

class SQL
{
char original[255];
//public:
//char com[100][9000000];
char com[100][1000];
//private:
char mode[50];

int len;
int i,j;
bool sp,sp1;
int word,line;
//bool initchk;
bool bracket;
bool brin;
int bfcount,bbcount;

public:

SQL()
{
        i = 0, j = 0;

        sp = false, sp1 = false;

        word = 0, line = 0;

        //      initchk = false;

        bracket = false; brin = false;
        bfcount=0; bbcount=0;
}

void parse(char [],bool);
void disp();

void newline()
{
        sp = true;

        com[line][word] = '\0';
        line++;
        word = 0;
}



} sql;

void SQL::parse(char db[],bool enter = false)
{


        // MAIN PARSING LOGIC;
        len = strlen(db);

        if(enter == true)
        {
                sp = false;
        }

        for (i = 0; i < len; i++) {

                if (db[i] == ' ' && bracket == false) {
                        // If there is a wordace in the main command, then it means it is the end of a word which was required to be parsed
                        // we put a null char at the end of current row of sql array to make it a string
                        // we increment the row number
                        // we reset the char position counter - 'j' back to zero so initialization takes place from the first pocket of array

                        if(sp==true)
                        {
                                continue;
                        }
                        else
                        {
                                newline();

                        }

                } else {

                        if(db[i] == '(' && bfcount<1)
                        {
                                if(db[i]!=' ')
                                {
                                        newline();
                                        com[line][word++] = db[i];

                                        sp = false;
                                }
                                bracket = true;

                                bfcount++;
                        }
                        else if(db[i] == '(' && bfcount>=1)
                        {
                                brin = true;
                                bfcount++;
                                com[line][word++] = db[i];
                                sp = false;
                        }
                        else if(db[i] == ')' && brin==false)
                        {
                                bracket = false;

                                com[line][word++] = db[i];
                                sp = false;
                                newline();
                                bbcount++;
                        }
                        else if(db[i] == '(' && brin == true)
                        {
                                brin = false;
                                com[line][word++] = db[i];
                                sp = false;
                        }

                        else
                        {
                                com[line][word++] = db[i];
                                sp = false;
                        }
                }

        }

        com[line][word] = '\0';

        com[line+1][0] = '\0';         // Check for seeing the name of database is single word

}

void SQL::disp()
{
        cout<<endl;
        for (int i = 0; i < line + 1; ++i) {

                for (int j = 0; j < strlen(com[i]); ++j) {

                        cout << com[i][j];
                }
                cout << endl;
        }

        cout<<endl;
}

bool chk(char ar[])
{
        bool ret;
        static char emp[] = " ";
        if(ar[strlen(ar)-1]==';')
        {
                ret = true;
                sql.parse(ar,true);
        }
        else {
                ret = false;
                sql.parse(emp);
                sql.parse(ar);
        }


        return ret;
}

int main()
{

        cout<<"sql: ";
        char ar[255];
        gets(ar);

        while(!chk(ar))
        {
                cout<<"  -> ";
                gets(ar);


        }

        cout<<endl<<"SUCCESS"<<endl;

        sql.disp();

        //  cout<<endl<<"SIZE IS: "<<sizeof(sql.com)<<" MB";

        return 0;
}

/*

   bool parselogic(char db[])
   {

        char com[50][50];   // Double dimesnional array to store the parsed command
        char mode[50];   // to identify the mode of sql command to execute

        // MAIN PARSING LOGIC;
        int len = strlen(db);

        int i = 0, j = 0;

        bool sp=false,sp1=false;

        int word = 0, line = 0;

        if(db[len-1] == ';')
        {
                return false;
        }


        for (i = 0; i < len; i++) {

                if (db[i] == ' ') {
                        // If there is a wordace in the main command, then it means it is the end of a word which was required to be parsed
                        // we put a null char at the end of current row of sql array to make it a string
                        // we increment the row number
                        // we reset the char position counter - 'j' back to zero so initialization takes place from the first pocket of array

                        if(sp==true)
                        {
                                continue;
                        }
                        else
                        {

                                sp = true;

                                com[line][word] = '\0';
                                line++;
                                word = 0;
                        }

                } else {
                        com[line][word++] = db[i];
                        sp = false;
                }

        }

        com[line][word] = '\0';

        com[line+1][0] = '\0';   // Check for seeing the name of database is single word

        //  cout << endl;

        //    Check to see if the parsing was working or not

   /*
        for (int i = 0; i < line + 1; ++i) {

                for (int j = 0; j < strlen(com[i]); ++j) {

                        cout << com[i][j];
                }
                cout << endl;
        }

        cout<<endl;
 */
/*    return true;

   }
 */
