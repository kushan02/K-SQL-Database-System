//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef handlerdef
#define handlerdef

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <process.h>

#include "global.h"
#include "error.h"
#include "database.h"
#include "identify.h"


// CREATE DATABASE MODE
void createDb(char com[][50])
{

        if (isCreateDB(com)) {
                if(createFolder(com[2])) {

                        if(addEntrydb(com[2])) {
                                cout << endl << "Database "<<com[2]<<" created Successfully! "<<endl;


                        }
                } else{

                        cout << endl << "Database "<<com[2]<<" already exists! "<<endl;

                }
        } else {
                cout << endl << "Please use a valid database name "<<endl;

        }
}

void showDb(char com[][50])
{

        if (isShowDB(com)) {

                showDb();
        }



        /*  if (isShowDB(com)) {

                  if(showDb())
                  {
                          return true;
                  }

           }
           else {
                  return false;
           }
         */
}

void dropDb(char com[][50])
{
        if (isDropDB(com)) {

                if(dropDB(com[2]))
                {
                        std::cout << endl<< "Database " << com[2] <<" deleted Successfully!" <<std::endl;
                }
                else
                {
                        std::cout << endl << "Database " << com[2] << " doesnot exist. Please select a existing database."<< std::endl;
                }

        }
        else {
        }
}





#endif // handlerdef
