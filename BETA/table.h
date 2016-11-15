//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef tabledef
#define tabledef

using namespace std;

class TABLE : protected DATABASE
{

char tb[index1][index2];
int line, word;

struct TDATA
{
        //  char table_name[50];
        //char br1[5];
        //char br2[5];
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
                else if(sql[3][i]!= ' ' && sql[3][i-1]== ')')
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
                }
                else if(sql[3][i] == '(' && br == false)
                {
                        br = true;
                }
                else if(sql[3][i] == ')' &&  br == true && i<strlen(sql[3])-1)
                {
                        br = false;

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
        disptb();


}

void TABLE::tblogic()
{
        fstream f;



        strcpy(data.structure,"struct ");
        strcat(data.structure,sql[2]);
        strcat(data.structure,"\n");
        strcat(data.structure,"{");
        strcat(data.structure,"\n");
        strcat(data.structure, "};");
        strcat(data.structure,"\n");
        strcat(data.structure,"\n");


        //  strcat(data.structure,"\0");

        f.open("files/Databases/TABLE_STRUCT.dat",ios::out|ios::app);

        f.write((char *)&data,sizeof(data));
        //  f<<data.structure;

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
        f.open("files/Databases/TABLE_STRUCT.dat",ios::in);
        while(f.read((char *)&data,sizeof(data)))
        //  while(!f.eof())
        {
                //        gets(data.structure);
                cout<<data.structure;
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
