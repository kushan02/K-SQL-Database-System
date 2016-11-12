//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef indentifydef
#define indentifydef

using namespace std;

class IDENTIFY : protected PARSE
{
protected:
char mode[50];

public:
void identify()
{
        identifylogic();
}
private:
void identifylogic() {

        // SELECT COMMAND
        if(cmp(sql[0],"select"))
        {
                strcpy(mode, "select");
        }

// CREATE COMMAND
        else if(cmp(sql[0],"create"))
        {
                if (cmp(sql[1], "table")) {
                        strcpy(mode, "createt");
                } else {
                        strcpy(mode, "createdb");
                }
        }

        else if(cmp(sql[0],"insert"))
        {
                strcpy(mode, "insert");
        }
        else if(cmp(sql[0],"update"))
        {
                strcpy(mode, "update");
        }
        else if(cmp(sql[0],"delete"))
        {
                strcpy(mode, "delete");
        }
        else if(cmp(sql[0],"drop"))
        {
                if (cmp(sql[1], "table")) {
                        strcpy(mode, "dropt");
                } else {
                        strcpy(mode, "dropdb");
                }
        }
        else if(cmp(sql[0],"use"))
        {
                strcpy(mode, "use");
        }
        else if(cmp(sql[0],"show"))
        {
                strcpy(mode, "show");
        }
        else if(cmp(sql[0],"exit"))
        {
                strcpy(mode,"exit");
        }

        else
        {
                strcpy(mode, "error");
        }

}
};


#endif // indentifydef
