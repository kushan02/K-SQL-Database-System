//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef globaldef
#define globaldef


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

/*
   void cat(char ar1[],char ar2[],char ar3[] = {'\0'},char ar4[]={'\0'},char ar5[]={'\0'}) // currently limit is max 5
   {

        strcat(ar1,ar2);
        if(ar3[0]!='\0')
        {
                strcat(ar1,ar3);
        }
        if(ar4[0]!='\0')
        {
                strcat(ar1,ar4);
        }
        if(ar5[0]!='\0')
        {
                strcat(ar1,ar5);
        }
   }
 */

void cls()
{
        system("cls");
}

#endif
