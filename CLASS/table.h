//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef tabledef
#define tabledef

using namespace std;

class TABLE : protected DATABASE
{

char tb[index1][index2];
char stu[index1][index2];

int line, word;

struct TDATA
{
        char structure[500];
} data;

protected:
void parse_tb();
void disp();
void tblogic();
void disptb();


};

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

        disp();
        tblogic();
        cout<<"********************";
        disptb();


}

void TABLE::tblogic()
{
        fstream f;

        memset(stu, 0, sizeof(stu[0][0]) * index1 * index2);


        strcpy(data.structure,"struct ");
        strcat(data.structure,sql[2]);
        //    strcat(data.structure,"\n");
        strcat(data.structure,"{");
        //  strcat(data.structure,"\n");

        static int l1 =0, w1=0;
        bool brk = false;

        for (int i = 0; i < line+1; i++) {

                //    static char* p[] = new char[][];
                //    static char *head = p;

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

                //  cout<<"&&&&&&&&"<< " "<<w1;
                stu[l1][w1] = '\0';
                //stu[l1+1][0] = '\0';

                if (cmp(stu[1],"varchar")) {

                        strcpy(stu[1],"char");
                        strcat(stu[0],"[");
                        strcat(stu[0],stu[2]);
                        strcat(stu[0],"]");

                }
                else if (cmp(stu[1],"char")) {

                        strcpy(stu[1],"char");
                        //    strcat(stu[0],"[");
                        //    strcat(stu[0],stu[2]);
                        //    strcat(stu[0],"]");

                }

                strcat(data.structure,stu[1]);


                strcat(data.structure," ");
                strcat(data.structure,stu[0]);

                //    strcat(data.structure,tb[i]);
                strcat(data.structure,";");
                //strcat(data.structure,"\n");


        }

        strcat(data.structure, "}");
        strcat(data.structure,sql[2]);
        strcat(data.structure,"1;");

        f.open("files/Databases/TABLE_STRUCT.h",ios::out|ios::app);
        f.write((char *)&data,sizeof(data));
        //f<<data.structure;
        f.close();

        char fp[50];
        strcpy(fp,"files/Databases/");
        strcat(fp,sql[2]);
        strcat(fp,".ksh");

        f.open(fp,ios::out|ios::app);
        f.close();




}

void TABLE::disptb()
{
        fstream f;
        if(!f)
        {
                cout<<"ERROR";
        }
        cout<<endl<<endl;
        f.open("files/Databases/TABLE_STRUCT.h",ios::in);
        while(f.read((char *)&data,sizeof(data)))
        //  while(!f.eof())
        {
                //        gets(data.structure);
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






#endif
