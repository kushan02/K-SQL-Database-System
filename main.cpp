#ifndef maindef // Guard header files
#define maindef


#include <iostream>
#include "database.h"
#include "global.h"
#include <stdio.h>

#include "parse.h"

using namespace std;

int main()
{

        // TODO: BEGIN CODING FOR TABLE DESIGN INSIDE DATABASE

        // TODO: Link the tables once completed with the given database

        /* TODO : Create a options menu based off the database schema
         * Create Database
         * View Databases
         * Delete Database
         */
/*
        cout<<"Enter mode of database operation: ";
        char c; cin>>c;

        cout<<"Enter KSQL Command: ";

        char db[100];

        cin.ignore(); //^^this is necessary


        gets(db);

        if(database(db,c))
        {
                cout<<endl<<endl<<"Query Executed Successfully!"<<endl;
        }

*/

    char db[100];
    while(1)
    {
    std::cout << "ksql>> ";
    gets(db);
    parse(db);
    
  }


        return 0;
}


#endif // maindef
