  #include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <conio.h>
using namespace std;


char ar[50000];
char sql[50][1000];

int line = 0, word = 0;

int letter = 0;

char ch;

int i=0;

bool sp = false;

void newline()
{
        sql[line][i] = '\0';
        line++;
        i=0;

}
void sameline()
{
        sql[line][i++]=ch;
}

bool extraspace()
{
        if(ch==' ' && sql[line][i-1]==' ')
        {
                return true;
                sp = true;
        }
        else
        {
                sp = true;
                return false;

        }

}
bool space()
{
        if(ch==' ')
        {
                sp = true;
                return true;
        }
        else {
                sp = false;
                return false;

        }
}
bool isbackspace()
{
        if((ch=='\b' || ch == 8 || ch==127))
        {
                return true;
        }
        else
        {
                return false;
        }
}
bool backspace()
{
        putchar('\b');
        putchar(' ');
        //    putchar('\b');
        if(i>0)
        {
                i--;
        }
        else
        {
                line--;
                i = strlen(sql[line]);
        }

}
bool enter()
{
        if(ch == '\r' || ch =='\n')
        {
                return true;
        }
        else
        {
                return false;
        }
}




int main()
{

        cout<<" ksql> ";
        while(1)
        {

                ch = getch();


                if(ch==';')
                {
                        break;
                }
                else if(isbackspace())
                {
                        if(i>0 || sp == false)
                        {
                                backspace();
                        }
                        else
                        {
                                continue;
                        }
                }
                else if((enter()) && sp == true)
                {
                        cout<<endl<<"    -> ";
                        newline();
                        line--;
                        continue;
                }
                else if(enter())
                {
                        if(i>0)
                        {
                                cout<<endl<<"    -> ";

                                newline();

                                continue;
                        }

                }

                // TODO: BRACKET LOGIC HERE
                /* Put the bracket in single line */


                else if (extraspace())
                {
                        continue;
                }
                else if(space())
                {
                        newline();
                        i--;
                        sameline();
                }
                else
                {
                        sameline();
                }



                putchar(ch);

                /*    else if(extraspace())
                    {
                            continue;
                    }
                    else if(enter())
                    {

                            cout<<endl<<"  -> ";

                            newline();

                            continue;

                    }

                    else if(isbackspace())
                    {
                            if(strlen(sql[line])!=0)
                                    backspace();
                    }

                    else if(space())
                    {
                            newline();
                            sameline();
                    }
                    else
                    {

                            sameline();
                            letter++;
                    }


                    putchar(ch);


                 */
        }

        sql[line][i]='\0';

//    cout<<*p;
//  cout<<endl<<ar;
        cout<<endl<<endl<<"-----------------"<<endl;
        for (size_t i = 0; i < line+1; i++) {
                for (size_t j = 0; j < strlen(sql[i]); j++) {
                        cout<<sql[i][j];
                        /* code */
                }
                cout<<endl;
                /* code */
        }
        return 0;
}
