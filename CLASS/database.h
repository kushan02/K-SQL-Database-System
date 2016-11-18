//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef databasedef
#define databasedef

using namespace std;

class DATABASE : protected ERRORS
{
protected:
char db_name[50];

char folder_path[100], file_path[100], open_path[100];
fstream f;

public:

DATABASE()
{
        strcpy(folder_path,"\\files\\databases\\");
        strcpy(file_path,"\\files\\databases\\DBRECORD.ksh");
        //  strcpy(path,(char *) getFolderDir().c_str());
        strcpy(open_path,"files/databases/DBRECORD.ksh");
        //    strcat(path, folder_path );
}

private:

string getFolderDir() {
        char buffer[MAX_PATH];
        GetModuleFileName( NULL, buffer, MAX_PATH );
        string::size_type pos = string( buffer ).find_last_of( "\\/" );
        return string( buffer ).substr( 0, pos);
}

string getfilepath()
{
        char result[ MAX_PATH ];
        return string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
}

struct dbEntry
{
        char dbName[50];
} obj;

protected:

bool useDB()
{

}


bool createFolder()
{

        //GET THE PATH OF EXE
        char path[100];
        strcpy(path,(char *) getFolderDir().c_str());

        strcat(path, folder_path );

        strcat(path, sql[2]);

        if(!CreateDirectory(path,NULL))
        {
                return false;
        }
        else {
                return true;
        }
}




bool addEntrydb()
{

        char path[100];

        strcpy(path,(char *) getFolderDir().c_str());

        strcat(path, file_path );

        f.open(path,ios::in);
        while(f.read( (char *)&obj,sizeof(obj) ) )
        {
                if(cmp(obj.dbName,sql[2]))
                {
                        f.close();
                        return false;
                }
        }

        f.close();


        f.open(path,ios::out|ios::app);

        strcpy(obj.dbName,sql[2]);
        if(!f.write( (char *)&obj, sizeof(obj)))
        {
                f.close();
                return false;
        }

        f.close();
        return true;

}

bool showDb()
{

        //    f.open("files/databases/DBRECORD.dat",ios::in);

        f.open(open_path,ios::in);

        if(!f)
        {
                return false;
        }

        cout<<"+-------------------------+";
        cout<<endl;
        cout<<"| DATABASES               |";
        cout<<endl;
        cout<<"+-------------------------+"<<endl;

        while(f.read((char*)&obj, sizeof(obj)))
        {

                int len = strlen(obj.dbName);

                cout<<"|  "<<obj.dbName;
                int width = 24-len;

                cout<<setw(width)<<"|"<<endl;
        }

        cout<<"+-------------------------+";

        f.close();

        return true;
}


bool dropDB()
{

        fstream o;
        //    f.open("files/databases/DBRECORD.dat",ios::in);
        f.open(open_path,ios::in);
        o.open("files/databases/temp.dat",ios::out);

        if(!f)
        {
                return false;
        }

        bool found=false;

        char del[100];
        strcpy(del,"rmdir /Q /S ");
        strcat(del,(char *) getFolderDir().c_str());
        strcat(del,folder_path);
        strcat(del,sql[2]);

        while(f.read((char*)&obj, sizeof(obj)))
        {

                if(cmp(obj.dbName,sql[2]))
                {
                        found = true;

                        system(del);

                        continue;
                }

                o.write( (char *)&obj, sizeof(obj));

        }
        f.close();
        o.close();

        //  remove("files/databases/DBRECORD.dat");
        //  rename("files/databases/temp.dat","files/databases/DBRECORD.dat");


        remove(open_path);
        rename("files/databases/temp.dat",open_path);


        if(found==true)
        {
                return true;
        }
        else
        {
                return false;
        }

}

};


#endif
