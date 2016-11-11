//
// Created by Kushan Mehta on 01-11-2016.
//

#ifndef ksqldef
#define ksqldef

using namespace std;


class KSQL : protected IDENTIFY
{

protected:


public:

KSQL()
{
        initvarparse();
}

void init()
{
        begin();
}

private:
void begin()
{
        process();
        identify();
        std::cout << "mode: " << mode<<'\n';
}

};


#endif
