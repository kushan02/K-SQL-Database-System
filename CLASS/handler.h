//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef handlerdefmy
#define handlerdefmy

class HANDLER : protected IDENTIFY
{
// to identify the mode of sql command to execute
protected:
char logic[20];

public:
void handler()
{
        handlerlogic();
}
private:
void handlerlogic()
{
/*
        // CREATE DATABASE MODE
        if(cmp(mode,"createdb"))
        {
                createDb(com);
        }

        else if (cmp(mode,"createt"))
        {
                createT(com);
        }

        else if (cmp(mode,"show"))
        {
                showDb(com);
        }

        else if (cmp(mode,"dropdb"))
        {
                dropDb(com);
        }

        else if(cmp(mode,"exit"))
        {
                exit(0);
        }

        else
        {
                cout<<endl<<"FATAL ERROR";
        }
 */

        if(cmp(mode,"createdb") || cmp(mode,"dropdb") || cmp(mode,"show"))
        {
                strcpy(logic,"database");
        }
        else if(cmp(mode,"createt") /* || cmp(mode,"dropdb") || cmp(mode,"show") */)
        {
                strcpy(logic,"table");
        }
        else if(cmp(mode,"exit"))
        {
                //    exit(0);
        }
        else
        {
                strcpy(logic,"error");
                cout<<endl<<"FATAL ERROR"<<endl;
        }

}


};

#endif
