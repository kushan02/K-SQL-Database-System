//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef error
#define error

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <process.h>

// TODO : Add specific error with detailed cause... can be done at end

using namespace std;

bool cmp(const string& a, const string& b)
{
        unsigned int sz = a.size();
        if (b.size() != sz)
                return false;
        for (unsigned int i = 0; i < sz; ++i)
                if (tolower(a[i]) != tolower(b[i]))
                        return false;
        return true;
}


/* Display Messages for different errors BEGINS
 * semerr - Semicolon not present
 * selerr - Select not preset
 */
void semerr()
{
        cout<<"ERROR: Statement not terminated with a semi colon ;"<<endl;
}
void selerr()
{
        cout<<"ERROR: SELECT Syntax not found in the beginning of the command"<<endl;
}

// Display Messaages END

int hasSelect(char str[]);

int hasSemicol(char str[]) {
//int semicol() {

        int flag = 0,i=0;
        int len = strlen(str);

        // cout<<"Original length = "<<len;

        for (i = len; i >= 0; i--) {

                if (str[i] == ' ')  {

                        str[i]='\0';

                }
                else if (str[i]==';')
                {
                        flag=1;
                        str[i]='\0';
                        break;
                }
                else if (isalnum(str[i]))
                {
                        break;
                }

        }
        /*  cout<<endl;
           cout<<"counter is : "<<len-i<<endl;
           cout<<"Final length = "<<strlen(str);

           cout<<endl<<str<<endl<<endl;
         */
        return flag;


}

int hasSelect(char str[])
{
        int len = strlen(str);
        char temp[10]; int j=0,flag=0;
        for (int i = 0; i <len; ++i) {

                if (str[i]==' ')
                {
                        continue;
                }
                else
                {
                        for ( j = 0; j <6; ++j) {
                                temp[j]=str[i+j];

                        }

                        break;

                }

        }

        temp[j]= '\0';

        //  cout<<"THE SELECT COMMAND IS: "<<temp<<endl;


        if (cmp(temp,"select"))
        {
                flag=1;
        }

        return flag;

}

bool isCreateDB(char db[][50]) {

        bool create = true, data = true, dname = true, dsingle = true;

        if (!cmp(db[0], "create")) {
                create = false;
        }
        if(!cmp(db[1], "database"))
        {
                data = false;
        }
        if(db[2][0]=='\0' || db[2][0]==' ')
        {
                dname = false;
        }
        if(db[3][0] != '\0')
        {
                dsingle = false;
        }

/*  if (cmp(db[0], "create") && cmp(db[1], "database") && db[2] != NULL && db[3][0] == '\0') */

        if(create == true & data == true && dname == true && dsingle == true)
        {
                return true;
        }

        else {

// cout << endl << "Sytax error: Please ensure correct syntax is used for creating database " << endl;



                if(dname == false)
                {
                        cout<<"ERROR: Please specify a allowed name for database";
                }
                else if(dsingle == false)
                {
                        cout<<"ERROR: The database name can contain a single word only";
                }
                //if(cr == false || dat == false)
                else
                {
                        cout<<"ERROR: The correct syntax should be \" Select Database <DBName> \" ";
                }

                cout<<endl;

                return false;

        }
}

bool isShowDB(char db[][50]) {

        bool show = true, data = true, extra = true;
        if (!cmp(db[0], "show")) {
                show = false;
        }
        if(!cmp(db[1], "databases"))
        {
                data = false;
        }
        if(db[2][0] != '\0')
        {
                extra = false;
        }

        if(show = true && data == true && extra == true)
        {
                return true;
        }

        else {


                if(extra == false)
                {
                        cout<<"ERROR: Unecessary syntax present. The correct syntax should be \" Show Database \" ";
                }
                else
                {
                        cout<<"ERROR: The correct syntax should be \" Show Database \" ";
                }

                cout<<endl;

                return false;

        }
}

#endif // error
