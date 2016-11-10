//
// Created by Kushan Mehta on 01-11-2016.
//

#ifndef ksqldef
#define ksqldef

#include <iostream>
#include <string.h>
#include <process.h>

#include "global.h"
#include "parse.h"
//#include "identify.h"
//#include "handler.h"


using namespace std;


class KSQL {

protected:
char db[255];

public:

void init()
{
        process();
}

private:

PARSE parse;

void process();

};

void KSQL::process()
{
        while(!parse.parse())
        {
                cout<<"  -> ";
                gets(db);
        }

        parse.disp();

        //      identify.identify();
        //      handler.hanlder();


}

#endif
