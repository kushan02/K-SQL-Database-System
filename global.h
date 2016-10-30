//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef global
#define global

#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;


string getFolderDir() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

string getfilepath()
{
    char result[ MAX_PATH ];
    return string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
}


bool createFolder(const char * fname)
{

    //GET THE PATH OF EXE
    char path[100];
    strcpy(path,(char *) getFolderDir().c_str());

    strcat(path, "\\files\\databases\\" );

    strcat(path, fname);

    // cout<<path<<endl;


    if(!CreateDirectory(path ,NULL))
    {
        return false;
    }
    else {
        return true;
    }
}


struct dbEntry
{
    char dbName[50];
};



#endif // global
