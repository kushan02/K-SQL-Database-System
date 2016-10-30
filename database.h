//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef databasedef
#define databasedef

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>

#include "global.h"
#include "error.h"

using namespace std;

bool addEntrydb(char []);
bool showDb();

bool addEntrydb(char ename[])
{

        fstream f;

        char path[100];
        strcpy(path,(char *) getFolderDir().c_str());

        strcat(path, "\\files\\databases\\DBRECORD.DAT" );


        f.open(path,ios::out|ios::app);

        dbEntry obj;
        strcpy(obj.dbName,ename);
        if(!f.write( (char *)&obj, sizeof(obj)))
        {
                f.close();
                return false;
        }

        f.close();
        return true;

}


bool showDb()
{
        fstream f;
        f.open("files/databases/DBRECORD.dat",ios::in);

        if(!f)
        {
                return false;
        }


        dbEntry obj;

        cout<<endl<<"+-------------------------+";
        cout<<endl;
        cout<<"| DATABASES               |";
        cout<<endl;
        cout<<"+-------------------------+"<<endl;

        while(f.read((char*)&obj, sizeof(obj)))
        {

                int len = strlen(obj.dbName);

                cout<<"|  "<<obj.dbName;
                int width = 24-len;

                cout<<setw(width)<<"|"<<endl;
        }

        cout<<"+-------------------------+";
        cout<<endl;

        f.close();

        return true;
}

bool delDb(char name[])
{
        // TODO: Add delete functionality

}





#endif // databasedef
