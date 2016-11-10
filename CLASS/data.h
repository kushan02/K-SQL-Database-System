#ifndef datadef
#define datadef

class SQL;
class PARSE;

class DATA
{
friend class SQL;
friend class PARSE;

char db[255];
char com[index1][index2]; // Double Dimensional Array to store the parsed sql command
char mode[50]; // to identify the mode of sql command to execute

int len;
int i,j;
bool sp; // Check for consecutive spacing
int word,line; // Indices for double dimensional array
bool bracket; // Check to see if there is a bracket
bool brin; // Internal bracket check
int bfcount; // Count the no. of brackets opened
bool semicolon; // Bool to keep an eye of termination of statement


public:

DATA() // Constructor to assign default values
{
        i = 0, j = 0;
        sp = false;
        word = 0, line = 0;
        bracket = false; brin = false;
        bfcount=0;
        semicolon = false;
        db[0] = '\0';
}


} data;

#endif
