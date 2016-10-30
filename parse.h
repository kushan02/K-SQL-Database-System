//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef parsedef
#define parsedef

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <process.h>

#include "global.h"
#include "error.h"
#include "database.h"
#include "identify.h"

using namespace std;

bool parse(char []);


bool parse(char db[]) {

        char com[20][50]; // Double dimesnional array to store the parsed command
        char mode[50]; // to identify the mode of sql command to execute

        // MAIN PARSING LOGIC;
        int len = strlen(db);

        int i = 0, j = 0;

        int sp = 0, key = 0;

        for (i = 0; i < len; i++) {

                if (db[i] == ' ') {
                        // If there is a space in the main command, then it means it is the end of a word which was required to be parsed
                        // we put a null char at the end of current row of sql array to make it a string
                        // we increment the row number
                        // we reset the char position counter - 'j' back to zero so initialization takes place from the first pocket of array

                        com[key][sp] = '\0';
                        key++;
                        sp = 0;

                } else {
                        com[key][sp++] = db[i];
                }

        }

        com[key][sp] = '\0';

        com[key+1][0] = '\0'; // Check for seeing the name of database is single word

      //  cout << endl;

        /*  Check to see if the parsing was working or not

           for (int i = 0; i < key + 1; ++i) {

                    for (int j = 0; j < strlen(com[i]); ++j) {

                            cout << com[i][j];
                    }
                    cout << endl;
            }

            cout<<endl;
         */


// CALL THE FUNCTION TO IDENTIFY THE MODE OF SQL COMMAND

        identify(com,mode);

        /*
           LIST OF MODES:

         * Select = select
         * Create:
           Table = createt
           Database = createdb
         * Insert = insert
         * Update = update
         * Delete = delete
         * Drop:
           Table = dropt
           Database = dropdb
         * Show = show
         * Use = use
         * Error = error
         * Exit = exit

         */


        // CREATE DATABASE MODE
        if(cmp(mode,"createdb"))
        {

                if (isCreateDB(com)) {
                        if(createFolder(com[2])) {

                                if(addEntrydb(com[2])) {
                                        cout << endl << "Database "<<com[2]<<" created Successfully! "<<endl<<endl;

                                        return true;
                                }
                        } else{
                                return false;
                        }
                } else {
                        return false;
                }
        }

        else if (cmp(mode,"show"))
        {
                if (isShowDB(com)) {

                        if(showDb())
                        {
                                return true;
                        }

                }
                else {
                        return false;
                }
        }

        else if(cmp(mode,"exit"))
        {
            exit(0);
        }


        else
        {
          std::cout << "FATAL ERROR" << std::endl;
        }

}






#endif // parsedef
