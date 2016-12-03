#include <iostream>
#include <fstream>
#include <windows.h>
#include <typeinfo>




using namespace std;
int main()
{

        /*  fstream f;

           f.open("code.cpp",ios::out);

           char ar[10000];
           strcpy(ar, "#include <iostream>\n#include<fstream>\nusing namespace std;\nint main(){fstream f;f.open(\"KTEMP.ksh\",ios::out);f.close();return 0;}");

           f<<ar;


           f.close();


           system("g++ code.cpp -o code.exe");
           system("code");

           remove("code.cpp");
           remove("code.exe");
         */

        int i;
        char z;
        char ar[2300];
        double d;
        float f;
        cout << typeid(i).name()<<endl;
        cout << typeid(z).name()<<endl;
        cout << typeid(ar).name()<<endl;
        cout << typeid(d).name()<<endl;
        cout << typeid(f).name()<<endl;
        //  strcpy(ar,typeid(i).name());
        //  cout<<ar;

        return 0;
}
