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

        char db[100];
        while(1)
        {
                std::cout << "ksql>> ";
                gets(db);
                parse(db);
                std::cout << std::endl;
        }


        return 0;
}


#endif // maindef
