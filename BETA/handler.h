//
// Created by Kushan Mehta on 26-10-2016.
//

#ifndef handlerdefmy
#define handlerdefmy

class HANDLER :  protected DATABASE
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

        if(cmp(mode,"createdb")) // Create Database
        {
                if(isCreateDB())
                {
                        if(addEntrydb()) {

                                if(createFolder()) {
                                        cout << "Database "<<sql[2]<<" created Successfully! ";


                                }
                        } else{

                                cout << "Database "<<sql[2]<<" already exists! ";

                        }
                }
        }


        else if (cmp(mode,"createt")) // Create Table
        {
                if(isCreateT())
                {
                        cout<<"Create table sytax correct";
                }
        }

        else if (cmp(mode,"show")) // Show Databases
        {
                if(isShowDB()) {
                        if(!showDb())
                        {
                                cout<<"No Databases exists.";
                        }
                }

        }

        else if (cmp(mode,"dropdb")) // Drop Database
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
