#include <iostream>
#include <fstream>
#include <windows.h>



using namespace std;
int main()
{

        fstream f;

        f.open("code.cpp",ios::out);

        char ar[10000];
        strcpy(ar, "#include <iostream>\n#include<fstream>\nusing namespace std;\nint main(){fstream f;f.open(\"KTEMP.ksh\",ios::out);f.close();return 0;}");

        f<<ar;


        f.close();


        system("g++ code.cpp -o code.exe");
        system("code");

        remove("code.cpp");
        remove("code.exe");



        return 0;
}
