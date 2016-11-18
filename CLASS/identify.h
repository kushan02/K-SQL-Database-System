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

        // Create
        else if(cmp(sql[0],"create"))
        {
                if (cmp(sql[1], "table")) {
                        strcpy(mode, "createt");
                }

                else if (cmp(sql[1], "database"))  {

                        strcpy(mode, "createdb");
                }
                else
                {
                        strcpy(mode,"error");
                }
        }

        // Insert
        else if(cmp(sql[0],"insert"))
        {
                strcpy(mode, "insert");
        }

        // Update
        else if(cmp(sql[0],"update"))
        {
                strcpy(mode, "update");
        }

        // Delete
        else if(cmp(sql[0],"delete"))
        {
                strcpy(mode, "delete");
        }

        // Drop
        else if(cmp(sql[0],"drop"))
        {
                if (cmp(sql[1], "table")) {
                        strcpy(mode, "dropt");
                }
                else if (cmp(sql[1], "database"))  {
                        strcpy(mode, "dropdb");
                }
                else
                {
                        strcpy(mode,"error");
                }
        }

        // Use
        else if(cmp(sql[0],"use"))
        {
                strcpy(mode, "use");
        }

        // Show
        else if(cmp(sql[0],"show"))
        {
                strcpy(mode, "show");
        }

        // Exit
        else if(cmp(sql[0],"exit"))
        {
                strcpy(mode,"exit");
        }

        // Error
        else
        {
                strcpy(mode, "error");
        }

}
};


#endif // indentifydef
