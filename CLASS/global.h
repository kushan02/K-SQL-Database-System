//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef globaldef
#define globaldef
/*
 #include <iostream>
 #include <string.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <process.h>
 */

//class KSQL;
//class PARSE;

//#include "ksql.h"
//#include "parse.h"

class PARSE;
class KSQL;


// TODO : Add specific error with detailed cause... can be done at end

using namespace std;

const int index1 = 100,index2 = 1000;

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

#endif
