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
bool dropDB(char);

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

bool dropDB(char name[])
{
        // TODO: Delete the folder also


        fstream f,o;
        f.open("files/databases/DBRECORD.dat",ios::in);
        o.open("files/databases/temp.dat",ios::out);

        if(!f)
        {
                return false;
        }


        dbEntry obj;

        bool found=false;

        while(f.read((char*)&obj, sizeof(obj)))
        {

                if(cmp(obj.dbName,name))
                {
                        found = true;
                        continue;
                }

                o.write( (char *)&obj, sizeof(obj));

        }
        f.close();
        o.close();

        remove("files/databases/DBRECORD.dat");
        rename("files/databases/temp.dat","files/databases/DBRECORD.dat");


        if(found==true)
        {
                return true;
        }
        else
        {
                return false;
        }

}





#endif // databasedef
