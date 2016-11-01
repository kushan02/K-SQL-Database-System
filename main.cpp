#ifndef maindef // Guard header files
#define maindef


#include <iostream>
#include "global.h"
#include <stdio.h>

#include "parse.h"

using namespace std;

int main()
{

        // TODO: BEGIN CODING FOR TABLE DESIGN INSIDE DATABASE

        // TODO: Link the tables once completed with the given database

        /*  char db[255];
           while(1)
           {
                  std::cout << "ksql>> ";
                  gets(db);
                  parse(db);
                  std::cout << std::endl;
           }
         */
        cout<<"sql: ";
        char ar[255];
        gets(ar);

        while(!parse(ar))
        {
                cout<<"  -> ";
                gets(ar);


        }

        cout<<endl<<"SUCCESS"<<endl;

        sql.disp();




        return 0;
}


#endif // maindef
