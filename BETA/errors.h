//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef errordef
#define errordef

using namespace std;

class ERRORS : protected IDENTIFY {

protected:

/*
   isCreateDB
   isCreateT
   isShowDB
   isDropDB

 */

bool isCreateDB() {

        bool create = true, data = true, dname = true, dsingle = true;

        if (!cmp(sql[0], "create")) {
                create = false;
        }
        if(!cmp(sql[1], "database"))
        {
                data = false;
        }
        if(sql[2][0]=='\0' || sql[2][0]==' ')
        {
                dname = false;
        }
        if(sql[3][0] != '\0')
        {
                dsingle = false;
        }

        if(create == true & data == true && dname == true && dsingle == true)
        {
                return true;
        }

        else {


                if(dname == false)
                {
                        cout<<"ERROR: Please specify a allowed name for database";
                }
                else if(dsingle == false)
                {
                        cout<<"ERROR: The database name can contain a single word only";
                }
                else
                {
                        cout<<"ERROR: The correct syntax should be \" Create Database <DBName> \" ";
                }

                return false;

        }
}

bool isCreateT() {

        bool create = true, table = true, tname = true;

        if (!cmp(sql[0], "create")) {
                create = false;
        }
        if(!cmp(sql[1], "table"))
        {
                table = false;
        }
        if(sql[2][0]=='\0' || sql[2][0]==' ')
        {
                tname = false;
        }


        if(create == true & table == true && tname == true)
        {
                return true;
        }

        else {

                if(tname == false)
                {
                        cout<<"ERROR: Please specify a allowed name for table";
                }

                else
                {
                        cout<<"ERROR: The correct syntax should be \" Create table <TableName> (Parameters) \" ";
                }

                return false;

        }
}


bool isShowDB() {

        bool show = true, data = true, extra = true;
        if (!cmp(sql[0], "show")) {
                show = false;
        }
        if(!cmp(sql[1], "databases"))
        {
                data = false;
        }
        if(sql[2][0] != '\0')
        {
                extra = false;
        }

        if(show = true && data == true && extra == true)
        {
                return true;
        }

        else {

                if(extra == false)
                {
                        cout<<"ERROR: Unecessary syntax present. The correct syntax should be \" Show Databases \" ";
                }
                else
                {
                        cout<<"ERROR: The correct syntax should be \" Show Databases \" ";
                }

                return false;

        }
}

bool isDropDB() {

        bool drop = true, data = true, dname = true, dsingle = true;

        if (!cmp(sql[0], "drop")) {
                drop = false;
        }
        if(!cmp(sql[1], "database"))
        {
                data = false;
        }
        if(sql[2][0]=='\0' || sql[2][0]==' ')
        {
                dname = false;
        }
        if(sql[3][0] != '\0')
        {
                dsingle = false;
        }

        if(drop == true & data == true && dname == true && dsingle == true)
        {
                return true;
        }

        else {

                if(dname == false)
                {
                        cout<<"ERROR: Please specify a allowed name for database";
                }
                else if(dsingle == false)
                {
                        cout<<"ERROR: The database name can contain a single word only";
                }
                else
                {
                        cout<<"ERROR: The correct syntax should be \" Drop Database <DBName> \" ";
                }


                return false;

        }
}
};


#endif // errordef
