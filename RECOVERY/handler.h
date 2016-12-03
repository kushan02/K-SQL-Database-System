//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef handlerdefmy
#define handlerdefmy

class HANDLER :  protected INSERT
{
protected:

void handler()
{
        handlerlogic();
}

private:

void handlerlogic()
{
        cout<<endl<<endl;

        // TODO: Develop Tables

        if(cmp(mode,"createdb"))         // Create Database
        {
                if(isCreateDB())
                {
                        if(addEntrydb()) {

                                //      if(createFolder()) {
                                cout << "Database "<<sql[2]<<" created Successfully! ";


                                //    }
                        } else{

                                cout << "Database "<<sql[2]<<" already exists! ";

                        }
                }
        }


        else if (cmp(mode,"createt"))         // Create Table
        {
                if(tUse())
                {
                        if(isCreateT())
                        {
                                //  cout<<"Create table sytax correct";
                                if(table())
                                {
                                        //    parse_tb();
                                        cout<<"Table "<<sql[2]<<" created!";
                                }
                                else
                                {
                                        cout<<"Table "<<sql[2]<<" already exists!";
                                }
                        }

                }
                else
                {
                        cout<<"No database in use";
                }
        }

        else if (cmp(mode,"showdb"))         // Show Databases
        {
                if(isShowDB()) {
                        if(!showDb())
                        {
                                cout<<"No Databases exists.";
                        }
                }

        }

        else if (cmp(mode,"showt"))         // Show Databases
        {
                if(tUse())
                {
                        if(isShowT()) {
                                if(!showT())
                                {
                                        cout<<"No Tables exists";
                                }
                        }
                }
                else
                {
                        cout<<"No database in use";
                }

        }

        else if (cmp(mode,"dropdb"))         // Drop Database
        {
                if(isDropDB()) {
                        if(dropDB())
                        {
                                cout<< "Database " << sql[2] <<" deleted Successfully!";
                        }
                        else
                        {
                                cout<< "Database " << sql[2] << " does not exist. Please select a existing database.";
                        }
                }
        }
        else if (cmp(mode,"use"))         // Use Database
        {
                if(useDB())
                {
                        cout<<"Database "<<sql[1]<<" in use.";
                }

        }
        else if (cmp(mode,"insert"))         // Insert into Table
        {
                if(tUse())
                {
                        if(isInsertT())
                        {
                                insert();
                        }
                }
                else
                {
                        cout<<"No database in use";
                }
        }


        else if(cmp(mode,"exit"))
        {
                cout<<"Bye"<<endl;
                exit(0);
        }

        else
        {
                cout<<"Please Enter a valid KSQL Command.";
        }
        cout<<endl;

}


};

#endif
