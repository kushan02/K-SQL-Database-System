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


void init()
{
        begin();
}

private:
void begin();
};

void KSQL::begin()
{
        while(1)
        {
                cout<<endl<<" ksql> ";
                parse();
                identify();
                handler();
                std::cout << "mode: " << mode<<'\n';
                std::cout << "logic: " << logic<<'\n';
                if(cmp(mode,"exit"))
                {
                        exit(0);
                }
        }
}



#endif
