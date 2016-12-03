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
   isUseDB
   isInsertT

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

        if(create == true && data == true && dname == true && dsingle == true)
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

        bool create = true, table = true, tname = true, par = true;

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
        if(!(strlen(sql[3])>0))
        {
                par = false;
        }


        if(create == true && table == true && tname == true && par == true)
        {
                return true;
        }

        else {

                if(tname == false)
                {
                        cout<<"ERROR: Please specify a allowed name for table";
                }

                else if(par == false)
                {
                        cout<<"ERROR: No parameters for fields to create for the table supplied.";
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

        if(show == true && data == true && extra == true)
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

bool isShowT() {

        bool show = true, data = true, extra = true;
        if (!cmp(sql[0], "show")) {
                show = false;
        }
        if(!cmp(sql[1], "tables"))
        {
                data = false;
        }
        if(sql[2][0] != '\0')
        {
                extra = false;
        }

        if(show == true && data == true && extra == true)
        {
                return true;
        }

        else {

                if(extra == false)
                {
                        cout<<"ERROR: Unecessary syntax present. The correct syntax should be \" Show Tables \" ";
                }
                else
                {
                        cout<<"ERROR: The correct syntax should be \" Show Tables \" ";
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

        if(drop == true && data == true && dname == true && dsingle == true)
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

bool isUseDB() {

        bool use = true, nm = true, extra = true;
        if (!cmp(sql[0], "use")) {
                use = false;
        }
        if(sql[2][0] != '\0')
        {
                extra = false;
        }
        if(!(sql[1][0] != '\0'))
        {
                nm = false;
        }

        if(use == true && nm == true && extra == true)
        {
                return true;
        }

        else {

                if(extra == false)
                {
                        cout<<"ERROR: Unecessary syntax present. The correct syntax should be \" Use DatabaseName \" ";
                }
                else
                {
                        cout<<"ERROR: The correct syntax should be \" Use DatabaseName \" ";
                }

                return false;

        }
}

bool isInsertT() {

        bool insert = true, into = true, values = true, tname = true, par1 = true, par2 = true;

        if (!cmp(sql[0], "insert")) {
                insert = false;
        }
        if(!cmp(sql[1], "into"))
        {
                into = false;
        }
        if(!cmp(sql[4], "values"))
        {
                into = false;
        }
        if(sql[2][0]=='\0' || sql[2][0]==' ')
        {
                tname = false;
        }
        if(sql[3][0]!='(')
        {
                par1 = false;
        }
        if(sql[5][0]!='(')
        {
                par2 = false;
        }


        if(insert == true && into == true && tname == true && values == true && par1 == true && par2 == true)
        {
                return true;
        }

        else {

                if(tname == false)
                {
                        cout<<"ERROR: Please specify a allowed name for table";
                }

                else if(par1 == false)
                {
                        cout<<"ERROR: No parameters for fields to insert data into supplied.";
                }
                else if(par2 == false)
                {
                        cout<<"ERROR: No values to insert data supplied.";
                }

                else
                {
                        cout<<"ERROR: The correct syntax should be \" INSERT INTO table_name (column1,column2,column3,...) VALUES (value1,value2,value3,...); \" ";
                }

                return false;

        }
}


};


#endif // errordef
