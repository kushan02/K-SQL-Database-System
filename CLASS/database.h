//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef databasedef
#define databasedef

using namespace std;

class DATABASE
{

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


bool createFolder(const char * fname)
{

        //GET THE PATH OF EXE
        char path[100];
        strcpy(path,(char *) getFolderDir().c_str());

        strcat(path, "\\files\\databases\\" );

        strcat(path, fname);

        // cout<<path<<endl;


        if(!CreateDirectory(path,NULL))
        {
                return false;
        }
        else {
                return true;
        }
}


struct dbEntry
{
        char dbName[50];
};

bool addEntrydb()
{

        fstream f;

        char path[100];
        strcpy(path,(char *) getFolderDir().c_str());

        strcat(path, "\\files\\databases\\DBRECORD.DAT" );


        f.open(path,ios::out|ios::app);

        dbEntry obj;
        strcpy(obj.dbName,ename);
        if(!f.write( (char *)&obj, sizeof(obj)))
        {
                f.close();
                return false;
        }

        f.close();
        return true;

}


protected:

bool showDb()
{
        fstream f;


        f.open("files/databases/DBRECORD.dat",ios::in);

        if(!f)
        {
                return false;
        }


        dbEntry obj;

        cout<<endl<<"+-------------------------+";
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
        cout<<endl;

        f.close();
        delete(f);

        return true;
}


bool dropDB()
{
        // TODO: Delete the folder also


        fstream f,o;
        f.open("files/databases/DBRECORD.dat",ios::in);
        o.open("files/databases/temp.dat",ios::out);

        if(!f)
        {
                return false;
        }


        dbEntry obj;

        bool found=false;

        while(f.read((char*)&obj, sizeof(obj)))
        {

                if(cmp(obj.dbName,name))
                {
                        found = true;
                        continue;
                }

                o.write( (char *)&obj, sizeof(obj));

        }
        f.close();
        o.close();

        delete(f);
        delete(o);

        remove("files/databases/DBRECORD.dat");
        rename("files/databases/temp.dat","files/databases/DBRECORD.dat");


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
