//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef parsedef
#define parsedef

using namespace std;


class PARSE
{
protected:
char sql[index1][index2];

public:
void parse()
{
        setvar();
        parselogic();
}

private:
int line, word, i;
char ch;
bool sp, bracket, brin, qoute, semicol;

void cleararray()
{
        memset(sql, 0, sizeof(sql[0][0]) * index1 * index2);

}

void setvar()
{
        line = 0;
        word = 0;
        i=0;
        sp = false;
        bracket = false;
        brin = false;
        qoute = false;
        semicol = false;
        cleararray();
}

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



void parselogic();
void display();


};

void PARSE::parselogic()
{
        while(1)
        {

                ch = getch();

                if(enter() && semicol == true)
                {
                        break;
                }
                else if(ch==';')
                {
                        //    break;
                        semicol = true;
                }
                else if(isbackspace())
                {
                        if(i>0 || strlen(sql[line-1])>0)
                        {
                                backspace();
                        }
                        else
                        {
                                continue;
                        }
                }
                else if((enter()) && sp == true && bracket==false && qoute == false)
                {
                        //  cout<<" * ";
                        cout<<endl<<"    -> ";

                        newline();
                        line--;
                        continue;
                }
                else if(enter())
                {
                        //    cout<<" ^ ";

                        if(i>0)
                        {
                                //    cout<<" % ";

                                cout<<endl<<"    -> ";

                                if(bracket == false && qoute == false)
                                {
                                        newline();
                                }

                                continue;
                        }

                }

                // TODO: BRACKET LOGIC HERE
                /* Put the bracket in single line */

                else if(ch == '(' && bracket == false && i==0)
                {
                        //    cout<<" # ";
                        bracket = true;
                        //    newline();
                        sameline();
                }
                else if(ch == '(' && bracket == false && sql[line][i-1] != ' ')
                {
                        //    cout<<" @ ";
                        bracket = true;
                        newline();
                        sameline();
                }

                else if(ch == '(' && bracket == false)
                {
                        //    cout<<" $ ";
                        bracket = true;
                        //  newline();
                        sameline();
                }

                else if(ch == '(' && bracket == true)
                {
                        //    cout<<" % ";
                        brin = true;
                        sameline();
                }
                else if(ch == ')' && brin == true)
                {
                        //    cout<<" ^ ";
                        brin = false;
                        sameline();
                }
                else if(ch == ')' && bracket == true && brin == false)
                {
                        //    cout<<" & ";
                        sameline();
                        newline();
                        bracket = false;
                }
                else if (extraspace())
                {
                        continue;
                }

                else if(space() && i<1 && bracket == false && qoute == false)
                {
                        continue;
                }
                else if(extraspace() && bracket == true)
                {
                        continue;
                }
                else if(space() && i>1 && bracket == false && sql[line][i-1] == ',')
                {
                        sameline();
                }
                else if(sql[line][i-1] == ' ' && i>1 && bracket == false && qoute == false && ch == ',')
                {
                        sameline();
                }
                else if( (ch == '=' || ch == '>' || ch == '<' )  && strlen(sql[line])<1 /*&& i>0 */ && bracket==false && qoute == false)
                {
                        //    cout<<" * ";
                        line--;
                        i = strlen(sql[line]);
                        sql[line][i++] = ' ';
                        sameline();
                }
                else if( ch == ' ' && (sql[line][i-1] == '=' || sql[line][i-1] == '<' || sql[line][i-1] == '>') && bracket==false && qoute==false)
                {
                        //    cout<<" ! ";
                        sameline();
                }

                else if(ch == '\'')
                {
                        if(qoute == false)
                        {
                                //  cout<<" @ ";
                                qoute = true;

                        }
                        else if(qoute == true) {
                                //  cout<<" # ";
                                qoute = false;
                        }
                        sameline();

                }

                else if(bracket == true || qoute == true)
                {
                        //  cout <<" % ";
                        sameline();
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
        }

        sql[line][i]='\0';
        //  display();
}

void PARSE::display()
{
        cout<<endl<<endl<<"-----------------"<<endl;
        for (size_t i = 0; i < line+1; i++) {
                for (size_t j = 0; j < strlen(sql[i]); j++) {
                        cout<<sql[i][j];
                }
                cout<<endl;
        }
}


#endif
