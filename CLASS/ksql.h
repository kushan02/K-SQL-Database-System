//
// Created by Kushan Mehta on 01-11-2016.
//

#ifndef ksqldef
#define ksqldef

using namespace std;


class KSQL : protected HANDLER
{

protected:


public:
KSQL()
{
        timer = 0;
}

void init()
{
        begin();
}

private:
clock_t cl;
double timer;

void begin();
};

void KSQL::begin()
{
        while(1)
        {

                cout<<endl<<"ksql> ";
                parse();

                cl = clock();

                identify();
                handler();

                cl = clock() - cl;
                timer = cl /(long double) CLOCKS_PER_SEC;

                cout<<endl<<"Query executed in ("<< timer<<" sec)"<<endl;
        }
}



#endif
