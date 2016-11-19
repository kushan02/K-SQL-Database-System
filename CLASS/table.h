//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef tabledef
#define tabledef

using namespace std;

class TABLE : protected DATABASE, protected CREATE
{

char tb[index1][index2];
char stu[index1][index2];

int line, word;

char db_path[500];

struct TDATA
{
        char structure[400];
} data;

struct ENTRY
{
        char tbname[50];
        char dbname[50];
} entry;

public:
TABLE()
{
        strcpy(db_path,"files/DBKTM.ksh");
}

protected:


void parse_tb();
void disp();
void tblogic();
void disptb();
bool noExists();
bool showT();

bool table()
{
        if(noExists())
        {
                parse_tb();
                return true;
        }

        else
        {
                return false;
        }
}

bool tUse();

};

bool TABLE::tUse()
{
        if(db_name[0]!='\0')
        {
                return true;
        }
        else return false;
}

bool TABLE::noExists()
{
        fstream f;
        f.open("files/DBKTM.ksh",ios::in);
        while(f.read((char *)&entry,sizeof(entry)))
        {
                if (cmp(entry.dbname,db_name) && cmp(entry.tbname,sql[2])) {
                        return false;

                }
        }
        f.close();
        return true;


}

void TABLE::parse_tb()
{
        int i = 1,j=0;
        //  int line = 0, word = 0;
        line = 0, word = 0;
        bool br = false;
        for(i=1; i<strlen(sql[3])-1; i++)
        {

                if(sql[3][i] == ' ' && j == 0)
                {
                        continue;
                }


                else if(sql[3][i]== ' ' && sql[3][i-1]== ' ')
                {
                        tb[line][j++] = sql[3][i];
                        continue;
                }
                else if(sql[3][i]!= ' ' && sql[3][i-1]== ')' )
                {
                        //  tb[line][j++] = sql[3][i];
                        if(sql[3][i]==',' && br== false)
                        {
                                tb[line][j] = '\0';
                                line++;
                                j = 0;
                                continue;

                        }
                        else
                        {
                                tb[line][j++] = ' ';
                        }
                        //    continue;
                }

                else if(sql[3][i] == '(' && sql[3][i-1]!=' ' && br == false)
                {



                        tb[line][j++] = ' ';

                        br = true;
                        //  continue;
                }
                else if(sql[3][i] == '(' && br == false)
                {
                        br = true;
                        //    continue;
                }
                else if(sql[3][i] == ')' &&  br == true && i<strlen(sql[3])-1)
                {
                        br = false;
                        //    continue;

                        //    tb[line][j++] = sql[3][i];
                }
                else if (br == true)
                {
                        if(sql[3][i]==' ')
                        {
                                continue;
                        }
                }
                else if(sql[3][i]==',' && br== false)
                {
                        tb[line][j] = '\0';
                        line++;
                        j = 0;
                        continue;

                }
                else if(i == strlen(sql[3])-1)
                {
                        tb[line][j] = '\0';
                        line++;
                        j = 0;
                        continue;
                }

                tb[line][j++] = sql[3][i];

        }

        //      disp();
        tblogic();
        //    cout<<"********************";
        //    disptb();


}

void TABLE::tblogic()
{
        fstream f;
        memset(stu, 0, sizeof(stu[0][0]) * index1 * index2);
        strcpy(data.structure,"struct ");
        strcat(data.structure,db_name);
        strcat(data.structure,".");
        strcat(data.structure,sql[2]);
        strcat(data.structure,"{");

        static int l1 =0, w1=0;
        bool brk = false;

        for (int i = 0; i < line+1; i++) {

                l1 = 0;
                w1 = 0;

                for(int j=0; j<strlen(tb[i]); j++)
                {
                        if(tb[i][j] == ' ' &&  brk ==  false)
                        {
                                stu[l1][w1] = '\0';
                                l1++;
                                w1=0;
                                continue;
                        }
                        else if(tb[i][j] == '(')
                        {
                                brk = true;
                                continue;
                        }
                        else if(tb[i][j] == ')')
                        {
                                brk = false;
                                continue;
                        }

                        stu[l1][w1++] = tb[i][j];

                }

                stu[l1][w1] = '\0';

                if (cmp(stu[1],"varchar")) {

                        strcpy(stu[1],"char");
                        strcat(stu[0],"[");
                        strcat(stu[0],stu[2]);
                        strcat(stu[0],"]");

                }
                else if (cmp(stu[1],"char")) {

                        strcpy(stu[1],"char");

                }
                else if(cmp(stu[1],"int"))
                {
                        if(stu[2][0]=='(')
                        {
                                strcpy(stu[1],"double");
                        }
                        else
                        {
                                strcpy(stu[1],"int");

                        }
                }
                else if(cmp(stu[1],"number"))
                {

                        strcpy(stu[1],"int");

                }
                else if(cmp(stu[1],"decimal"))
                {

                        strcpy(stu[1],"float");

                }
                else if(cmp(stu[1],"key") && cmp(stu[0],"primary"))
                {

                        strcpy(stu[1],"/* PRIMARY KEY");
                        strcpy(stu[0],stu[2]);
                        strcat(stu[0],"*/");
                }


                strcat(data.structure,stu[1]);


                strcat(data.structure," ");
                strcat(data.structure,stu[0]);
                strcat(data.structure,";");
        }

        strcat(data.structure, "};");
        //  strcat(data.structure,sql[2]);
        //  strcat(data.structure,"1;");

        f.open("files/TABLE_STRUCT.h",ios::out|ios::app);
        f.write((char *)&data,sizeof(data));
        f.close();

        char fp[50];
        strcpy(fp,"files/");
        strcat(fp,sql[2]);
        strcat(fp,".");
        strcat(fp,db_name);
        strcat(fp,".ksh");

        f.open(fp,ios::out|ios::app);
        f.close();

        f.open("files/DBKTM.ksh",ios::out|ios::app);
        //  f.open(db_path,ios::out|ios::app);
        strcpy(entry.tbname,sql[2]);
        strcpy(entry.dbname,db_name);
        f.write((char *)&entry,sizeof(entry));
        f.close();





}

void TABLE::disptb()
{
        fstream f;
        if(!f)
        {
                cout<<"ERROR";
        }
        cout<<endl;
        f.open("files/TABLE_STRUCT.h",ios::in);
        while(f.read((char *)&data,sizeof(data)))
        {
                cout<<data.structure<<endl;
        }
        f.close();
}

void TABLE::disp()
{
        cout<<endl<<endl<<"-----------------"<<endl;
        for (size_t i = 0; i < line+1; i++) {
                for (size_t j = 0; j < strlen(tb[i]); j++) {
                        cout<<tb[i][j];
                }
                cout<<endl;
        }
}

bool TABLE::showT()
{

        //    f.open("files/databases/DBRECORD.dat",ios::in);

        f.open(db_path,ios::in);

        if(!f)
        {
                return false;
        }

        cout<<"+-------------------------+";
        cout<<endl;
        cout<<"| Tables_in_";
        cout<<db_name;
        int w1 = 15 - strlen(db_name);
        cout<<setw(w1)<<"|";

        //  cout<<"| DATABASES               |";
        cout<<endl;
        cout<<"+-------------------------+"<<endl;
        int len = 0;

        while(f.read((char*)&entry, sizeof(entry)))
        {
                if(cmp(db_name,entry.dbname))
                {
                        len = strlen(entry.tbname);

                        cout<<"|  "<<entry.tbname;
                        int width = 24-len;

                        cout<<setw(width)<<"|"<<endl;
                }
        }

        cout<<"+-------------------------+";

        f.close();

        return true;
}






#endif
