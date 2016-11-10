//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef parsedef
#define parsedef

#include <iostream>
#include <string.h>
#include <process.h>

#include "ksql.h"
#include "global.h"
//#include "identify.h"
//#include "handler.h"

//class KSQL;

using namespace std;


class PARSE : protected KSQL
{
protected:
char com[index1][index2];      // Double Dimensional Array to store the parsed sql command
char mode[50];      // to identify the mode of sql command to execute

private:
int len;
int i,j;
bool sp;         // Check for consecutive spacing
int word,line;         // Indices for double dimensional array
bool bracket;         // Check to see if there is a bracket
bool brin;         // Internal bracket check
int bfcount;         // Count the no. of brackets opened
bool semicolon;         // Bool to keep an eye of termination of statement



public:

PARSE()
{
        i = 0, j = 0;
        sp = false;
        word = 0, line = 0;
        bracket = false; brin = false;
        bfcount=0;
        semicolon = false;
        //    db[0] = '\0';
}

void disp();   // Display the parsed command

bool parse()
{
        bool ret;
        static char emp[] = " ";

        if(db[strlen(db)-1]==';')
        {
                ret = true;
                semicolon = true;
                //  parselogic(db);
                parselogic();
        }
        else {
                ret = false;
                //parselogic(emp);
                //parselogic(db);
                parselogic();
        }
        return ret;
}

private:

void parselogic();   // Main Parsing Logic


void newline() // Function to switch to new line in double dimensional array
{
        // If there is a space in the main command, then it means it is the end of a word which was required to be parsed
        // we put a null char at the end of current row of sql array to make it a string
        // we increment the row number
        // we reset the char position counter - 'j' back to zero so initialization takes place from the first pocket of array

        sp = true; // Flag to indicate there has been a recent space
        com[line][word] = '\0';
        line++;
        word = 0;
}

void sameline()
{
        // Insert the character in same line as that of the current one. Dont change the line of array
        com[line][word++] = db[i];
        sp =  false;
}


};

void PARSE::parselogic()
{
        len = strlen(db); // Calculate the length of the command entered


        for (i = 0; i < len; i++) {

                if (db[i] == ' ' && bracket == false) {  // CONDITION ONLY IF THE ENTERED CHAR IS SPACE

                        // If there is a space and there are no brackets opened for Parameters

                        if(sp==true) // If there is a consecutive space, continue.
                        {
                                continue;
                        }
                        else
                        {
                                newline(); // Else we parse each word in a new array row (double dimensional)

                        }

                } else {   // If the current character is not a space and just a regular letter of special character

                        if(db[i] == '(' && bfcount<1)
                        {
                                //  cout<<endl<<"bracket counter is: "<<i<<endl;
                                // We check if the char entered is a bracket and it is the main bracket for Parameters

                                if(db[0]!='(') // We check if the bracket is not the first char of new line
                                {
                                        if(db[i-1]!=' ') // if there is no space between tbname and parameter, insert all the parameter in one line
                                        {
                                                newline();

                                        }
                                }

                                sameline();

                                bracket = true; // Bool for main bracket beginning

                                bfcount++; // Add a counter so that only the first time the main bracket is initialized
                        }
                        else if(db[i] == '(' && bfcount>=1) // If the main bracket is already initialized
                        {
                                brin = true; // Bool for beginning of internal bracket (inside the parameters)
                                bfcount++;
                                sameline();
                        }
                        else if(db[i] == ')' && brin==false)
                        {
                                bracket = false;

                                sameline();
                                newline();

                        }
                        else if(db[i] == '(' && brin == true)
                        {
                                brin = false;
                                sameline();
                        }

                        else
                        {
                                sameline();
                        }

                }

        }

        com[line][word] = '\0';     // Complete the last word of the array

        com[line+1][0] = '\0';         // Check for seeing the name of database is single word

        if(semicolon == true)
        {
                com[line][word-1] = '\0';     // Remove semicolon

        }

}

void PARSE::disp() // public function to check the parsed command
{
        cout<<endl;
        for (int i = 0; i < line + 1; ++i) {

                for (int j = 0; j < strlen(com[i]); ++j) {

                        cout << com[i][j];
                }
                cout << endl;
        }

        cout<<endl;
}

#endif
